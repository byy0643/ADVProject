// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IInteractItems.h"
#include "NoticeBoard.generated.h"

UCLASS()
class ADVPROJECT_API ANoticeBoard : public AActor, public IIInteractItems
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANoticeBoard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(VisibleAnywhere, Category = Collision)
	class UBoxComponent* colliComp;

	UPROPERTY(VisibleAnywhere, Category = BodyMesh)
	class UStaticMeshComponent* bodyComp;

	UPROPERTY(EditDefaultsOnly, Category = noticeBoardUI)
	TSubclassOf<class UUserWidget> noticeBoardUIFactory;

	class UUserWidget* _noticeBoardUI;

	void Reaction() override;

	/*UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* otherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);*/
};
