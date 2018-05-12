// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "Flag_defenderGameMode.h"
#include "Flag_defenderCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFlag_defenderGameMode::AFlag_defenderGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
