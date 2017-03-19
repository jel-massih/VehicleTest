// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "VehicleTest.h"
#include "VehicleTestGameMode.h"
#include "VehicleTestPawn.h"
#include "VehicleTestHud.h"

AVehicleTestGameMode::AVehicleTestGameMode()
{
	DefaultPawnClass = AVehicleTestPawn::StaticClass();
	HUDClass = AVehicleTestHud::StaticClass();
}
