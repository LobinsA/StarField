// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "Teleporter.generated.h"

/**
 * 
 */
UCLASS()
class STARFIELD_API ATeleporter : public ATriggerBox
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
public:
	ATeleporter();
	UFUNCTION()
	void Teleporter(class AActor* overlappingActor, class AActor* otherActor);
};	
