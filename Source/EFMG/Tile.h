// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Tile.generated.h"

class UProjectileMovementComponent;
class UStaticMeshComponent;

UCLASS()
class EFMG_API ATile : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ATile();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
private:
	UProjectileMovementComponent* obstacleMovement;
	
};
