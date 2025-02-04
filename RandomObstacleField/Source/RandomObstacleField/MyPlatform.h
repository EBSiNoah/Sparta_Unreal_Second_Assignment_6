// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "TimerManager.h"
#include "MyPlatform.generated.h"

UCLASS()
class RANDOMOBSTACLEFIELD_API AMyPlatform : public AActor
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Status")
	UStaticMeshComponent* floorMeshComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Status")
	FVector meshScale;
	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;
	FTimerHandle timerHandle;
public:	
	// Sets default values for this actor's properties
	AMyPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	void ModifyMeshScale();
	virtual void StatusInit();
};
