#pragma once
#include "WheeledVehicle.h"
#include "RVWheeledVehicle.generated.h"

UCLASS()
class REPLICATEDVEHICLE_API ARVWheeledVehicle : public AWheeledVehicle
{
	GENERATED_BODY()

public:
	ARVWheeledVehicle();

	// Begin Pawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End Pawn interface

	// Begin Actor interface
	virtual void Tick(float Delta) override;
protected:
	virtual void BeginPlay() override;
	// End Actor interface

public:

	/** Handle pressing forwards */
	void MoveForward(float Val);
	/** Handle pressing right */
	void MoveRight(float Val);
};
