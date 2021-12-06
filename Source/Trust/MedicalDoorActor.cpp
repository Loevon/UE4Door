// Fill out your copyright notice in the Description page of Project Settings.


#include "AirlockDoorActor.h"
#include "Net/UnrealNetwork.h"
#include "Components/SkeletalMeshComponent.h"


AAirlockDoorActor::AAirlockDoorActor() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// setup lock materials
	LockedDoorMaterial = CreateDefaultSubobject<UMaterialInterface>(TEXT("Green_Glow"));
	UnlockedDoorMaterial = CreateDefaultSubobject<UMaterialInterface>(TEXT("Red_Glow"));
}

// Called when the game starts or when spawned
void AAirlockDoorActor::BeginPlay() {
	Super::BeginPlay();
	
	if (HasAuthority()) {
		SetReplicates(true);
	}

}

void AAirlockDoorActor::LockDoor() {
	if (HasAuthority()) {
		ServerLockDoor();
	}
}

void AAirlockDoorActor::UnlockDoor() {
	if (HasAuthority()) {
		MulticastUnlockDoor();
	}
}

// replication
void AAirlockDoorActor::MulticastLockDoor_Implementation() {
	SkeletalMesh->SetMaterial(0, LockedDoorMaterial);
}

void AAirlockDoorActor::MulticastUnlockDoor_Implementation() {
	SkeletalMesh->SetMaterial(0, UnlockedDoorMaterial);
}
