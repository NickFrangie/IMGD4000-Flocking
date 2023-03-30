// Fill out your copyright notice in the Description page of Project Settings.


#include "FlockingManager.h"

#define AGENT_COUNT 10
#define RULE1_FACTOR 100
#define RULE2_FACTOR 100
#define RULE3_FACTOR 100

void UFlockingManager::Init( UWorld *world, UStaticMeshComponent *mesh ) {
    UE_LOG(LogTemp, Warning, TEXT("Manager initialized"));
    
    World = world;
    float incr = (PI * 2.f) / AGENT_COUNT;
    for( int i = 0; i < AGENT_COUNT; i++ ) {
        if( World != nullptr ) {
            FRotator rotation = FRotator();

            FVector location = FVector();
            location.X = FMath::Sin( incr * i ) * 150.f;
            location.Z = FMath::Cos( incr * i ) * 150.f;

            AAgent * agent = World->SpawnActor<AAgent>( location, rotation );
            agent->Init( mesh, i );
            Agents.Add( agent );
        }
    }

    initialized = true;
}

void UFlockingManager::Flock() {
    for (int i = 0; i < Agents.Num(); i++) {
        AAgent * agent = Agents[i];

        FVector v1 = Rule1(agent) / RULE1_FACTOR;
        FVector v2 = Rule2(agent);
        FVector v3 = Rule3(agent);

        agent->Velocity += v1 + v2 + v3;
    }
}

FVector UFlockingManager::Rule1( AAgent * boid ) {
    FVector pc = FVector(0.f);
    for (int i = 0; i < Agents.Num(); i++) {
        AAgent * agent = Agents[i];
        if (agent != boid) {
            pc += agent->GetActorLocation();
        }
    }

    pc = pc / (Agents.Num() - 1);
    return pc - boid->GetActorLocation();
}

FVector UFlockingManager::Rule2( AAgent * agent ) {
    return FVector(0.f);
}

FVector UFlockingManager::Rule3( AAgent * agent ) {
    return FVector(0.f);
}