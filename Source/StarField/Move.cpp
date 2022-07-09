// Fill out your copyright notice in the Description page of Project Settings.


#include "Move.h"

// Sets default values for this component's properties
UMove::UMove()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMove::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetOwner()->GetActorLocation();
	
}


// Called every frame
void UMove::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	MoveObject(DeltaTime);
	RotateObject(DeltaTime);

}

void UMove::SetShouldMove(bool mShouldMove)
{
	ShouldMove = mShouldMove;
}

void UMove::SetShouldRotate(bool mShouldRotate)
{
	ShouldRotate = mShouldRotate;
}

void UMove::MoveObject(float DeltaTime)
{
	FVector TargetLocation = StartLocation;
	if (ShouldMove)
	{
		TargetLocation = StartLocation + MoveOffset;
	}
	FVector CurrentLocation = GetOwner()->GetActorLocation();
	float Speed = MoveOffset.Length() / MoveTime;

	FVector NewLocation = FMath::VInterpConstantTo(CurrentLocation, TargetLocation, DeltaTime, Speed);
	GetOwner()->SetActorLocation(NewLocation);
}

void UMove::RotateObject(float DeltaTime)
{
	FRotator CurrentRotation = GetOwner()->GetActorRotation();
	if (ShouldRotate)
	{
		CurrentRotation = CurrentRotation + RotationVelocity * DeltaTime;
	}
	GetOwner()->SetActorRotation(CurrentRotation);
}

