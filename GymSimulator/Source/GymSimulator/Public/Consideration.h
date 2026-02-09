// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Consideration.generated.h"

/**
 *
 */
UCLASS(Blueprintable, EditInlineNew, DefaultToInstanced)
class GYMSIMULATOR_API UConsideration : public UObject
{
	GENERATED_BODY()


public:
	UFUNCTION(BlueprintCallable, Category = "Utility AI")
	virtual float Score(AActor* Owner, UObject* Context) const;

protected:
	UFUNCTION(BlueprintNativeEvent, Category = "Utility AI")
	float CalculateScore(AActor* Owner, UObject* Context) const;
	virtual float CalculateScore_Implementation(AActor* Owner, UObject* Context) const;

	UPROPERTY(EditAnywhere, Category = "Utility AI")
	UCurveFloat* ResponseCurve;
};
