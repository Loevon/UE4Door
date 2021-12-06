// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "TrustGameMode.h"
#include "TrustHUD.h"
#include "TrustCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATrustGameMode::ATrustGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATrustHUD::StaticClass();
}
