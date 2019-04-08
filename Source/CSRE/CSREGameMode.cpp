// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "CSREGameMode.h"
#include "CSREHUD.h"
#include "CSRECharacter.h"
#include "UObject/ConstructorHelpers.h"

ACSREGameMode::ACSREGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ACSREHUD::StaticClass();
}
