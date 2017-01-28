// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "EFMG.h"
#include "EFMGGameMode.h"
#include "EFMGPawn.h"
#include "Obstacle.h"

AEFMGGameMode::AEFMGGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AEFMGPawn::StaticClass();
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FClassFinder<AActor> obstacleClassFinder(TEXT("/Game/Obstacle1"));
	obstacleClass = obstacleClassFinder.Class;
}

// Called when the game starts or when spawned
void AEFMGGameMode::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(obstacleTimerHandle, this, &AEFMGGameMode::ObstacleTimer, 1);
}

void AEFMGGameMode::ObstacleTimer()
{
	UWorld* const world = GetWorld();
	if (world)
	{
		if (obstacleClass)
		{
			world->GetTimerManager().SetTimer(obstacleTimerHandle, this, &AEFMGGameMode::ObstacleTimer, 1);
			const FRotator spawnRotation(0, 180, 0);
			const FVector spawnLocation;
			//world->SpawnActor<AObstacle>(spawnLocation, spawnRotation);
			world->SpawnActor(obstacleClass, &spawnLocation, &spawnRotation);
		}
		else
			UE_LOG(LogTemp, Log, TEXT("Failed!"));
	}

}
