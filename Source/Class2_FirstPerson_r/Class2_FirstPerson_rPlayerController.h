// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MyUserWidget.h"
#include "GameFramework/PlayerController.h"
#include "Class2_FirstPerson_rPlayerController.generated.h"

class UInputMappingContext;

/**
 *
 */
UCLASS(Blueprintable)
class CLASS2_FIRSTPERSON_R_API AClass2_FirstPerson_rPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:

	/** Input Mapping Context to be used for player input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMappingContext;

	// Begin Actor interface

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Points")
	int32 iPoints;

	UFUNCTION(BlueprintCallable)
	void AddPoints(int32 add);
	
protected:

	virtual void BeginPlay() override;

	// End Actor interface
	
public:
	// 用于存储 UMyUserWidget 的实例
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMyUserWidget* MyUserWidgetInstance;
};
