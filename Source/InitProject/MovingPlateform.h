// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlateform.generated.h"

UCLASS()
class INITPROJECT_API AMovingPlateform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlateform();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, Category = "Movement")
	float SpeedX;
	
	UPROPERTY(EditAnywhere, Category = "Movement")
	float SpeedY;
	
	UPROPERTY(EditAnywhere, Category = "Movement")
	float SpeedZ;
	
	UPROPERTY(EditAnywhere, Category = "Movement")
	float Distance;

};
