// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBox.h"

#include "Bullet.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"
#include "ItemBoxWidget.h"

// Sets default values
AItemBox::AItemBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	SetRootComponent(boxComp);
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	meshComp->SetupAttachment(RootComponent);

	widgetComp = CreateDefaultSubobject<UWidgetComponent>(TEXT("widgetComp"));
	widgetComp->SetupAttachment(RootComponent);
	widgetComp->SetWidgetSpace(EWidgetSpace::Screen);
	ConstructorHelpers::FClassFinder<UUserWidget> hpWidget(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/ThirdPerson/Blueprints/WBP_ItemBox.WBP_ItemBox_C'"));
	if(hpWidget.Succeeded())
	{
		widgetComp->SetWidgetClass(hpWidget.Class);
	}
}

// Called when the game starts or when spawned
void AItemBox::BeginPlay()
{
	Super::BeginPlay();

	boxComp->OnComponentBeginOverlap.AddDynamic(this, &AItemBox::OnOverlap);
	hp = maxHP;
	UE_LOG(LogTemp, Warning, TEXT("boxHP : %d"),hp)
	boxWidget = Cast<UItemBoxWidget>(widgetComp->GetWidget());
	if (boxWidget)
	{
		UE_LOG(LogTemp, Warning, TEXT("boxWidget Casted"))
		boxWidget->ShowHPBar(hp, maxHP);
	}
}

// Called every frame
void AItemBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItemBox::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	bullet = Cast<ABullet>(OtherActor);
	UE_LOG(LogTemp, Warning, TEXT("OnOverlap : %s"), *OtherActor->GetName())
	if(bullet)
	{		
		TakeHP(bullet->attkScore);
		UE_LOG(LogTemp, Warning, TEXT("box hp : %d"), maxHP)
		boxWidget->ShowHPBar(hp, maxHP);
		DamageProcess();
	}
}

void AItemBox::DamageProcess()
{
	if(!boxWidget) return;

	UE_LOG(LogTemp, Warning, TEXT("On Widget HP = %d"), maxHP)
}

