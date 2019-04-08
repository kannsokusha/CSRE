// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "Pistols.generated.h"

UENUM(BlueprintType)
enum PistolsState
{
	PistolsDraw,
	PistolsIdle,
	PistolsOnFire,
	PistolsWeaponSpecialFunction,
	PistolsReload
};

UCLASS()
class CSRE_API APistols : public AWeapon
{
	GENERATED_BODY()
	
public:

	// Sets default values for this actor's properties
	APistols();

	//开火
	UFUNCTION(BlueprintCallable, Category = Attack)
	void OnFire();

	//开火重写
	UFUNCTION(BlueprintImplementableEvent, Category = Attack)
	void OOnFire();

	//停止开火
	UFUNCTION(BlueprintCallable, Category = Attack)
	void StopFire();

	//停止开火重写
	UFUNCTION(BlueprintImplementableEvent, Category = Attack)
	void OStopFire();

	//鼠标右键，武器特殊功能
	UFUNCTION(BlueprintCallable, Category = Attack)
	void WeaponSpecialFunction();

	//鼠标右键，武器特殊功能
	UFUNCTION(BlueprintImplementableEvent, Category = Attack)
	void OWeaponSpecialFunction();

	//换弹
	UFUNCTION(BlueprintCallable, Category = Weapon)
	void Reload();

	//换弹重写
	UFUNCTION(BlueprintImplementableEvent, Category = Weapon)
	void OReload();

	//拾起&切换
	UFUNCTION(BlueprintCallable, Category = Weapon)
	void Pick();

	//拾起&切换重写
	UFUNCTION(BlueprintImplementableEvent, Category = Weapon)
	void OPick();

	//丢武器
	UFUNCTION(BlueprintCallable, Category = Weapon)
	void Drop();

	//丢武器重写
	UFUNCTION(BlueprintImplementableEvent, Category = Weapon)
	void ODrop();

	//得到备用子弹数
	UFUNCTION(BlueprintCallable, Category = Bullets)
	FORCEINLINE int GetSpareBullets() const { return spareBullets; }

	//得到当前弹夹子弹数
	UFUNCTION(BlueprintCallable, Category = Bullets)
	FORCEINLINE int GetBulletsOfClip() const { return bulletsOfClip; }

	//攻击伤害
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Damage)
	int attackDamage;

	//武器状态
	UFUNCTION(BlueprintCallable)
	FORCEINLINE PistolsState GetPistolsState() const { return currentState; }
	UFUNCTION(BlueprintCallable)
	void SetPistolsState(PistolsState newState);

	//备用子弹
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Bullet)
	int spareBullets;
	//当前弹夹子弹数
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Bullet)
	int bulletsOfClip;
	//弹夹容量
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Bullet)
	int clipSize;
	//武器状态
	PistolsState currentState = PistolsIdle;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
