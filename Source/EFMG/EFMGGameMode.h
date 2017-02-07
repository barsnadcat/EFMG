// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "GameFramework/GameModeBase.h"
#include "EFMGGameMode.generated.h"

UCLASS(minimalapi)
class AEFMGGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:

	AEFMGGameMode();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
private:
	FBoxSphereBounds GetTileBounds(AActor* tile);
	float GetTileLength(AActor* tile);
	float GetTileTopEdge(AActor* tile);
	void SpawnTile();
private:
	UClass*      tileClass = NULL;

	UPROPERTY()
	TArray<AActor*> mTiles;
};
