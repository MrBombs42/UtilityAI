// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Consideration.h"
#include "EnergyConsideration.generated.h"

/**
 *
 */
UCLASS()
class GYMSIMULATOR_API UEnergyConsideration : public UConsideration
{
	GENERATED_BODY()

protected:
	virtual float CalculateScore_Implementation(AActor* Owner, UObject* Context) const override;
};
