// Fill out your copyright notice in the Description page of Project Settings.


#include "UtilityAI/Considerations/EnergyConsideration.h"

#include "NPC/GymNPC.h"

float UEnergyConsideration::CalculateScore_Implementation(AActor* Owner, UObject* Context) const
{
	AGymNPC* GymNPC = Cast<AGymNPC>(Owner);
	if (!GymNPC)
	{
		return 0;
	}

	return GymNPC->GetEnergyLevel();
}
