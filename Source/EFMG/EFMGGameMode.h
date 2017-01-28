// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "GameFramework/GameModeBase.h"
#include "EFMGGameMode.generated.h"


UCLASS(minimalapi)
class AEFMGGameMode : public AGameModeBase
{
	GENERATED_BODY()
private:
	FTimerHandle courseTimerHandle;
	UClass* tileClass = NULL;
public:
	AEFMGGameMode();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void CourseTimer();

};



