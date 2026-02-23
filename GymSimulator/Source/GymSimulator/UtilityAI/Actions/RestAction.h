// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UtilityAI/Actions/UtilityAction.h"
#include "RestAction.generated.h"

/**
 *
 */
UCLASS()
class GYMSIMULATOR_API URestAction : public UUtilityAction
{
	GENERATED_BODY()


public:
	URestAction();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "🎬 Action")
	float EnergyRecoveryRate;

protected:
	virtual void Execute_Implementation(AActor* Owner, UObject* Context) override;
	virtual void Stop_Implementation(AActor* Owner) override;

private:
	FTimerHandle RecoveryTimerHandle;

	TWeakObjectPtr<AActor> CurrentOwner;

	UFUNCTION()
	void RecoverEnergy();
};
