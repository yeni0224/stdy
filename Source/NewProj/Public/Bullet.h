// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"

UCLASS()
class NEWPROJ_API ABullet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABullet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly, Category="Bullet Settings")
	class USphereComponent* sphereComp;
	UPROPERTY(EditDefaultsOnly, Category="Bullet Settings")
	class UStaticMeshComponent* meshComp;	
	UPROPERTY(EditAnywhere, Category= "Bullet Settings")
	class UProjectileMovementComponent* moveComp;

	void DestroyMySelf();

	int32 attkScore = 5;
};
