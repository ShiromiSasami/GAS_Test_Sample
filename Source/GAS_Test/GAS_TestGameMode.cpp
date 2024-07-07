// Copyright Epic Games, Inc. All Rights Reserved.

#include "GAS_TestGameMode.h"
#include "GAS_TestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGAS_TestGameMode::AGAS_TestGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
