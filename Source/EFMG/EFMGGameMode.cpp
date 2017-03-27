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
	for (int i = 0; i < 9; i++)
		mEnd = SpawnTile(mEnd);
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
	UWorld* const world = GetWorld();
	if (!world)
		return;
	
	// Get player pos
	FVector pos = world->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	
	// Get distance to the course end
	float len = FVector::Dist(mEnd, pos);

	if (len < 500.f)
	{
		// Spawn new tile
		mEnd = SpawnTile(mEnd);
		// Remove last tile
		AActor* lastTile = mTiles.Pop();
		world->DestroyActor(lastTile);

	}	
}

FVector AEFMGGameMode::SpawnTile(FVector spawnLocation)
{
	UWorld* const world = GetWorld();
	if (world)
	{
		if (tileClass)
		{
			UE_LOG(LogTemp, Warning, TEXT("Spawn tile at %.2f %2.f %2f"), spawnLocation.X, spawnLocation.Y, spawnLocation.Z);

			const FRotator spawnRotation(0, 180, 0);
			AActor* newTile = world->SpawnActor(tileClass, &spawnLocation, &spawnRotation);
			mTiles.Insert(newTile, 0);
			return spawnLocation + FVector(10000.f, 0, 0);
		}
	}
	return FVector();

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
