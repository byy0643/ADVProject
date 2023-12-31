// Fill out your copyright notice in the Description page of Project Settings.


#include "Lever.h"
#include <Components/BoxComponent.h>

// Sets default values
ALever::ALever()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	colliComp = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComp"));
	colliComp->SetCollisionProfileName(TEXT("BlockOnlyDynamic"));
}

// Called when the game starts or when spawned
void ALever::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALever::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ALever::NotifyActorBeginOverlap(AActor* OtherActor)
{
	SetActorRelativeRotation(FRotator(0, 90, 45));
	isTriggered = true;
}
