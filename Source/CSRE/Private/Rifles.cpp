// Fill out your copyright notice in the Description page of Project Settings.

#include "Rifles.h"
#include "Engine.h"

// Sets default values
ARifles::ARifles()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ARifles::OnFire()
{
	if (currentState == RiflesIdle)
	{
		if (bulletsOfClip > 0)
		{
			SetRiflesState(RiflesOnFire);
			OOnFire();
		}
		else
		{
			Reload();
		}
	}
}

void ARifles::StopFire()
{
	if (currentState == RiflesOnFire)
	{
		SetRiflesState(RiflesStopFire);
		OStopFire();
	}
}

void ARifles::WeaponSpecialFunction()
{
	if (currentState == RiflesIdle)
	{
		SetRiflesState(RiflesWeaponSpecialFunction);
		OWeaponSpecialFunction();
	}
}

void ARifles::Reload()
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "Reload??");
	if (currentState == RiflesIdle && spareBullets > 0 && bulletsOfClip < clipSize)//有备用子弹，弹夹不满的时候允许换弹
	{
		SetRiflesState(RiflesReload);
		OReload();
	}
}

void ARifles::Pick()
{
	SetRiflesState(RiflesDraw);
	OPick();
}

void ARifles::Drop()
{
	ODrop();
}

void ARifles::Reloaded()
{
	int temp = bulletsOfClip + spareBullets;//总子弹
	bulletsOfClip = clipSize;
	spareBullets = temp - bulletsOfClip;
}

void ARifles::SetRiflesState(RiflesState newState)
{
	currentState = newState;
}

// Called when the game starts or when spawned
void ARifles::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARifles::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

