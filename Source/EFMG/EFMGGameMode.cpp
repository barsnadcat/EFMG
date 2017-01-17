// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "EFMG.h"
#include "EFMGGameMode.h"
#include "EFMGPawn.h"

AEFMGGameMode::AEFMGGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AEFMGPawn::StaticClass();
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AEFMGGameMode::BeginPlay()
{
	Super::BeginPlay();
	//World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AEFMGGameMode::ObstacleTimer, FireRate);

}

void AEFMGGameMode::ObstacleTimer()
{
	//World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AEFMGGameMode::ObstacleTimer, FireRate);
}
