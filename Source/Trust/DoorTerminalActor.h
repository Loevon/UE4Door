// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "DoorTerminalActor.generated.h"

UCLASS()
class TRUST_API ADoorTerminalActor : public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADoorTerminalActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent *Mesh;

	UPROPERTY(EditAnywhere, Category = "Terminal Colors")
	class UMaterialInterface *ActiveTerminalMaterial;

	UPROPERTY(EditAnywhere, Category = "Terminal Colors")
	class UMaterialInterface *InactiveTerminalMaterial;

	UPROPERTY(EditAnywhere, Category = "Terminal Colors")
	class UMaterialInterface *HackedTermialMaterial;

	/* Replace me with an object inhereted by an interface */
	UPROPERTY(EditAnywhere, Category = "Interactable Object")
	class ADoorActor *Door;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Interaction")
	void Interaction();
	virtual void Interaction_Implementation() override;

private:
	// TODO
	UFUNCTION()
	void OpenDoor();

	UFUNCTION()
	void CloseDoor();
	UFUNCTION()
	void ToggleDoorOpenClosedState();

	void HackDoor();
	void LockDoor();
	void UnlockDoor();
};
