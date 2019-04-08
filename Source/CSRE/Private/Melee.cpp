// Fill out your copyright notice in the Description page of Project Settings.

#include "Melee.h"
// Sets default values
AMelee::AMelee()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMelee::OnFire()
{
	if (currentState == MeleeIdle)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "LightAttack");
		SetMeleeState(LightAttack);
		OLightAttack();
	}
}

void AMelee::WeaponSpecialFunction()
{
	if (currentState == MeleeIdle)
	{
		SetMeleeState(HeavyAttack);
		OHeavyAttack();
	}
}

void AMelee::StopFire()
{
	if (currentState == LightAttack)
	{
		SetMeleeState(LightAttackStop);
		OStopFire();
	}
}

void AMelee::Reload()
{
}

void AMelee::Pick()
{
	SetMeleeState(MeleeDraw);
	OPick();
}

void AMelee::Drop()
{
}

//void AMelee::SetWeaponState(WeaponState newState)
//{
//	weaponState = newState;
//}

void AMelee::SetMeleeState(MeleeState newState)
{
	currentState = newState;
}

// Called when the game starts or when spawned
void AMelee::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMelee::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

