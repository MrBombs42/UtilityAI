// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Consideration.h"
#include "GenericPropertyConsideration.generated.h"

UENUM(BlueprintType)
enum class EComparisonOperator : uint8
{
	GreaterThan			UMETA(DisplayName = ">"),
	GreaterOrEqual		UMETA(DisplayName = ">="),
	LessThan			UMETA(DisplayName = "<"),
	LessOrEqual			UMETA(DisplayName = "<="),
	Equal				UMETA(DisplayName = "=="),
	NotEqual			UMETA(DisplayName = "!="),
};



UCLASS(Blueprintable, EditInlineNew, DefaultToInstanced)
class GYMSIMULATOR_API UGenericPropertyConsideration : public UConsideration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "🧠 Consideration")
	FName PropertyName;

	UPROPERTY(EditAnywhere, Category = "🧠 Consideration")
	EComparisonOperator Operator;

	UPROPERTY(EditAnywhere, Category = "🧠 Consideration")
	float ComparisonValue;

protected:
	virtual float CalculateScore_Implementation(AActor* Owner, UObject* Context) const override;


private:
	mutable FProperty* CachedProperty;

	mutable UClass* CachedOwnerClass;

	float GetPropertyValue(AActor* Owner) const;

	bool EvaluateComparison(float Value) const;
};
