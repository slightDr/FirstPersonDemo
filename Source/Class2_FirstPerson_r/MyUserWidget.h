// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUserWidget.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class CLASS2_FIRSTPERSON_R_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()

	
public:
	void ShowPoints(int32 Points);

	// Called when the widget is constructed
	virtual void NativeConstruct() override;
	
	// 用来绑定蓝图中的 TextBlock 控件
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* PointsText;
};
