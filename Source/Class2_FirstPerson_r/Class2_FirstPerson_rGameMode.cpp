// Copyright Epic Games, Inc. All Rights Reserved.

#include "Class2_FirstPerson_rGameMode.h"
#include "Class2_FirstPerson_rCharacter.h"
#include "UObject/ConstructorHelpers.h"

AClass2_FirstPerson_rGameMode::AClass2_FirstPerson_rGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
