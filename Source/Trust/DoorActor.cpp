// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorActor.h"
#include "Net/UnrealNetwork.h"
#include "Components/SkeletalMeshComponent.h"
#include "Sound/SoundBase.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ADoorActor::ADoorActor() {
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	RootComponent = SkeletalMesh;

	// init locals
	isOpen = false;
}

// Called when the game starts or when spawned
void ADoorActor::BeginPlay() {
	Super::BeginPlay();

	if (HasAuthority()) {
		SetReplicates(true);
	}
}

void ADoorActor::LockDoor() {
	UE_LOG(LogTemp, Warning, TEXT("ADoorActor Lock Door"));
}

void ADoorActor::UnlockDoor() {
	UE_LOG(LogTemp, Warning, TEXT("ADoorActor Unlock Door"));
}

void ADoorActor::OpenDoor() {
	if (HasAuthority()) {
		isOpen = true;

		if (OpenDoorSoundCue != NULL) {
			MulticastPlayOpenDoorAudio();
		}
	}
}

void ADoorActor::CloseDoor() {
	if (HasAuthority()) {
		isOpen = false;

		if (OpenDoorSoundCue != nullptr) {
			MulticastPlayCloseDoorAudio();
		}
	}
}

bool ADoorActor::GetIsOpen() const {
	return isOpen;
}

// replication
void ADoorActor::GetLifetimeReplicatedProps(TArray< FLifetimeProperty > & OutLifetimeProps) const {
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ADoorActor, isOpen);
}

void ADoorActor::MulticastLockDoor_Implementation() {
	UE_LOG(LogTemp, Warning, TEXT("ADoorActor Multicast lock Door"));
}

void ADoorActor::MulticastUnlockDoor_Implementation() {
	UE_LOG(LogTemp, Warning, TEXT("ADoorActor Multicast unlock Door"));
}

bool ADoorActor::ServerLockDoor_Validate() {
	return true;
}

void ADoorActor::ServerLockDoor_Implementation() {
	MulticastLockDoor();
}

bool ADoorActor::ServerUnlockDoor_Validate() {
	return true;
}

void ADoorActor::ServerUnlockDoor_Implementation() {
	MulticastUnlockDoor();
}

// TODO: Implement these sounds based on the door's child class, but have parent defaults here
void ADoorActor::MulticastPlayOpenDoorAudio_Implementation() {
	UGameplayStatics::PlaySoundAtLocation(this, OpenDoorSoundCue, this->GetActorLocation(), 1.f, 1.f, 0.f, SoundAttenuation, nullptr);
}

void ADoorActor::MulticastPlayCloseDoorAudio_Implementation() {
	UGameplayStatics::PlaySoundAtLocation(this, CloseDoorSoundCue, this->GetActorLocation(), 1.f, 1.f, 0.f, SoundAttenuation, nullptr);
}