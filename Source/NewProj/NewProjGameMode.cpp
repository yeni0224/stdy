// Copyright Epic Games, Inc. All Rights Reserved.

#include "NewProjGameMode.h"
#include "NewProjCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANewProjGameMode::ANewProjGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
