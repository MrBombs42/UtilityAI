// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GymNPC.generated.h"

UCLASS()
class GYMSIMULATOR_API AGymNPC : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGymNPC();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float EnergyLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stats", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float HungerLevel;

	UFUNCTION(Blueprintable, Category= "Stats")
	float GetEnergyLevel() const {return EnergyLevel;};

	UFUNCTION(Blueprintable, Category= "Stats")
	float GetHungerLevel() const {return HungerLevel;};

	UFUNCTION(Blueprintable, Category= "Stats")
	void ModifyEnergy(float Amount);

	UFUNCTION(Blueprintable, Category= "Stats")
	void ModifyHunger(float Amount);
};
