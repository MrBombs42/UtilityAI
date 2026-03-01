// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UtilityAI/Considerations/Base/ConsiderationBase.h"
#include "CurveConsideration.generated.h"

UCLASS(Abstract)
class GYMSIMULATOR_API UCurveConsideration : public UConsiderationBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category = "🧠 Consideration")
	UCurveFloat* ResponseCurve;

	virtual float Score(AActor* Owner, UObject* Context) const override;
};
