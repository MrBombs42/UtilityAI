// Fill out your copyright notice in the Description page of Project Settings.


#include "UtilityAI/Actions/UtilityAction.h"

#include "Consideration.h"

float UUtilityAction::CalculateFinalScore(AActor* Owner, UObject* Context) const
{
	if (Considerations.Num() == 0)
	{
		return 0.0f;
	}

	float FinalScore = 1.0f;

	for (UConsideration* Consideration : Considerations)
	{
		if (Consideration)
		{
			float Score = Consideration->Score(Owner, Context);
			FinalScore *= Score;
		}
	}

	return FinalScore;
}

void UUtilityAction::Execute_Implementation(AActor* Owner, UObject* Context)
{
	UE_LOG(LogTemp, Warning, TEXT("Executing action: %s"), *ActionName);
}

void UUtilityAction::Stop_Implementation(AActor* Owner)
{
	UE_LOG(LogTemp, Warning, TEXT("Stopping action: %s"), *ActionName);
}
