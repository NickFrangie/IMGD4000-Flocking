// Fill out your copyright notice in the Description page of Project Settings.


#pragma once

#include "CoreMinimal.h"
#include "Agent.h"
#include "FlockingManager.generated.h"

UCLASS()
class FLOCKING_API UFlockingManager : public UObject
{

public:
	GENERATED_BODY()

	void Init( UWorld *world, UStaticMeshComponent *mesh );
	void Flock();

private:
	FVector Rule1( AAgent * boid );
	FVector Rule2( AAgent * boid );
	FVector Rule3( AAgent * boid );

	UWorld *World;	
	bool initialized;
	TArray<class AAgent *> Agents;
};