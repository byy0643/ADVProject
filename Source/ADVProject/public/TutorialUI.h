// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TutorialUI.generated.h"

UCLASS()
class ADVPROJECT_API ATutorialUI : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATutorialUI();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

public:
	UPROPERTY(VisibleAnywhere, Category=Collision)
	class UBoxComponent* colliComp;

	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess = "true"))
	class UWidgetComponent* widgetComp;

	UPROPERTY(EditAnywhere)
	USceneComponent* DefaultRoot = nullptr;
	
};
