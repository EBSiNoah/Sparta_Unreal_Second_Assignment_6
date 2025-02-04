// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatePlatform.h"

ARotatePlatform::ARotatePlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	
	//StatusInit();
}

ARotatePlatform::ARotatePlatform(const FObjectInitializer& ObjectInitializer, const float inputSpeed)
{
	rotateSpeed = inputSpeed;
}

void ARotatePlatform::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &ARotatePlatform::StatusInit, 5.0f, true);
}

void ARotatePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(axis * rotateSpeed * DeltaTime);
}

void ARotatePlatform::SetSpeed(const float& inputSpeed)
{
	if (rotateSpeed != inputSpeed)
	{
		rotateSpeed = inputSpeed;
	}
}

float ARotatePlatform::GetSpeed()
{
	return rotateSpeed;
}

void ARotatePlatform::SetAxis(const FRotator& inputAxis)
{
	if (axis != inputAxis)
	{
		axis = inputAxis;
	}
}

FRotator ARotatePlatform::GetAxis()
{
	return axis;
}

void ARotatePlatform::StatusInit()
{
	Super::StatusInit();
	rotateSpeed = FMath::RandRange(50, 200);
	axis = FRotator(FMath::RandRange(0, 1), FMath::RandRange(0, 1), FMath::RandRange(0, 1));
	FVector initPos(FMath::RandRange(0, 1000), FMath::RandRange(0, 1000), FMath::RandRange(500, 700));

	SetActorLocation(initPos);
}