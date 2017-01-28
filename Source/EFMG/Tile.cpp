// Fill out your copyright notice in the Description page of Project Settings.

#include "EFMG.h"
#include "Tile.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ATile::ATile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Static reference to the mesh to use for the projectile
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMeshAsset(TEXT("/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile"));

	// Create mesh component for the projectile sphere
	ObstacleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProjectileMesh0"));
	ObstacleMesh->SetStaticMesh(ProjectileMeshAsset.Object);
	ObstacleMesh->SetupAttachment(RootComponent);
	ObstacleMesh->BodyInstance.SetCollisionProfileName("Projectile");
	RootComponent = ObstacleMesh;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ObstacleMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement0"));
	ObstacleMovement->UpdatedComponent = ObstacleMesh;
	ObstacleMovement->InitialSpeed = 3000.f;
	ObstacleMovement->MaxSpeed = 3000.f;
	ObstacleMovement->bRotationFollowsVelocity = true;
	ObstacleMovement->bShouldBounce = false;
	ObstacleMovement->ProjectileGravityScale = 0.f; // No gravity

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

