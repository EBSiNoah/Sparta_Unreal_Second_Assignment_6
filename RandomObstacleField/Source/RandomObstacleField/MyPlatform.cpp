// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlatform.h"

// Sets default values
AMyPlatform::AMyPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	floorMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Floor"));
	floorMeshComponent->SetupAttachment(RootComponent);
	//StatusInit();
	//GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &AMyPlatform::StatusInit, 5.0f, true);
}

// Called when the game starts or when spawned
void AMyPlatform::BeginPlay()
{
	Super::BeginPlay();
	if (floorMeshComponent)
	{
		floorMeshComponent->SetWorldScale3D(meshScale);
	}
	GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &AMyPlatform::StatusInit, 5.0f, true);
}

// Called every frame
void AMyPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ModifyMeshScale();
}

void AMyPlatform::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.Property && PropertyChangedEvent.Property->GetFName() == FName("meshScale"))
	{
		if (floorMeshComponent)
		{
			floorMeshComponent->SetWorldScale3D(meshScale);
		}
	}
}

void AMyPlatform::ModifyMeshScale()
{
	if (floorMeshComponent && meshScale != floorMeshComponent->GetComponentScale())
	{
		floorMeshComponent->SetWorldScale3D(meshScale);
	}
}

void AMyPlatform::StatusInit()
{
	meshScale = FVector(FMath::RandRange(1, 5), FMath::RandRange(1, 5), FMath::RandRange(1, 5));
	floorMeshComponent->SetWorldScale3D(meshScale);
	//StatusInitTimer();
}