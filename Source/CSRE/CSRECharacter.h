// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Public/Melee.h"
#include "Public/Rifles.h"
#include "Public/Pistols.h"
#include "CSRECharacter.generated.h"

UENUM(BlueprintType)
enum CharacterState
{
	Idle,
	Run,
	CrouchRun,
	CrouchIdle
};

UENUM(BlueprintType)
enum WeaponType
{
	Melee,
	Pistols,
	Rifles,
	Grenades
};


class UInputComponent;

UCLASS(config=Game)
class ACSRECharacter : public ACharacter
{
	GENERATED_BODY()

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FirstPersonCameraComponent;

	/** Motion controller (right hand) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UMotionControllerComponent* R_MotionController;

	/** Motion controller (left hand) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UMotionControllerComponent* L_MotionController;

public:
	ACSRECharacter();

protected:
	virtual void BeginPlay();

public:
	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	FVector GunOffset;

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category=Projectile)
	TSubclassOf<class ACSREProjectile> ProjectileClass;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
	class USoundBase* FireSound;

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class UAnimMontage* FireAnimation;

	/** Whether to use motion controller location for aiming. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	uint32 bUsingMotionControllers : 1;
	
	//近战武器
	UPROPERTY(BlueprintReadWrite, Category = Weapons)
	AMelee* meleeWeapon;
	//主武器
	UPROPERTY(BlueprintReadWrite, Category = Weapons)
	ARifles* riflesWeapon;
	//副武器
	UPROPERTY(BlueprintReadWrite, Category = Weapons)
	APistols* pistolsWeapon;
	//近战武器
	//UPROPERTY(BlueprintReadWrite, Category = Mesh)
	//AMelee* meleeWeapon;
	//当前武器
	UPROPERTY(BlueprintReadWrite, Category = Weapons)
	AWeapon* currentWeapon;
	//当前状态
	//UPROPERTY(BlueprintReadWrite, Category = State)
	//CharacterState currentState;
	//切换武器
	UFUNCTION(BlueprintImplementableEvent)
	void OChangeWeapon();

private:
	//当前状态
	CharacterState currentState;
	//当前武器类型
	WeaponType currentWeaponType = Melee;
protected:
	
	/** Fires a projectile. */
	void OnFire();

	/** Fires a projectile. */
	void StopFire();

	//鼠标右键，武器特殊功能
	void WeaponSpecialFunction();

	//换弹
	void Reload();

	//上一个武器
	void PreviousWeapon();

	//下一个武器
	void NextWeapon();

	/** Resets HMD orientation and position in VR. */
	void OnResetVR();

	/** Handles moving forward/backward */
	void MoveForward(float Val);

	/** Handles stafing movement, left and right */
	void MoveRight(float Val);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);

	struct TouchData
	{
		TouchData() { bIsPressed = false;Location=FVector::ZeroVector;}
		bool bIsPressed;
		ETouchIndex::Type FingerIndex;
		FVector Location;
		bool bMoved;
	};
	void BeginTouch(const ETouchIndex::Type FingerIndex, const FVector Location);
	void EndTouch(const ETouchIndex::Type FingerIndex, const FVector Location);
	void TouchUpdate(const ETouchIndex::Type FingerIndex, const FVector Location);
	TouchData	TouchItem;
	
protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;
	// End of APawn interface

	/* 
	 * Configures input for touchscreen devices if there is a valid touch interface for doing so 
	 *
	 * @param	InputComponent	The input component pointer to bind controls to
	 * @returns true if touch controls were enabled.
	 */
	bool EnableTouchscreenMovement(UInputComponent* InputComponent);

public:
	/** Returns Mesh1P subobject **/
	//FORCEINLINE class USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	/** Returns FirstPersonCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }
	UFUNCTION(BlueprintCallable)
	FORCEINLINE CharacterState GetCurrentState() const { return currentState; }
	void SetCurrentState(CharacterState newState);
	UFUNCTION(BlueprintCallable)
	FORCEINLINE WeaponType GetCurrentWeaponType() const { return currentWeaponType; }
	void SetCurrentWeaponType(WeaponType newWeaponType);
};

