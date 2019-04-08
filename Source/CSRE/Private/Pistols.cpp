// Fill out your copyright notice in the Description page of Project Settings.

#include "Pistols.h"

// Sets default values
APistols::APistols()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void APistols::OnFire()
{
	if (currentState == PistolsIdle)
	{
		SetPistolsState(PistolsOnFire);
		OOnFire();
	}
}

void APistols::StopFire()
{

}

void APistols::WeaponSpecialFunction()
{
	if (currentState == PistolsIdle)
	{
		SetPistolsState(PistolsWeaponSpecialFunction);
		OWeaponSpecialFunction();
	}
}

void APistols::Reload()
{
	if (currentState == PistolsIdle)
	{
		SetPistolsState(PistolsReload);
		OReload();
	}
}

void APistols::Pick()
{
	SetPistolsState(PistolsDraw);
	OPick();
}

void APistols::Drop()
{
	ODrop();
}

void APistols::SetPistolsState(PistolsState newState)
{
	currentState = newState;
}

// Called when the game starts or when spawned
void APistols::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APistols::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}