// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyPlatform.h"
#include "MovePlatform.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMOBSTACLEFIELD_API AMovePlatform : public AMyPlatform
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Move info")
	float moveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Move info")
	FVector direction;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Move info")
	FVector initPos;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Move info")
	FVector currentPos;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Move info")
	float moveDistance;

	virtual void BeginPlay() override;

public:
	AMovePlatform();
	virtual void Tick(float DeltaTime) override;
	void SetSpeed(const float& inputSpeed);
	float GetSpeed();
	void SetDirection(const FVector& inputDirection);
	FVector GetDirection();
	void SetInitPos(const FVector& inputPos);
	FVector GetInitPos();
	void SetCurrentPos(const FVector& inputPos);
	FVector GetCurrentPos();
	void SetMoveDistance(const float& inputDistance);
	float GetMoveDistance();
	void ChangeDirection();
	void StatusInit() override;
};
