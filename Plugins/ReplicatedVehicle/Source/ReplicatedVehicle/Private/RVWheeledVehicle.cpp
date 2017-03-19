#include "IReplicatedVehicle.h"
#include "RVWheeledVehicle.h"

#include "Components/InputComponent.h"
#include "WheeledVehicleMovementComponent4W.h"


ARVWheeledVehicle::ARVWheeledVehicle()
{
}

void ARVWheeledVehicle::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// set up gameplay key bindings
	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ARVWheeledVehicle::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ARVWheeledVehicle::MoveRight);
	PlayerInputComponent->BindAxis("LookUp");
	PlayerInputComponent->BindAxis("LookRight");
}

void ARVWheeledVehicle::MoveForward(float Val)
{
	GetVehicleMovementComponent()->SetThrottleInput(Val);
}

void ARVWheeledVehicle::MoveRight(float Val)
{
	GetVehicleMovementComponent()->SetSteeringInput(Val);
}

void ARVWheeledVehicle::Tick(float Delta)
{
	Super::Tick(Delta);
}

void ARVWheeledVehicle::BeginPlay()
{
	Super::BeginPlay();
}