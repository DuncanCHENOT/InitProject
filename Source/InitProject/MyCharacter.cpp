// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"	// Move Manager
#include "EnhancedInputComponent.h"						// Input system from Unreal
//#include "Engine/Engine.h"								// Print to screen
//#include "ScoreWidget.h"								// Score UI
#include "Components/CapsuleComponent.h"				// The Character collision capsule
#include "Kismet/GameplayStatics.h"						// To restart the level
//#include "TimerManager.h"								// Timer

// Sets default values
AMyCharacter::AMyCharacter()
{

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
	GetCharacterMovement()->JumpZVelocity = JumpForce;
	
	JumpMaxCount = MaxJump;
	
	AddPoints(0);
	
	Lives = MaxLives;
	UpdateLivesDisplay();
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	UEnhancedInputComponent* InputComp = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	
	if (InputComp && SprintAction)
	{
		InputComp->BindAction(SprintAction, ETriggerEvent::Started, this, &AMyCharacter::StartSprint);
		
		InputComp->BindAction(SprintAction, ETriggerEvent::Completed, this, &AMyCharacter::StopSprint);
		
	}
}

void AMyCharacter::StartSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
}

void AMyCharacter::StopSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = WalkSpeed;
}

void AMyCharacter::AddPoints(int32 Points)
{
	Score += Points;
	
	if (GEngine)
	{
		FString Message = FString::Printf(TEXT("Score: %d / %d"), Score, ScoreToWin);
		GEngine->AddOnScreenDebugMessage(1, 100.f, FColor::Yellow, Message);
		
		if (Score >= ScoreToWin)
		{
			GEngine->AddOnScreenDebugMessage(2, 100.f, FColor::Green, TEXT("You win!"), true, FVector2D(3.f,3.f));
		}
	}
}

void AMyCharacter::LoseLife()
{
	if (bIsDead)
	{
		return;
	}
	
	Lives -= 1;
	
	UpdateLivesDisplay();
	
	if (Lives <= 0)
	{
		Die();
	}
}

void AMyCharacter::UpdateLivesDisplay()
{
	if (GEngine)
	{
		FString Message = FString::Printf(TEXT("Vies : %d / %d"), Lives, MaxLives);
		GEngine->AddOnScreenDebugMessage(3, 100.f, FColor::Red, Message);
	}
}

void AMyCharacter::Die()
{
	if (bIsDead)
	{
		return;
	}
	
	bIsDead = true;
	
	Lives = 0;
	UpdateLivesDisplay();
	
	GetCharacterMovement()->DisableMovement();
	DisableInput(Cast<APlayerController>(GetController()));
	
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	GetMesh()->SetCollisionProfileName(TEXT("Ragdoll"));
	GetMesh()->SetSimulatePhysics(true);
	
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(4, 100.f, FColor::Red, TEXT("Dead!"), true, FVector2D(3.f,3.f));
	}
	
	GetWorldTimerManager().SetTimer(RestartTimer, this, &AMyCharacter::RestartLevel, RestartDelay, false);
}

void AMyCharacter::RestartLevel()
{
	FString LevelName = UGameplayStatics::GetCurrentLevelName(this);
	UGameplayStatics::OpenLevel(this, FName(*LevelName));
}