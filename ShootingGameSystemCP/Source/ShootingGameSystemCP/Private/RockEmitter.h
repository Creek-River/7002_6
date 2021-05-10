// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RockEmitter.generated.h"

UCLASS()
class ARockEmitter : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARockEmitter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	TSubclassOf<class AStaticMeshActor> rockActor = nullptr;
	void SpawnRock(); //���������Ȋ֐��ׁ̈AUCLASS�}�N���͎g��Ȃ�
	FTimerHandle timerHandle; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Emitter Properties")
		float delayTime = 1.5f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	//�_���[�W��M
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

	float HP = 20.0f;
};
