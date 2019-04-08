// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.h"
#include "Rifles.generated.h"

UENUM(BlueprintType)
enum RiflesState
{
	RiflesDraw,
	RiflesIdle,
	RiflesOnFire,
	RiflesStopFire,
	RiflesWeaponSpecialFunction,
	RiflesReload
};

UCLASS()
class CSRE_API ARifles : public AWeapon
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARifles();

	//����
	UFUNCTION(BlueprintCallable, Category = Attack)
	void OnFire();

	//������д
	UFUNCTION(BlueprintImplementableEvent, Category = Attack)
	void OOnFire();

	//ֹͣ����
	UFUNCTION(BlueprintCallable, Category = Attack)
	void StopFire();

	//ֹͣ������д
	UFUNCTION(BlueprintImplementableEvent, Category = Attack)
	void OStopFire();

	//����Ҽ����������⹦��
	UFUNCTION(BlueprintCallable, Category = Attack)
	void WeaponSpecialFunction();

	//����Ҽ����������⹦��
	UFUNCTION(BlueprintImplementableEvent, Category = Attack)
	void OWeaponSpecialFunction();

	//����
	UFUNCTION(BlueprintCallable, Category = Weapon)
	void Reload();

	//������д
	UFUNCTION(BlueprintImplementableEvent, Category = Weapon)
	void OReload();

	//ʰ��&�л�
	UFUNCTION(BlueprintCallable, Category = Weapon)
	void Pick();

	//ʰ��&�л���д
	UFUNCTION(BlueprintImplementableEvent, Category = Weapon)
	void OPick();

	//������
	UFUNCTION(BlueprintCallable, Category = Weapon)
	void Drop();

	//��������д
	UFUNCTION(BlueprintImplementableEvent, Category = Weapon)
	void ODrop();

	//��������
	UFUNCTION(BlueprintCallable, Category = Bullets)
	void Reloaded();

	//�õ������ӵ���
	UFUNCTION(BlueprintCallable, Category = Bullets)
	FORCEINLINE int GetSpareBullets() const { return spareBullets; }

	//�õ���ǰ�����ӵ���
	UFUNCTION(BlueprintCallable, Category = Bullets)
	FORCEINLINE int GetBulletsOfClip() const { return bulletsOfClip; }

	//�����˺�
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Damage)
	int attackDamage;

	//����״̬
	UFUNCTION(BlueprintCallable)
	FORCEINLINE RiflesState GetRiflesState() const { return currentState; }
	UFUNCTION(BlueprintCallable)
	void SetRiflesState(RiflesState newState);

	//�����ӵ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Bullet)
	int spareBullets;
	//��ǰ�����ӵ���
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Bullet)
	int bulletsOfClip;
	//��������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Bullet)
	int clipSize;
	//����״̬
	RiflesState currentState = RiflesIdle;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
