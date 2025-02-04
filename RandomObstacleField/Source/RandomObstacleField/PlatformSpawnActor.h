// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformSpawnActor.generated.h"

UCLASS()
class RANDOMOBSTACLEFIELD_API APlatformSpawnActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatformSpawnActor();	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	TSubclassOf<AActor> BP_RotatePlatform;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawner")
	TSubclassOf<AActor> BP_MovePlatform;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void SpawnPlatform();
};
