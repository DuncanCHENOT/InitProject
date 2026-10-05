// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingCube.generated.h"

class UStaticMeshComponent; 
UCLASS()
class INITPROJECT_API ARotatingCube : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARotatingCube();
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, Category = "Cours")
	UStaticMeshComponent* Mesh;
	
	UPROPERTY(EditAnywhere, Category = "Cours")
	float RotateSpeed = 90.f;
	
	UPROPERTY(EditAnywhere, Category = "Cours")
	bool bFloat = true;
	
	UPROPERTY(EditAnywhere, Category = "Cours")
	float FloatingHight = 50.f;
	
	UPROPERTY(EditAnywhere, Category = "Cours")
	float RotationSpeed = 2.f;
	
private:
	FVector InitialLocation;
	float Time = 0.f;

};
