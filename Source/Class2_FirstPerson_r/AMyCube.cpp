// Fill out your copyright notice in the Description page of Project Settings.


#include "AMyCube.h"


// Sets default values
AAMyCube::AAMyCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	iShotPoints = 100;
	bHasBeenShot = false;
	fScaleFac = 0.5f;
	InitCubeMesh();
}

void AAMyCube::InitCubeMesh()
{
	// 在构造函数中创建该组件
	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	RootComponent = CubeMesh;  // 将该组件设置为根组件

	// 加载StaticMesh并将其应用到 CubeMesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("/Game/LevelPrototyping/Meshes/SM_ChamferCube.SM_ChamferCube"));
	if (CubeMeshAsset.Succeeded())
	{
		CubeMesh->SetStaticMesh(CubeMeshAsset.Object);  // 设置 StaticMesh
	}
	CubeMesh->SetSimulatePhysics(true);
}

void AAMyCube::ChangeScale()
{
	// 获取当前的Scale
	FVector CurrentScale = GetActorScale3D();
    
	// 按倍数缩放
	FVector NewScale = CurrentScale * fScaleFac;
    
	// 设置新的Scale
	SetActorScale3D(NewScale);
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

