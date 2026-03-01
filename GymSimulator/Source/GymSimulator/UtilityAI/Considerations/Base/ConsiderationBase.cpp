// Fill out your copyright notice in the Description page of Project Settings.


#include "UtilityAI/Considerations/Base/ConsiderationBase.h"

float UConsiderationBase::Score(AActor* Owner, UObject* Context) const
{
	return CalculateScore(Owner, Context);
}

float UConsiderationBase::CalculateScore_Implementation(AActor* Owner, UObject* Context) const
{
	return 0.0f;
}