// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"


UCLASS()
class PROJECT_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

	APlayerCharacter(const FObjectInitializer& ObjectInitializer);

	/* First Person Camera */
	UPROPERTY(VisibleAnywhere, Category = Camera)
	UCameraComponent*  FirstPersonCameraComponent;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	USkeletalMeshComponent* FirstPersonMesh;

	/** Gun mesh: 1st person view (seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USkeletalMeshComponent* WeaponMesh;


public:
	// Sets default values for this character's properties
	APlayerCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	//handles moving forward/backward
	UFUNCTION()
		void MoveForward(float Val);

	//handles strafing
	UFUNCTION()
		void MoveRight(float Val);

	//sets jump flag when key is pressed
	UFUNCTION()
		void OnStartJump();

	//clears jump flag when key is released
	UFUNCTION()
		void OnStopJump();

	UFUNCTION()
		void FireWeapon();
	
	//Gun Muzzle offset from characters location
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector GunOffset;

	//Projectile Class to Spawn
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
		TSubclassOf<class AWeaponProjectile> ProjectileClass;

	//Sound to play each time we fire
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class USoundBase* FireSound;

	//AnimMontage to play each time we fire
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		class UAnimMontage* FireAnimation;

	//Returns FirstPersonMesh subobject
	FORCEINLINE class USkeletalMeshComponent* GetFirstPersonMesh() const { return FirstPersonMesh; }
	//Returns FirstPersonCameraComponent subobject
	FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }
};