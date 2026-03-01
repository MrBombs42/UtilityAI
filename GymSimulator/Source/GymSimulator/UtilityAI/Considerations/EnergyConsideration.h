// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Base/CurveConsideration.h"
#include "EnergyConsideration.generated.h"

/**
 *
 */
UCLASS()
class GYMSIMULATOR_API UEnergyConsideration : public UCurveConsideration
{
	GENERATED_BODY()

protected:
	virtual float CalculateScore_Implementation(AActor* Owner, UObject* Context) const override;
};
