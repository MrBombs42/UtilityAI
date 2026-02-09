// Fill out your copyright notice in the Description page of Project Settings.


#include "Consideration.h"

#include "VectorUtil.h"

float UConsideration::Score(AActor* Owner, UObject* Context) const
{
	float rawScore  = CalculateScore(Owner, Context);

	if (ResponseCurve)
	{
		return ResponseCurve -> GetFloatValue(rawScore);
	}

	return FMath::Clamp(rawScore, 0.0f, 0.0f);
}

float UConsideration::CalculateScore_Implementation(AActor* Owner, UObject* Context) const
{
	return 0.0f;
}
