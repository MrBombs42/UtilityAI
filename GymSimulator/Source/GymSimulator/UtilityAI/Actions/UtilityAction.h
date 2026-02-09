// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Consideration.h"
#include "UObject/NoExportTypes.h"
#include "UtilityAction.generated.h"

/**
 *
 */
UCLASS(Blueprintable, EditInlineNew, DefaultToInstanced)
class GYMSIMULATOR_API UUtilityAction : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Utility AI")
	FString ActionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Utility AI")
	TArray<UConsideration*> Considerations;

	UFUNCTION(BlueprintCallable, Category="Utility AI")
	float CalculateFinalScore(AActor* Owner, UObject* Context) const;

	UFUNCTION(BlueprintNativeEvent, Category="Utility AI")
	void Execute(AActor* Owner, UObject* Context);
	virtual void Execute_Implementation(AActor* Owner, UObject* Context);

	UFUNCTION(BlueprintNativeEvent, Category="Utility AI")
	void Stop(AActor* Owner);
	virtual void Stop_Implementation(AActor* Owner);

};
