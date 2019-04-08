// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine.h"
#include "Weapon.h"
#include "Melee.generated.h"

UENUM(BlueprintType)
enum MeleeState
{
	MeleeDraw,
	MeleeIdle,
	LightAttack,
	LightAttackStop,
	HeavyAttack,
};

UCLASS()
class CSRE_API AMelee : public AWeapon
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMelee();

	//Çá¹¥»÷
	UFUNCTION(BlueprintCallable, Category = Attack)
	void OnFire();

	//ÖØ¹¥»÷
	UFUNCTION(BlueprintCallable, Category = Attack)
	void WeaponSpecialFunction();

	//Çá¹¥»÷ÖØÐ´
	UFUNCTION(BlueprintImplementableEvent, Category = Attack)
	void OLightAttack();

	//ÖØ¹¥»÷ÖØÐ´
	UFUNCTION(BlueprintImplementableEvent, Category = Attack)
	void OHeavyAttack();

	//Í£Ö¹¿ª»ð
	UFUNCTION(BlueprintCallable, Category = Attack)
	void StopFire();

	//Í£Ö¹¿ª»ðÖØÐ´
	UFUNCTION(BlueprintImplementableEvent, Category = Attack)
	void OStopFire();

	//»»µ¯
	UFUNCTION(BlueprintCallable, Category = Weapon)
	void Reload();

	//Ê°Æð&ÇÐ»»
	UFUNCTION(BlueprintCallable, Category = Weapon)
	void Pick();

	//Ê°Æð&ÇÐ»»ÖØÐ´
	UFUNCTION(BlueprintImplementableEvent, Category = Weapon)
	void OPick();

	//¶ªÎäÆ÷
	UFUNCTION(BlueprintCallable, Category = Weapon)
	void Drop();

	//Çá¹¥»÷ÉËº¦
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Damage)
	int lightAttackDamage;

	//ÖØ¹¥»÷ÉËº¦
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Damage)
	int heavyAttackDamage;

	//¹¥»÷¾àÀë
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Damage)
	int attackDistance;

	//ÎäÆ÷×´Ì¬
	UFUNCTION(BlueprintCallable)
	FORCEINLINE MeleeState GetMeleeState() { return currentState; }
	UFUNCTION(BlueprintCallable)
	void SetMeleeState(MeleeState newState);

private:
	//ÎäÆ÷×´Ì¬
	MeleeState currentState = MeleeIdle;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
