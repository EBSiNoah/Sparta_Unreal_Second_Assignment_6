// Copyright Epic Games, Inc. All Rights Reserved.

#include "RandomObstacleFieldGameMode.h"
#include "RandomObstacleFieldCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARandomObstacleFieldGameMode::ARandomObstacleFieldGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
