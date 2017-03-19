#include "IReplicatedVehicle.h"
#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"


class FReplicatedVehicle : public IReplicatedVehicle
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE(FReplicatedVehicle, ReplicatedVehicle )

void FReplicatedVehicle::StartupModule()
{
}

void FReplicatedVehicle::ShutdownModule()
{
}



