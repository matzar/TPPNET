// Fill out your copyright notice in the Description page of Project Settings.

/**
* The Actors are the key bit of replication.
* The Actor will be updated on the Client, from the Server,
* only if the Actor is a Replicated Actor and there's a Replicated propert on that actor.
*/

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MovingPlatform.generated.h"

/**
 *
 */
UCLASS()
class TTPNET_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	AMovingPlatform();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float Speed = 20;
};
