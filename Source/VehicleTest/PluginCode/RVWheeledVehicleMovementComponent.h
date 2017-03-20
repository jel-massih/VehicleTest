#pragma once

#include "Engine/EngineTypes.h"

#include "WheeledVehicleMovementComponent4W.h"
#include "RVWheeledVehicleMovementComponent.generated.h"

UCLASS()
class URVWheeledVehicleMovementComponent : public UWheeledVehicleMovementComponent4W
{
	GENERATED_UCLASS_BODY()

protected:

	/** Vehicle movementcomponent belongs to */
	UPROPERTY(Transient, DuplicateTransient)
	ADevRVWheeledVehicle* VehicleOwner;

public:

	/** Smoothing mode for simulated proxies in network game. */
	UPROPERTY(Category = "Character Movement (Networking)", EditAnywhere, BlueprintReadOnly)
	ENetworkSmoothingMode NetworkSmoothingMode;

public:

	virtual void PostLoad() override;

	//Server Stuff

	//Client Stuff
	virtual void SmoothCorrection(const FVector& OldLocation, const FQuat& OldRotaiton, const FVector& NewLocation, const FQuat& NewRotation);

public:
	uint32 bNetworkSmoothingComplete : 1;
};

class FNetworkPredictionData_Client_Vehicle : public FNetworkPredictionData_Client, protected FNoncopyable
{
public:
	FNetworkPredictionData_Client_Vehicle(const URVWheeledVehicleMovementComponent& VehicleMovement);
	virtual ~FNetworkPredictionData_Client_Vehicle();

	//Client timestamp of last time it sent servermove() to server. Saves bandwidth by delaying serverupdates
	float ClientUpdateTime;

	//Current timestamp for sending new moves to server
	float CurrentTimeStamp;
};