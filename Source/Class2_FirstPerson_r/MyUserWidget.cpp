// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget.h"

#include "Components/TextBlock.h"

void UMyUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Check if PointsText is valid
	if (PointsText)
	{
		UE_LOG(LogTemp, Warning, TEXT("PointsText successfully bound!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PointsText binding failed!"));
	}
}

void UMyUserWidget::ShowPoints(int32 Points)
{
	if (!PointsText)
	{
		UE_LOG(LogTemp, Warning, TEXT("PointsText empty!"));
		return;
	}
	
	PointsText->SetText(FText::FromString(FString::FromInt(Points)));
}
