// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/AudioComponent.h"
#include "DoorActor.generated.h"

UCLASS()
class TRUST_API ADoorActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoorActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UFUNCTION()
	bool GetIsOpen() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent *SkeletalMesh;

	UFUNCTION()
	virtual void LockDoor();

	UFUNCTION()
	virtual void UnlockDoor();

	UFUNCTION()
	void OpenDoor();

	UFUNCTION()
	void CloseDoor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* OpenDoorSoundCue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundBase* CloseDoorSoundCue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Audio)
	class USoundCue* OpenDoorCue;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Audio)
	class USoundAttenuation* SoundAttenuation;

protected:
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadWrite)
	bool isOpen;

	UFUNCTION(NetMulticast, Reliable)
	void MulticastPlayOpenDoorAudio();
	virtual void MulticastPlayOpenDoorAudio_Implementation();

	UFUNCTION(NetMulticast, Reliable)
	void MulticastPlayCloseDoorAudio();
	virtual void MulticastPlayCloseDoorAudio_Implementation();

	UFUNCTION(NetMulticast, Reliable)
	void MulticastLockDoor();
	virtual void MulticastLockDoor_Implementation();

	UFUNCTION(NetMulticast, Reliable)
	void MulticastUnlockDoor();
	virtual void MulticastUnlockDoor_Implementation();

	// Used for materials
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerLockDoor();
	bool ServerLockDoor_Validate();
	void ServerLockDoor_Implementation();

	// Used for materials
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerUnlockDoor();
	bool ServerUnlockDoor_Validate();
	void ServerUnlockDoor_Implementation();
};
