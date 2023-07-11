// Fill out your copyright notice in the Description page of Project Settings.


#include "Bullet.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABullet::ABullet()
{
	PrimaryActorTick.bCanEverTick = true;

	sphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("sphereComp"));
	SetRootComponent(sphereComp);
	sphereComp->SetCollisionProfileName(TEXT("BulletPreset"));

	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	meshComp->SetupAttachment(RootComponent);
	meshComp->SetRelativeScale3D(FVector(0.3f));
	meshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	moveComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("moveComp"));
	moveComp->SetUpdatedComponent(sphereComp);
	moveComp->InitialSpeed = 5000;
	moveComp->MaxSpeed = 5000;
	moveComp->bShouldBounce = true;
	moveComp->Bounciness = 0.3f;
}

// Called when the game starts or when spawned
void ABullet::BeginPlay()
{
	Super::BeginPlay();


	FTimerHandle bulletTimer;
	GetWorld()->GetTimerManager().SetTimer(bulletTimer, this, &ABullet::DistroyMySelf, 2.f);
}

// Called every frame
void ABullet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABullet::DistroyMySelf()
{
	Destroy();
}

