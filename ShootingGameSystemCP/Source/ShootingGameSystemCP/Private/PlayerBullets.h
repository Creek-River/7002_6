// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerBullets.generated.h"

UCLASS()
class APlayerBullets : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerBullets();

	//弾丸メッシュ
	UPROPERTY(VisibleDefaultsOnly, Category = "Shooting")
		class UStaticMeshComponent* bullet;

	//Projectile(発射する)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Shooting")
		class UProjectileMovementComponent* ProjectileMovement;

	UPROPERTY(VisibleDefaultsOnly, Category = "Shooting")
		class UParticleSystem* ExplosionParticle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//ヒットイベント
	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

};
