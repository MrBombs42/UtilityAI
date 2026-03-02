// Fill out your copyright notice in the Description page of Project Settings.


#include "UtilityAI/Actions/WorkOutAction.h"

#include "Chaos/PBDSuspensionConstraintData.h"
#include "NPC/GymNPC.h"

UWorkOutAction::UWorkOutAction()
{
	ActionName = "Work Out";

}

void UWorkOutAction::Execute_Implementation(AActor* Owner, UObject* Context)
{
	Super::Execute_Implementation(Owner, Context);

	AGymNPC* NPC = Cast<AGymNPC>(Owner);

	if (!NPC)
	{
		return;
	}

	CurrentOwner = NPC;

	const UWorld* World = NPC->GetWorld();
	if (!World)
	{
		return;
	}

	World->GetTimerManager().SetTimer(
		TimerHandle,
		this,
		&UWorkOutAction::DecreaseEnergy,
		1.f,
		true
		);

	UE_LOG(LogTemp, Log, TEXT("%s started work out"), *NPC->GetName());
}

void UWorkOutAction::Stop_Implementation(AActor* Owner)
{
	Super::Stop_Implementation(Owner);
	const UWorld* World = Owner->GetWorld();
	if (!World)
	{
		return;
	}

	World->GetTimerManager().ClearTimer((TimerHandle));
	UE_LOG(LogTemp, Warning, TEXT("STOP WorkOut"))
	CurrentOwner.Reset();
}

void UWorkOutAction::DecreaseEnergy()
{
	if (CurrentOwner.IsValid())
	{
		CurrentOwner->ModifyEnergy(-EnergyDecreaseRate);
		UE_LOG(LogTemp, Warning, TEXT("WorkOutAction::Execute_Implementation"));
	}
	else
	{
		// NPC foi destruído, para o timer
		UE_LOG(LogTemp, Warning, TEXT("NPC was destroyed, stopping workout timer"));
	}
}

