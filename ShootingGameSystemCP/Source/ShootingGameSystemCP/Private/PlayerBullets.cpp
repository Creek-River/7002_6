// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBullets.h"
#include "GameFramework/ProjectileMovementComponent.h"  //追加
#include "Kismet/GameplayStatics.h" //追加ヘッダ
#include "Particles/Particlesystem.h" //パーティクル制御の為追加

// Sets default values
APlayerBullets::APlayerBullets()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//bulletコンポーネントの初期設定
	bullet = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMesh"));

	bullet->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.1f));

	bullet->BodyInstance.SetCollisionProfileName("Projectile");

	bullet->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);

	//Component Hit イベントでコールする関数の登録(OnHit関数)
	bullet->OnComponentHit.AddDynamic(this, &APlayerBullets::OnHit);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> BulletStaticMesh(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	if (BulletStaticMesh.Object != NULL)
	{
		bullet->SetStaticMesh(BulletStaticMesh.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterialInstance> BulletMatAsset(TEXT("MaterialInstanceConstant'/Game/ShootingSystem/playerBulletA_m.playerBulletA_m'"));
	if (BulletMatAsset.Object != NULL)
	{
		bullet->SetMaterial(0, BulletMatAsset.Object);
	}

	RootComponent = bullet;

	//Projectileの初期設定
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = bullet;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	//Physics処理における弾丸の質量の定義
	bullet->SetMassOverrideInKg("", 10000.0f, true);

	//3秒で消滅
	this->InitialLifeSpan = 3.0f;

	//爆発パーティクルの初期設定
	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("ParticleSystem'/Game/Particles/P_Explosion.P_Explosion'"));
	if (ParticleAsset.Object != NULL) {
		ExplosionParticle = ParticleAsset.Object;
	}
}

// Called when the game starts or when spawned
void APlayerBullets::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerBullets::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerBullets::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& hit)
{
	UE_LOG(LogTemp, Display, TEXT("Check OnHit"));

	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		UE_LOG(LogTemp, Display, TEXT("Check OnHitIF"));

		//衝突相手にダメージを与える
		float DamageAmount = 25.0f;
		FDamageEvent de; //今回はコンストラクタ初期値から変わらないが、必要に応じてダメージ種類を指定
		AController* EventInstigator = nullptr; //今回はPlayer Controllerの指定なし
		AActor* DamageCauser = this; //ダメージ要因として自身(弾丸)を指定
		OtherActor->TakeDamage(DamageAmount, de, EventInstigator, DamageCauser);

		//相手を吹っ飛ばす
		OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());

		FVector Location = GetActorTransform().GetLocation();
		FRotator Rotation = GetActorTransform().GetRotation().Rotator();
		FVector Scale = FVector(1.0f);
		//ヒットエフェクトとして爆発パーティクルをスポーン
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionParticle, FTransform(Rotation, Location, Scale));
		//弾丸の消滅
		Destroy();
	}

}

