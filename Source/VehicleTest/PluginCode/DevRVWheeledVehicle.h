#pragma once
#include "WheeledVehicle.h"
#include "DevRVWheeledVehicle.generated.h"

UCLASS()
class ADevRVWheeledVehicle : public AWheeledVehicle
{
	GENERATED_UCLASS_BODY()

public:
	// Begin Pawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End Pawn interface

	// Begin Actor interface
	virtual void Tick(float Delta) override;
	virtual void PostNetReceivePhysicState();

protected:
	virtual void BeginPlay() override;
	// End Actor interface

	class URVWheeledVehicleMovementComponent* GetRVWheeledVehicleMovementComponent() const { return Cast<URVWheeledVehicleMovementComponent>(VehicleMovement); }

public:

	/** Handle pressing forwards */
	void MoveForward(float Val);
	/** Handle pressing right */
	void MoveRight(float Val);
};
