// Fill out your copyright notice in the Description page of Project Settings.

/**
* The Actors are the key bit of replication.
* The Actor will be updated on the Client, from the Server,
* only if the Actor is a Replicated Actor and there's a Replicated propert on that actor.
*/

#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
	}

	GlobalStartLocation = GetTargetLocation();
	// Transform Target Location gizmo from local space coordinates to global coordinates
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		// Save Actor's location (in global coordinates) in the vector
		FVector Location = GetActorLocation();

		float JourneyLength = (GlobalStartLocation - GlobalTargetLocation).Size();
		float JourneyTraveled = (GlobalStartLocation - Location).Size();

		if (JourneyTraveled > JourneyLength)
		{
			FVector Temp = GlobalTargetLocation;
			GlobalTargetLocation = GlobalStartLocation;
			GlobalStartLocation = Temp;
		}

		// Work out the direction vector based on the Actor's position and TragetLocation's (in global coordinates) position
		FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
		// Add the Direction vector to the Actor's location vector
		Location += Speed * DeltaTime * Direction;
		// Update Actor's location with the new Location vector
		SetActorLocation(Location);
	}
}

