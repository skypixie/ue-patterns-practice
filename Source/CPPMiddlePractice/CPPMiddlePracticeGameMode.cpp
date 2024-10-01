// Copyright Epic Games, Inc. All Rights Reserved.

#include "CPPMiddlePracticeGameMode.h"
#include "CPPMiddlePracticeCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACPPMiddlePracticeGameMode::ACPPMiddlePracticeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
