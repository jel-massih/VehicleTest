#include "VehicleTest.h"
#include "DevRVWheeledVehicle.h"

#include "Components/InputComponent.h"
#include "WheeledVehicleMovementComponent4W.h"


ADevRVWheeledVehicle::ADevRVWheeledVehicle(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer.SetDefaultSubobjectClass<URVWheeledVehicleMovementComponent>(AWheeledVehicle::VehicleMovement))
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

void ADevRVWheeledVehicle::PostNetReceivePhysicState()
{
	if (Role == ROLE_SimulatedProxy)
	{
		const FVector OldLocation = GetActorLocation();
		const FVector NewLocation = ReplicatedMovement.Location;
		const FQuat OldRotation = GetActorQuat();

		
		GetRVWheeledVehicleMovementComponent()->bNetworkSmoothingComplete = false;
		GetRVWheeledVehicleMovementComponent()->SmoothCorrection(OldLocation, OldRotation, NewLocation, ReplicatedMovement.Rotation.Quaternion());
	}
	
	/*UPrimitiveComponent* RootPrimComp = Cast<UPrimitiveComponent>(RootComponent);
	if (RootPrimComp)
	{
		FRigidBodyState NewState;
		ReplicatedMovement.CopyTo(NewState, this);

		FVector DeltaPos(FVector::ZeroVector);
		RootPrimComp->ConditionalApplyRigidBodyState(NewState, GEngine->PhysicErrorCorrection, DeltaPos);
	}*/
}
