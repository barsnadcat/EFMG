// Fill out your copyright notice in the Description page of Project Settings.

#include "EFMG.h"
#include "BirdCamera.h"


// Sets default values
ABirdCamera::ABirdCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// Create a camera...
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	

}

// Called when the game starts or when spawned
void ABirdCamera::BeginPlay()
{
	Super::BeginPlay();
	
	// If we find a matching PC, bind to it immediately.
	APlayerController* playerController = GetPlayerController();
	if (playerController)
		playerController->SetViewTarget(this);
}

// Called every frame
void ABirdCamera::Tick( float DeltaTime )
{
	Super::Tick(DeltaTime);

	APlayerController* playerController = GetPlayerController();

	APawn* pawn = playerController->GetPawn();
	if (!pawn)
		return;

	// Put camera at same x as pawn
	float x = pawn->GetActorLocation().X;	
	FVector pos = GetActorLocation();
	pos.X = x;
	this->SetActorLocation(pos);


}

APlayerController* ABirdCamera::GetPlayerController()
{
	UWorld* const world = GetWorld();
	if (!world)
		return nullptr;
	return world->GetFirstPlayerController();
}