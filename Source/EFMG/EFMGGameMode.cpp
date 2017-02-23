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
}

void LogActorBounds(AActor* tile, bool colliding)
{
	FVector origin;
	FVector boxExtent;
	tile->GetActorBounds(colliding, origin, boxExtent);
	UE_LOG(LogTemp, Warning, TEXT("Actor bounds (%d) origin %.2f %.2f %.2f boxExtent %.2f %.2f %.2f"), colliding, origin.X, origin.Y, origin.Z, boxExtent.X, boxExtent.Y, boxExtent.Z);
}

void AEFMGGameMode::Tick(float DeltaSeconds)
{
	// Move tiles
	// Spawn tiles
	if (mTiles.Num() == 0)
		SpawnTile();
	else
	{
		AActor* tile = mTiles[0];
		if (!tile->IsPendingKill())
		{

			FVector location = tile->GetActorLocation();
			UE_LOG(LogTemp, Warning, TEXT("Location %.2f %2.f %2f"), location.X, location.Y, location.Z);
			LogActorBounds(tile, true);
			LogActorBounds(tile, false);
		}

		//if (GetTileTopEdge(mTiles[0]) > 0)
		//	SpawnTile();
	}
	// Remove bottom ones
}

void AEFMGGameMode::SpawnTile()
{
	UWorld* const world = GetWorld();
	if (world)
	{
		if (tileClass)
		{
			const FRotator spawnRotation(0, 180, 0);
			const FVector spawnLocation;
			AActor* newTile = world->SpawnActor(tileClass, &spawnLocation, &spawnRotation);
			mTiles.Insert(newTile, 0);
		}
	}

}

float AEFMGGameMode::GetTileTopEdge(AActor* tile)
{
	FBoxSphereBounds bounds = GetTileBounds(tile);
	return bounds.Origin.X - bounds.BoxExtent.X;
}

FBoxSphereBounds AEFMGGameMode::GetTileBounds(AActor* tile)
{
	TInlineComponentArray<UStaticMeshComponent*> meshes;
	tile->GetComponents(meshes);
	for (auto m : meshes)
	{
		FString terrainName = "Terrain ";
		if (m->GetName() == terrainName)
			return m->Bounds;
	}

	UE_LOG(LogTemp, Warning, TEXT("No Terrain named static mech in tile blueprint "));
	return FBoxSphereBounds();
}

float AEFMGGameMode::GetTileLength(AActor* tile)
{
	FBoxSphereBounds bounds = GetTileBounds(tile);
	return bounds.BoxExtent.X * 2;
}
