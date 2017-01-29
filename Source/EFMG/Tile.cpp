// Fill out your copyright notice in the Description page of Project Settings.

#include "EFMG.h"
#include "Tile.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ATile::ATile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Use a ProjectileMovementComponent to govern this projectile's movement
	obstacleMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement0"));
	obstacleMovement->bAutoRegisterUpdatedComponent = true;
	obstacleMovement->InitialSpeed = 3000.f;
	obstacleMovement->MaxSpeed = 3000.f;
	obstacleMovement->bRotationFollowsVelocity = true;
	obstacleMovement->bShouldBounce = false;
	obstacleMovement->ProjectileGravityScale = 0.f; // No gravity

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;

}

// Called when the game starts or when spawned
void ATile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATile::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

