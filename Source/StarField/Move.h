// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Move.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class STARFIELD_API UMove : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMove();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetShouldMove(bool mShouldMove);
	void SetShouldRotate(bool mShouldRotate);

private:
	UPROPERTY(EditAnywhere, Category="Moving")
	FVector MoveOffset;
	UPROPERTY(EditAnywhere, Category="Moving")
	FVector ObjectVelocity = FVector::ZeroVector;
	UPROPERTY(EditAnywhere, Category="Moving")
	float MoveTime = 1;
	UPROPERTY(EditAnywhere, Category="Moving")
	bool ShouldMove = false;

	UPROPERTY(EditAnywhere, Category="Moving")
	FRotator RotationVelocity = FRotator::ZeroRotator;
	UPROPERTY(EditAnywhere, Category="Moving")
	bool ShouldRotate = false;

	FVector StartLocation;

	void MoveObject(float DeltaTime);
	void RotateObject(float DeltaTime);

};
