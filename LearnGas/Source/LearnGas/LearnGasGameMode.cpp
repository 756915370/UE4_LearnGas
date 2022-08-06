// Copyright Epic Games, Inc. All Rights Reserved.

#include "LearnGasGameMode.h"
#include "LearnGasCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALearnGasGameMode::ALearnGasGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
