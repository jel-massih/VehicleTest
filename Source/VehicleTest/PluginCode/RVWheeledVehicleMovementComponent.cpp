#include "VehicleTest.h"
#include "RVWheeledVehicleMovementComponent.h"

URVWheeledVehicleMovementComponent::URVWheeledVehicleMovementComponent(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
	NetworkSmoothingMode = ENetworkSmoothingMode::Exponential;

	bNetworkSmoothingComplete = true;
}

void URVWheeledVehicleMovementComponent::PostLoad()
{
	Super::PostLoad();

	VehicleOwner = Cast<ADevRVWheeledVehicle>(PawnOwner);
}

void URVWheeledVehicleMovementComponent::SmoothCorrection(const FVector& OldLocation, const FQuat& OldRotaiton, const FVector& NewLocation, const FQuat& NewRotation)
{
	//Shouldnt be running on a server that is not listen
	checkSlow(GetNetMode() != NM_DedicatedServer);
	checkSlow(GetNetMode() != NM_Standalone);

	//Only proxies or remote clients on listen server should run this
	const bool bIsSimulatedProxy = (VehicleOwner->Role);
	const bool bIsRemoteAutoProxy = (VehicleOwner->GetRemoteRole() == ROLE_AutonomousProxy);
	ensure(bIsSimulatedProxy || bIsRemoteAutoProxy);

	bNetworkSmoothingComplete = false;

	if (NetworkSmoothingMode == ENetworkSmoothingMode::Replay)
	{
		//Replays use pure interp
		return;
	}
	else if (NetworkSmoothingMode == ENetworkSmoothingMode::Disabled)
	{
		UpdatedComponent->SetWorldLocationAndRotation(NewLocation, NewRotation);
		bNetworkSmoothingComplete = true;
	}
	else if (FNetworkPredictionData_Client_Vehicle* ClientData = GetPredictionData_Client_Vehicle())
	{

	}
}