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

	//�ṥ��
	UFUNCTION(BlueprintCallable, Category = Attack)
	void OnFire();

	//�ع���
	UFUNCTION(BlueprintCallable, Category = Attack)
	void WeaponSpecialFunction();

	//�ṥ����д
	UFUNCTION(BlueprintImplementableEvent, Category = Attack)
	void OLightAttack();

	//�ع�����д
	UFUNCTION(BlueprintImplementableEvent, Category = Attack)
	void OHeavyAttack();

	//ֹͣ����
	UFUNCTION(BlueprintCallable, Category = Attack)
	void StopFire();

	//ֹͣ������д
	UFUNCTION(BlueprintImplementableEvent, Category = Attack)
	void OStopFire();

	//����
	UFUNCTION(BlueprintCallable, Category = Weapon)
	void Reload();

	//ʰ��&�л�
	UFUNCTION(BlueprintCallable, Category = Weapon)
	void Pick();

	//ʰ��&�л���д
	UFUNCTION(BlueprintImplementableEvent, Category = Weapon)
	void OPick();

	//������
	UFUNCTION(BlueprintCallable, Category = Weapon)
	void Drop();

	//�ṥ���˺�
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Damage)
	int lightAttackDamage;

	//�ع����˺�
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Damage)
	int heavyAttackDamage;

	//��������
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Damage)
	int attackDistance;

	//����״̬
	UFUNCTION(BlueprintCallable)
	FORCEINLINE MeleeState GetMeleeState() { return currentState; }
	UFUNCTION(BlueprintCallable)
	void SetMeleeState(MeleeState newState);

private:
	//����״̬
	MeleeState currentState = MeleeIdle;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
