// Fill out your copyright notice in the Description page of Project Settings.


#include "UtilityAI/Considerations/GenericPropertyConsideration.h"

float UGenericPropertyConsideration::CalculateScore_Implementation(AActor* Owner, UObject* Context) const
{
	if (!Owner)
	{
		return 0;
	}

	float PropertyValue = GetPropertyValue(Owner);

	bool Result = EvaluateComparison(PropertyValue);

	return Result ? 1.f : 0.f;
}

float UGenericPropertyConsideration::GetPropertyValue(AActor* Owner) const
{
	if (!Owner)
	{
		return 0.f;
	}

	UClass* OwnerClass = Owner->GetClass();

	if (CachedOwnerClass != OwnerClass)
	{
		CachedOwnerClass = OwnerClass;
		CachedProperty = OwnerClass->FindPropertyByName(PropertyName);

		if (!CachedProperty)
		{
			UE_LOG(LogTemp, Error, TEXT("Property %s not found"), *PropertyName.ToString());
		}
	}

	if (!CachedProperty)
	{
		return 0.f;
	}

	if (FFloatProperty* FloatProp = CastField<FFloatProperty>(CachedProperty))
	{
		return FloatProp->GetPropertyValue_InContainer(Owner);
	}

	if (FIntProperty* IntProp = CastField<FIntProperty>(CachedProperty))
	{
		return IntProp->GetPropertyValue_InContainer(Owner);
	}

	UE_LOG(LogTemp, Error, TEXT("Property %s not float or int"), *PropertyName.ToString());

	return 0.f;
}

bool UGenericPropertyConsideration::EvaluateComparison(float Value) const
{

	switch(Operator)
	{
		case EComparisonOperator::GreaterThan:
			return Value > ComparisonValue;
		case EComparisonOperator::GreaterOrEqual:
			return Value >= ComparisonValue;
		case EComparisonOperator::LessThan:
			return Value < ComparisonValue;
		case EComparisonOperator::LessOrEqual:
			return Value <= ComparisonValue;
		case EComparisonOperator::Equal:
			return FMath::IsNearlyEqual(Value, ComparisonValue, 0.01f);
		case EComparisonOperator::NotEqual:
			return !FMath::IsNearlyEqual(Value, ComparisonValue, 0.01f);
		default:
			return false;
	}
}
