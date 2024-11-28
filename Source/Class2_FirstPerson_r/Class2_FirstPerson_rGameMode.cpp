// Copyright Epic Games, Inc. All Rights Reserved.

#include "Class2_FirstPerson_rGameMode.h"

#include "AMyCube.h"
#include "Class2_FirstPerson_rCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

AClass2_FirstPerson_rGameMode::AClass2_FirstPerson_rGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
	
}

void AClass2_FirstPerson_rGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(
			TimerHandle_GameTimeLimit,
			this,
			&AClass2_FirstPerson_rGameMode::TimeLimit,
			fLimitTime,
			false
		);
	}

	DoubleSomeCubes();
}

void AClass2_FirstPerson_rGameMode::DoubleSomeCubes()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AAMyCube::StaticClass(), FoundActors);
	int CubeNum = FoundActors.Num();

	if (iDoubleNum > CubeNum)
		iDoubleNum = CubeNum;

	for (int i = 0; i < iDoubleNum; ++ i)
	{
		const int32 Idx = FMath::RandRange(0, FoundActors.Num() - 1);
		AAMyCube* Cube = Cast<AAMyCube>(FoundActors[Idx]);
		if (!Cube)
			continue;

		Cube->iShotPoints *= 2;
		FoundActors.RemoveAt(Idx);
	}
}

void AClass2_FirstPerson_rGameMode::TimeLimit() const
{
	UE_LOG(LogTemp, Warning, TEXT("Time limit reached! Ending game."));
	// 停止游戏或其他逻辑
	if (APlayerController* PC = GetWorld()->GetFirstPlayerController())
	{
		PC->SetPause(true); // 暂停游戏
	}
}
