// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DoorActor.h"
#include "AirlockDoorActor.generated.h"

UCLASS()
class TRUST_API AAirlockDoorActor : public ADoorActor {
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AAirlockDoorActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere)
	class UMaterialInterface *LockedDoorMaterial;

	UPROPERTY(EditAnywhere)
	class UMaterialInterface *UnlockedDoorMaterial;

	void LockDoor();

	void UnlockDoor();

protected:
	void MulticastLockDoor_Implementation();
	void MulticastUnlockDoor_Implementation();
};
