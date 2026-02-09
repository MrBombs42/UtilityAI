// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC/GymNPC.h"

// Sets default values
AGymNPC::AGymNPC()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	EnergyLevel = 1.0f;
	HungerLevel = 0.0f;
}

// Called when the game starts or when spawned
void AGymNPC::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AGymNPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ModifyEnergy(-0.01f * DeltaTime);
	ModifyHunger(0.005f * DeltaTime);

}

// Called to bind functionality to input
void AGymNPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AGymNPC::ModifyEnergy(float Amount)
{
	EnergyLevel = FMath::Clamp(EnergyLevel + Amount, 0.0f, 1.0f);
}

void AGymNPC::ModifyHunger(float Amount)
{
	HungerLevel = FMath::Clamp(Amount, 0.0f, 1.0f);
}

