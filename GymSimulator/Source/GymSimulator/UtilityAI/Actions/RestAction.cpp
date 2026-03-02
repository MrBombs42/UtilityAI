// Fill out your copyright notice in the Description page of Project Settings.


#include "UtilityAI/Actions/RestAction.h"

#include "NPC/GymNPC.h"

URestAction::URestAction()
{
	ActionName = "Rest";
	EnergyRecoveryRate = 0.2f;
}

void URestAction::Execute_Implementation(AActor* Owner, UObject* Context)
{
	Super::Execute_Implementation(Owner, Context);

	AGymNPC* GymNPC = Cast<AGymNPC>(Owner);
	if (!GymNPC)
	{
		return;
	}

	CurrentOwner = GymNPC;

	const UWorld* World = GymNPC->GetWorld();
	if (!World)
	{
		UE_LOG(LogTemp, Error, TEXT("World is null!"));
		return;
	}

	World->GetTimerManager().SetTimer(
		RecoveryTimerHandle,
		this,
		&URestAction::RecoverEnergy,
		1.0f,
		true
	);

	UE_LOG(LogTemp, Log, TEXT("%s started resting"), *GymNPC->GetName());
}

void URestAction::Stop_Implementation(AActor* Owner)
{
	Super::Stop_Implementation(Owner);

	const UWorld* World = Owner->GetWorld();
	if (!World)
	{
		UE_LOG(LogTemp, Error, TEXT("World is null!"));
		return;
	}
	World->GetTimerManager().ClearTimer(RecoveryTimerHandle);
	UE_LOG(LogTemp, Log, TEXT("%s stopped resting"), *Owner->GetName());

	CurrentOwner.Reset();

}

void URestAction::RecoverEnergy()
{
	if (!CurrentOwner.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("CurrentOwner is invalid!"));
		return;
	}

	CurrentOwner->ModifyEnergy(EnergyRecoveryRate);
	UE_LOG(LogTemp, Warning, TEXT("%s recovering energy: %.2f"),
		*CurrentOwner->GetName(),
		CurrentOwner->GetEnergyLevel());
}
