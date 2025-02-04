// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformSpawnActor.h"
#include "RotatePlatform.h"
#include "MovePlatform.h"

// Sets default values
APlatformSpawnActor::APlatformSpawnActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlatformSpawnActor::BeginPlay()
{
	Super::BeginPlay();
	SpawnPlatform();
}

// Called every frame
void APlatformSpawnActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlatformSpawnActor::SpawnPlatform()
{
	if (BP_RotatePlatform)
	{
		UE_LOG(LogTemp, Warning, TEXT("work?"));

		AActor* rotatePlatform = GetWorld()->SpawnActor<AActor>(BP_RotatePlatform);
		
		if (rotatePlatform)
		{
			UE_LOG(LogTemp, Warning, TEXT("spawn"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("nope"));
		}
	}
	if (BP_MovePlatform)
	{
		UE_LOG(LogTemp, Warning, TEXT("move platform"));

		AActor* movePlatform = GetWorld()->SpawnActor<AActor>(BP_MovePlatform);

		if (movePlatform)
		{
			UE_LOG(LogTemp, Warning, TEXT("spawn mp"));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("nope mp"));
		}
	}
}