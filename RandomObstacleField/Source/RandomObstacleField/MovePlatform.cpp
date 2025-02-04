// Fill out your copyright notice in the Description page of Project Settings.


#include "MovePlatform.h"

AMovePlatform::AMovePlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	
	//StatusInit();
}

void AMovePlatform::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &AMovePlatform::StatusInit, 5.0f, true);
}

void AMovePlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	currentPos += direction * moveSpeed * DeltaTime;

	SetActorLocation(currentPos);

	ChangeDirection();
}

void AMovePlatform::SetSpeed(const float& inputSpeed)
{
	if (moveSpeed != inputSpeed)
	{
		moveSpeed = inputSpeed;
	}
}

float AMovePlatform::GetSpeed()
{
	return moveSpeed;
}

void AMovePlatform::SetDirection(const FVector& inputDirection)
{
	if (direction != inputDirection)
	{
		direction = inputDirection;
		direction.Normalize();
	}
}

FVector AMovePlatform::GetDirection()
{
	return direction;
}

void AMovePlatform::SetInitPos(const FVector& inputPos)
{
	if (initPos != inputPos)
	{
		initPos = inputPos;
	}
}

FVector AMovePlatform::GetInitPos()
{
	return initPos;
}

void AMovePlatform::SetCurrentPos(const FVector& inputPos)
{
	if (currentPos != inputPos)
	{
		currentPos = inputPos;
	}
}

FVector AMovePlatform::GetCurrentPos()
{
	return currentPos;
}

void AMovePlatform::SetMoveDistance(const float& inputDistance)
{
	if (moveDistance != inputDistance)
	{
		moveDistance = inputDistance;
	}
}

float AMovePlatform::GetMoveDistance()
{
	return moveDistance;
}

void AMovePlatform::ChangeDirection()
{
	float compare = FVector::Dist(initPos, currentPos);
	if (compare > moveDistance)
	{
		direction *= -1;
	}
}

void AMovePlatform::StatusInit()
{
	Super::StatusInit();

	moveSpeed = FMath::RandRange(50, 200);
	direction = FVector(FMath::RandRange(0, 1), FMath::RandRange(0, 1), FMath::RandRange(0, 1));
	initPos = FVector(FMath::RandRange(1000, 2000), FMath::RandRange(1000, 2000), FMath::RandRange(500, 700));
	moveDistance = FMath::RandRange(100, 400);
	currentPos = initPos;

	direction.Normalize();
	SetActorLocation(initPos);
}