// Fill out your copyright notice in the Description page of Project Settings.


#include "RockEmitter.h"
#include "Runtime/Engine/Classes/Engine/StaticMeshActor.h" 
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "PlayerBullets.h" //�ǉ�



// Sets default values
ARockEmitter::ARockEmitter()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FClassFinder<AStaticMeshActor> smActor(TEXT("/Game/DungeonExplorer/GraphicAssets/BP_rock.BP_rock_C")); //�p�X���ǂݍ��ނ��߂̂��܂��Ȃ�
	rockActor = smActor.Class;

}

// Called when the game starts or when spawned
void ARockEmitter::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &ARockEmitter::SpawnRock, delayTime, true);
	
}

// Called every frame
void ARockEmitter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARockEmitter::SpawnRock()
{
	FActorSpawnParameters params;

	//�o���ʒu�̃Y���E�p�x�Y�����������_���l�ŎZ�o
	FVector pos = FVector(FMath::RandRange(-1500, 1000), FMath::RandRange(-1500, 1500), FMath::RandRange(0.0f, 0.4f));
	FRotator rot = FRotator(FMath::RandRange(-180, 180), FMath::RandRange(-180, 180), FMath::RandRange(-180, 180));

	//�Z�o�l�����ƂɊ���X�|�[��������
	GetWorld()->SpawnActor<AStaticMeshActor>(rockActor, GetActorLocation() + pos, GetActorRotation() + rot, params);

	//�ċA�I�Ɏ��g���Ăяo���ׂ��^�C�}�[�Z�b�g����
	GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &ARockEmitter::SpawnRock, delayTime, true);
}

//�_���[�W��M
float  ARockEmitter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	UE_LOG(LogTemp, Display, TEXT("Rock Damage Simulation"));
	UE_LOG(LogTemp, Display, TEXT("Damege : %f"), DamageAmount);
	HP = HP - DamageAmount;
	UE_LOG(LogTemp, Display, TEXT("Roclk's HP Now : %f"), HP);
	if (HP <= 0.0f) {
		Destroy();
	}
	return DamageAmount;
}

