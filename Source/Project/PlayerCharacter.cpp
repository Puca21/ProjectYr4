// Fill out your copyright notice in the Description page of Project Settings.

#include "Project.h"
#include "PlayerCharacter.h"
#include "WeaponProjectile.h"
#include "Animation/AnimInstance.h"
#include "GameFramework/InputSettings.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("\n\nPlayer Character"));
	}

}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

APlayerCharacter::APlayerCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

	//set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	//Create a CameraComponent 
	FirstPersonCameraComponent = ObjectInitializer.CreateDefaultSubobject<UCameraComponent>(this, TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->AttachParent = GetCapsuleComponent();
	//Position the camera
	FirstPersonCameraComponent->RelativeLocation = FVector(0, 0, 64.f);
	//Allow the pawn to control rotation.
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	//Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	FirstPersonMesh = ObjectInitializer.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("FirstPersonMesh"));
	FirstPersonMesh->SetOnlyOwnerSee(true);         //only the owning player will see this mesh
	FirstPersonMesh->AttachParent = FirstPersonCameraComponent;
	FirstPersonMesh->bCastDynamicShadow = false;
	FirstPersonMesh->CastShadow = false;

	//Gun Mesh Component
	WeaponMesh = ObjectInitializer.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("WeaponMesh"));
	WeaponMesh->SetOnlyOwnerSee(true);
	WeaponMesh->bCastDynamicShadow = false;
	WeaponMesh->CastShadow = false;
	WeaponMesh->AttachTo(FirstPersonMesh, TEXT("WeaponPoint"), EAttachLocation::SnapToTargetIncludingScale, true);

	//Default offset from the character location for the projectiles to spawn
	GunOffset = FVector(100.f, 30.f, 10.f);

}


//Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);

	InputComponent->BindAxis("Turn", this, &APlayerCharacter::AddControllerYawInput);
	InputComponent->BindAxis("LookUp", this, &APlayerCharacter::AddControllerPitchInput);

	InputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::OnStartJump);
	InputComponent->BindAction("Jump", IE_Released, this, &APlayerCharacter::OnStopJump);

	InputComponent->BindAction("Fire", IE_Pressed, this, &APlayerCharacter::FireWeapon);




}

void APlayerCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
		{
			FRotator Rotation = Controller->GetControlRotation();

			if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling())
				{
					Rotation.Pitch = 0.0f;
				}

			const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
			AddMovementInput(Direction, Value);
		}

}

void APlayerCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);

		AddMovementInput(Direction, Value);
	}

}

void APlayerCharacter::OnStartJump()
{
	bPressedJump = true;
}

void APlayerCharacter::OnStopJump()
{
	bPressedJump = false;
}

void APlayerCharacter::FireWeapon()
{
	//try and fire a projectile
	if (ProjectileClass != NULL)
	{
		const FRotator SpawnRotation = GetControlRotation();
		//MuzzleOffSet is in camera space, so transform it to world space before offsetting from character location to find the muzzle position
		const FVector SpawnLocation = GetActorLocation() + SpawnRotation.RotateVector(GunOffset);

		UWorld* const World = GetWorld();
		if (World != NULL)
		{
			//spawn the projectile at the muzzle
			World->SpawnActor<AWeaponProjectile>(ProjectileClass, SpawnLocation, SpawnRotation);
		}
	}

	//try and play the sound if specified
	if (FireSound != NULL)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	}

	//try and play a firing animation if specified
	if (FireAnimation != NULL)
	{
		//Get the animation object for the arms mesh
		UAnimInstance* AnimInstance = FirstPersonMesh->GetAnimInstance();
		if (AnimInstance != NULL)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}
}