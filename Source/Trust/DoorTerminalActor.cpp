// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorTerminalActor.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "DoorActor.h"

// Sets default values
ADoorTerminalActor::ADoorTerminalActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// initalize terminal mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SkeletalMesh"));
	RootComponent = Mesh;

	// init reference to the door being opened
	Door = CreateDefaultSubobject<ADoorActor>(TEXT("Door"));
}

// Called when the game starts or when spawned
void ADoorTerminalActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ADoorTerminalActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// interactable interface
void ADoorTerminalActor::Interaction_Implementation() {
	// UE_LOG(LogTemp, Warning, TEXT("Terminal Interacted with!"));
	ToggleDoorOpenClosedState();
}

void ADoorTerminalActor::OpenDoor() {
	if (Door) {
		Door->OpenDoor(); // isOpen = true;
	}
}

void ADoorTerminalActor::CloseDoor() {
	if (Door) {
		Door->CloseDoor();
	}
}

void ADoorTerminalActor::ToggleDoorOpenClosedState() {
	if (Door) {
		
		if (Door->GetIsOpen() == true) {
			Door->CloseDoor();
		}
		else {
			Door->OpenDoor();
		}
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("WARNING: No door is connected to this terminal: %s."), *this->GetName());
	}
}


void ADoorTerminalActor::HackDoor() {}
void ADoorTerminalActor::LockDoor() {}
void ADoorTerminalActor::UnlockDoor() {}

