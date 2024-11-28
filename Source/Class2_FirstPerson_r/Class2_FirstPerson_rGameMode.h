// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Class2_FirstPerson_rGameMode.generated.h"

UCLASS(minimalapi)
class AClass2_FirstPerson_rGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float fLimitTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int iDoubleNum;

	FTimerHandle TimerHandle_GameTimeLimit; // 定义定时器句柄
	
	AClass2_FirstPerson_rGameMode();

	UFUNCTION(BlueprintCallable)
	virtual void BeginPlay() override;

	void DoubleSomeCubes();

	void TimeLimit() const;
};



