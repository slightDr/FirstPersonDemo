// Copyright Epic Games, Inc. All Rights Reserved.


#include "Class2_FirstPerson_rPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"

void AClass2_FirstPerson_rPlayerController::AddPoints(int32 add)
{
	iPoints += add;
	UE_LOG(LogTemp, Warning, TEXT("points: %d"), iPoints);
}

void AClass2_FirstPerson_rPlayerController::BeginPlay()
{
	Super::BeginPlay();

	iPoints = 0;

	// get the enhanced input subsystem
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		// add the mapping context so we get controls
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
}
