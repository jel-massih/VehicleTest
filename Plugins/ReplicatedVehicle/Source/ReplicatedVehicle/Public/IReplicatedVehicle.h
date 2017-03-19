#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"


class IReplicatedVehicle : public IModuleInterface
{
public:

	static inline IReplicatedVehicle& Get()
	{
		return FModuleManager::LoadModuleChecked< IReplicatedVehicle >( "ReplicatedVehicle" );
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded( "ReplicatedVehicle" );
	}
};