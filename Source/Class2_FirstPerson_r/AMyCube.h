// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AMyCube.generated.h"

UCLASS()
class CLASS2_FIRSTPERSON_R_API AAMyCube : public AActor
{
	GENERATED_BODY()
	
public:
	// 方块的网格体组件
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CubeMesh;

	// 射中积分
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 iShotPoints;
	
	// Sets default values for this actor's properties
	AAMyCube();
	void InitCubeMesh();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
