// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NPC/GymNPC.h"
#include "UtilityAI/Actions/UtilityAction.h"
#include "WorkOutAction.generated.h"


UCLASS()
class GYMSIMULATOR_API UWorkOutAction : public UUtilityAction
{
	GENERATED_BODY()

public:
	UWorkOutAction();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "🎬 Action")
	float EnergyDecreaseRate;

protected:
	virtual void Execute_Implementation(AActor* Owner, UObject* Context) override;
	virtual void Stop_Implementation(AActor* Owner) override;

private:
	FTimerHandle TimerHandle;

	TWeakObjectPtr<AGymNPC> CurrentOwner;

	UFUNCTION()
	void DecreaseEnergy();
};
