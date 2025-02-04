// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyPlatform.h"
#include "RotatePlatform.generated.h"

/**
 * 
 */
UCLASS()
class RANDOMOBSTACLEFIELD_API ARotatePlatform : public AMyPlatform
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Rotate info")
	float rotateSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Rotate info")
	FRotator axis;

	virtual void BeginPlay() override;
public:
	ARotatePlatform();
	ARotatePlatform(const FObjectInitializer& ObjectInitializer, const float inputSpeed);
	virtual void Tick(float DeltaTime) override;
	void SetSpeed(const float& inputSpeed);
	float GetSpeed();
	void SetAxis(const FRotator& inputAxis);
	FRotator GetAxis();
	void StatusInit() override;
};
