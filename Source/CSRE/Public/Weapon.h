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
	//����
	virtual void OnFire();
	//ֹͣ����
	virtual void StopFire();
	//����Ҽ����������⹦��
	virtual void WeaponSpecialFunction();
	//����
	virtual void Reload();
	//ʰ��&�л�
	virtual void Pick();
	//������
	virtual void Drop();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
