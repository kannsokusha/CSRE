// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class CSRE_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();
	//¿ª»ð
	virtual void OnFire();
	//Í£Ö¹¿ª»ð
	virtual void StopFire();
	//Êó±êÓÒ¼ü£¬ÎäÆ÷ÌØÊâ¹¦ÄÜ
	virtual void WeaponSpecialFunction();
	//»»µ¯
	virtual void Reload();
	//Ê°Æð&ÇÐ»»
	virtual void Pick();
	//¶ªÎäÆ÷
	virtual void Drop();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
