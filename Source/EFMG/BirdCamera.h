// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "BirdCamera.generated.h"

UCLASS()
class EFMG_API ABirdCamera : public AActor
{
	GENERATED_BODY()

	/** The camera */
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent;

public:

	// Sets default values for this actor's properties
	ABirdCamera();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
private:
	APlayerController* GetPlayerController();


};
