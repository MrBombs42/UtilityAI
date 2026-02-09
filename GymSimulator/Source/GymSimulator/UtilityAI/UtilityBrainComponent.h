// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actions/UtilityAction.h"
#include "Components/ActorComponent.h"
#include "UtilityBrainComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GYMSIMULATOR_API UUtilityBrainComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UUtilityBrainComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, Instanced, Category = "Utility AI")
	TArray<UUtilityAction*> AvailableActions;

	UPROPERTY(EditAnywhere, Category = "Utility AI")
	float DecisionInterval;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Utility AI")
	UObject* Context;

private:
	UPROPERTY()
	UUtilityAction* CurrentAction;

	float DecisionTimer;

	UUtilityAction* ChooseBestAction();

	void ExecuteAction(UUtilityAction* Action);
};
