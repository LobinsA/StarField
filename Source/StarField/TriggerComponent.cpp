// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

UTriggerComponent::UTriggerComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

AActor* UTriggerComponent::GetAcceptableActor() const
{
    TArray<AActor*> Actors;
    GetOverlappingActors(Actors);
    for (AActor* Actor : Actors)
    {
        bool HasAcceptableTag = Actor->ActorHasTag(AcceptableActorTag);
        if (HasAcceptableTag)
        {
            return Actor;
        }

    }

    return nullptr;
}

void UTriggerComponent::MineAsteroid()
{
    AActor* Actor = GetAcceptableActor();
    if (Actor != nullptr)
    {
        UE_LOG(LogTemp, Warning, TEXT("Mining Asteroid."));
        //TODO: increase resource value
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("No Asteroid Nearby."));
    }
}
