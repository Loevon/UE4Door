// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorAnimNotifyState.h"
#include "Engine.h"
#include "DoorActor.h"

void UDoorAnimNotifyState::NotifyBegin(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation, float TotalDuration) {
	// GEngine->AddOnScreenDebugMessage(-1, 4.5f, FColor::Purple, __FUNCTION__);

	if (MeshComp != NULL && MeshComp->GetOwner() != NULL) {
		ADoorActor *Door = Cast<ADoorActor>(MeshComp->GetOwner());
		if (Door != nullptr) {
			Door->LockDoor();
		}
	}
}

void UDoorAnimNotifyState::NotifyTick(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation, float FrameDeltaTime) {
	// GEngine->AddOnScreenDebugMessage(-1, 4.5f, FColor::Yellow, __FUNCTION__);
}

void UDoorAnimNotifyState::NotifyEnd(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation) {
	// GEngine->AddOnScreenDebugMessage(-1, 4.5f, FColor::Red, __FUNCTION__);

	if (MeshComp != NULL && MeshComp->GetOwner() != NULL) {
		ADoorActor *Door = Cast<ADoorActor>(MeshComp->GetOwner());
		if (Door != nullptr) {
			Door->UnlockDoor();
		}
	}
}
