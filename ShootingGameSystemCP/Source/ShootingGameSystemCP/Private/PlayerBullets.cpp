// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerBullets.h"
#include "GameFramework/ProjectileMovementComponent.h"  //�ǉ�
#include "Kismet/GameplayStatics.h" //�ǉ��w�b�_
#include "Particles/Particlesystem.h" //�p�[�e�B�N������̈גǉ�

// Sets default values
APlayerBullets::APlayerBullets()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//bullet�R���|�[�l���g�̏����ݒ�
	bullet = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMesh"));

	bullet->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.1f));

	bullet->BodyInstance.SetCollisionProfileName("Projectile");

	bullet->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Block);

	//Component Hit �C�x���g�ŃR�[������֐��̓o�^(OnHit�֐�)
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

	//Projectile�̏����ݒ�
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = bullet;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	//Physics�����ɂ�����e�ۂ̎��ʂ̒�`
	bullet->SetMassOverrideInKg("", 10000.0f, true);

	//3�b�ŏ���
	this->InitialLifeSpan = 3.0f;

	//�����p�[�e�B�N���̏����ݒ�
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

		//�Փˑ���Ƀ_���[�W��^����
		float DamageAmount = 25.0f;
		FDamageEvent de; //����̓R���X�g���N�^�����l����ς��Ȃ����A�K�v�ɉ����ă_���[�W��ނ��w��
		AController* EventInstigator = nullptr; //�����Player Controller�̎w��Ȃ�
		AActor* DamageCauser = this; //�_���[�W�v���Ƃ��Ď��g(�e��)���w��
		OtherActor->TakeDamage(DamageAmount, de, EventInstigator, DamageCauser);

		//����𐁂���΂�
		OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());

		FVector Location = GetActorTransform().GetLocation();
		FRotator Rotation = GetActorTransform().GetRotation().Rotator();
		FVector Scale = FVector(1.0f);
		//�q�b�g�G�t�F�N�g�Ƃ��Ĕ����p�[�e�B�N�����X�|�[��
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ExplosionParticle, FTransform(Rotation, Location, Scale));
		//�e�ۂ̏���
		Destroy();
	}

}

