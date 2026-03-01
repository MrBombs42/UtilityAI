// Fill out your copyright notice in the Description page of Project Settings.


#include "UtilityAI/Considerations/Base/CurveConsideration.h"

float UCurveConsideration::Score(AActor* Owner, UObject* Context) const
{
	float rawScore  = CalculateScore(Owner, Context);

	if (ResponseCurve)
	{
		return ResponseCurve -> GetFloatValue(rawScore);
	}

	return FMath::Clamp(rawScore, 0.0f, 0.0f);
}