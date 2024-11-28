// Fill out your copyright notice in the Description page of Project Settings.


#include "AMyCube.h"


// Sets default values
AAMyCube::AAMyCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAMyCube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAMyCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

