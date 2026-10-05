// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingCube.h"

#include "NetworkReplayStreaming.h"

// Sets default values
ARotatingCube::ARotatingCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Cube");
	
	RootComponent = Mesh;
	
	Mesh->SetMobility(EComponentMobility::Movable);
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ModelCube(TEXT("/Game/LevelPrototyping/Meshes/SM_ChamferCube.SM_ChamferCube"));
	
	if (ModelCube.Succeeded())
	{
		Mesh->SetStaticMesh(ModelCube.Object);
	}

}

// Called when the game starts or when spawned
void ARotatingCube::BeginPlay()
{
	Super::BeginPlay();
	
	InitialLocation = GetActorLocation();
}

// Called every frame
void ARotatingCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);	
	
	float AddAngle = DeltaTime * RotationSpeed;
	
	AddActorLocalRotation(FRotator(0.0f, AddAngle, 0.0f));
	
	if (bFloat)
	{
		Time = Time + DeltaTime;
		
		float Gap = FMath::Sin(Time * RotationSpeed) * FloatingHight;
		
		FVector NewLocation = InitialLocation;
		NewLocation.Z = InitialLocation.Z + Gap;
		SetActorLocation(NewLocation);
	}
}

