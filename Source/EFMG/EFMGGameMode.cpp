// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "EFMG.h"
#include "EFMGGameMode.h"
#include "EFMGPawn.h"

AEFMGGameMode::AEFMGGameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AEFMGPawn::StaticClass();
}

