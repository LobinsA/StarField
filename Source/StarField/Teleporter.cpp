// Fill out your copyright notice in the Description page of Project Settings.


#include "Teleporter.h"
#include "GameFramework/Actor.h"

ATeleporter::ATeleporter()
{
    OnActorBeginOverlap.AddDynamic(this, &ATeleporter::Teleporter);
}

void ATeleporter::BeginPlay()
{
    Super::BeginPlay();
}

void ATeleporter::Teleporter(AActor* overlappingActor, AActor* otherActor)
{
    UE_LOG(LogTemp, Display, TEXT("Entered Teleporter %s with %s"), *overlappingActor->GetName(),*otherActor->GetName());
    if (otherActor && otherActor != this)
    {
        otherActor->SetActorLocation(FVector(0,0,2000));
    }
}
