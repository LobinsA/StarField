// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "Teleporter.h"
#include "GameFramework/Actor.h"

ATeleporter::ATeleporter()
{
    OnActorBeginOverlap.AddDynamic(this, &ATeleporter::EnterTeleporter);
    OnActorBeginOverlap.AddDynamic(this, &ATeleporter::ExitTeleporter);
    teleporting = false;
}

void ATeleporter::BeginPlay()
{
    Super::BeginPlay();
}

void ATeleporter::EnterTeleporter(AActor* overlappingActor, AActor* otherActor)
{
    if (otherActor && otherActor != this)
    {
        if (otherTele)
        {   
            ACharacter* character = Cast<ACharacter>(otherActor);
            if (character && !otherTele->teleporting)
            {
                teleporting = true;
                character->SetActorRotation(otherTele->GetActorRotation());
                character->GetController()->SetControlRotation(character->GetActorRotation());
                character->SetActorLocation(otherTele->GetActorLocation());
            }
        }
    }
}

void ATeleporter::ExitTeleporter(AActor* overlappingActor, AActor* otherActor)
{
    if (otherActor && otherActor)
    {
        if (otherTele && !teleporting)
        {
            otherTele->teleporting = false;
        }
    }
}
