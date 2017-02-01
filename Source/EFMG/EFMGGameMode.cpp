// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "EFMG.h"
#include "EFMGGameMode.h"
#include "EFMGPawn.h"

AEFMGGameMode::AEFMGGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AEFMGPawn::StaticClass();
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FClassFinder<AActor> tileClassFinder(TEXT("/Game/Tiles/Tile_00"));
	tileClass = tileClassFinder.Class;
}

// Called when the game starts or when spawned
void AEFMGGameMode::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(courseTimerHandle, this, &AEFMGGameMode::CourseTimer, 1);
}

void AEFMGGameMode::CourseTimer()
{
	UWorld* const world = GetWorld();
	if (world)
	{
		if (tileClass)
		{
			world->GetTimerManager().SetTimer(courseTimerHandle, this, &AEFMGGameMode::CourseTimer, 1);
			const FRotator spawnRotation(0, 180, 0);
			const FVector spawnLocation;
			AActor* newTile = world->SpawnActor(tileClass, &spawnLocation, &spawnRotation);
		}
		else
			UE_LOG(LogTemp, Log, TEXT("Failed!"));
	}

}
