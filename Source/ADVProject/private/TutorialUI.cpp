// Fill out your copyright notice in the Description page of Project Settings.


#include "TutorialUI.h"
#include <Components/BoxComponent.h>
#include <Components/WidgetComponent.h>
#include <Kismet/GameplayStatics.h>

// Sets default values
ATutorialUI::ATutorialUI()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DefaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultRoot"));
	SetRootComponent(DefaultRoot);

	colliComp = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComp"));
	colliComp->SetCollisionProfileName(TEXT("OverlapOnlyPawn"));
	colliComp->SetupAttachment(DefaultRoot);

	widgetComp = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComp"));
	//RootComponent->SetupAttachment(widgetComp);
	widgetComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	widgetComp->SetupAttachment(DefaultRoot);
}

// Called when the game starts or when spawned
void ATutorialUI::BeginPlay()
{
	Super::BeginPlay();
	widgetComp->SetVisibility(false);
}

// Called every frame
void ATutorialUI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATutorialUI::NotifyActorBeginOverlap(AActor* OtherActor) {
	APawn* player = Cast<APawn>(OtherActor);
	UE_LOG(LogTemp, Log, TEXT("Overlapped"));
	if (player != nullptr) {
		UE_LOG(LogTemp, Log, TEXT("its pawn"));
		widgetComp->SetVisibility(true);
		colliComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}