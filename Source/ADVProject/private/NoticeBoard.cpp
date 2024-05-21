// Fill out your copyright notice in the Description page of Project Settings.


#include "NoticeBoard.h"
#include "UMG.h"
#include <Components/BoxComponent.h>
#include <Blueprint/UserWidget.h>
#include <Kismet/GameplayStatics.h>

// Sets default values
ANoticeBoard::ANoticeBoard()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	colliComp = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionComp"));
	/*colliComp->OnComponentBeginOverlap.AddDynamic(this, &ANoticeBoard::OnBeginOverlap);*/
	colliComp->SetCollisionProfileName(TEXT("InteractOnlyPawn"));

	bodyComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BodyMeshComp"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> tempMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cube'"));
	if (tempMesh.Succeeded()) {
		bodyComp->SetStaticMesh(tempMesh.Object);
		bodyComp->SetRelativeScale3D(FVector(0.01, 1.0, 1.0));
	}
	bodyComp->SetupAttachment(colliComp);

	bodyComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void ANoticeBoard::BeginPlay()
{
	Super::BeginPlay();
	_noticeBoardUI = CreateWidget(GetWorld(), noticeBoardUIFactory);

}

// Called every frame
void ANoticeBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void ANoticeBoard::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* otherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
//	UE_LOG(LogTemp, Log, TEXT("overlapped"));
//	APlayerController* control = UGameplayStatics::GetPlayerController(GetWorld(), 0);
//	_noticeBoardUI->AddToViewport();
//	control->bShowMouseCursor = true;
//}

void ANoticeBoard::Reaction() {
	UE_LOG(LogTemp, Log, TEXT("overlapped"));
	APlayerController* control = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	_noticeBoardUI->AddToViewport();
	control->bShowMouseCursor = true;
}

