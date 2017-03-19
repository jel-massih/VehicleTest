#include "VehicleTest.h"
#include "DevRVWheeledVehicle.h"

#include "Components/InputComponent.h"
#include "WheeledVehicleMovementComponent4W.h"


ADevRVWheeledVehicle::ADevRVWheeledVehicle()
{
}

void ADevRVWheeledVehicle::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// set up gameplay key bindings
	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ADevRVWheeledVehicle::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ADevRVWheeledVehicle::MoveRight);
	PlayerInputComponent->BindAxis("LookUp");
	PlayerInputComponent->BindAxis("LookRight");
}

void ADevRVWheeledVehicle::MoveForward(float Val)
{
	GetVehicleMovementComponent()->SetThrottleInput(Val);
}

void ADevRVWheeledVehicle::MoveRight(float Val)
{
	GetVehicleMovementComponent()->SetSteeringInput(Val);
}

void ADevRVWheeledVehicle::Tick(float Delta)
{
	Super::Tick(Delta);
}

void ADevRVWheeledVehicle::BeginPlay()
{
	Super::BeginPlay();
}