// Fill out your copyright notice in the Description page of Project Settings.


#include "UtilityAI/UtilityBrainComponent.h"

#include "Actions/UtilityAction.h"

// Sets default values for this component's properties
UUtilityBrainComponent::UUtilityBrainComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	DecisionInterval = 1.0f;
	DecisionTimer = 0.0f;
	CurrentAction = nullptr;
	Context = nullptr;
}


// Called when the game starts
void UUtilityBrainComponent::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("=== UtilityBrain BeginPlay ==="));
	UE_LOG(LogTemp, Warning, TEXT("Available Actions: %d"), AvailableActions.Num());

	UUtilityAction* BestAction = ChooseBestAction();
	if (BestAction != nullptr)
	{
		ExecuteAction(BestAction);
	}

}


// Called every frame
void UUtilityBrainComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	DecisionTimer += DeltaTime;

	if (DecisionTimer >= DecisionInterval)
	{
		DecisionTimer = 0.0f;

		UUtilityAction* BestAction = ChooseBestAction();

		if (BestAction && CurrentAction != BestAction)
		{
			ExecuteAction(BestAction);
		}
	}
}

UUtilityAction* UUtilityBrainComponent::ChooseBestAction()
{

	if (AvailableActions.Num() == 0)
	{
		return nullptr;
	}

	// podia estar cacheado
	AActor* Owner = GetOwner();
	if (Owner == nullptr)
	{
		return nullptr;
	}

	UUtilityAction* BestAction = nullptr;
	float BestScore = -1.0f;
	for (UUtilityAction* Action : AvailableActions)
	{
		if (Action == nullptr)
		{
			continue;
		}

		float Score = Action->CalculateFinalScore(Owner, Context);
		if (Score > BestScore)
		{
			BestScore = Score;
			BestAction = Action;
		}
	}

	return BestAction;
}

void UUtilityBrainComponent::ExecuteAction(UUtilityAction* Action)
{
	AActor* Owner = GetOwner();
	if (Action == nullptr || Owner == nullptr)
	{
		return;
	}

	if (CurrentAction)
	{
		CurrentAction->Stop(Owner);
	}

	CurrentAction = Action;
	CurrentAction->Execute(Owner, Context);

	UE_LOG(LogTemp, Warning, TEXT(">>> Executing action: %s (Score: High)"), *CurrentAction->ActionName);
}

