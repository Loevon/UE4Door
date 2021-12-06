// Fill out your copyright notice in the Description page of Project Settings.


#include "AirlockDoorAnimInstance.h"
#include "AirlockDoorActor.h"

UAirlockDoorAnimInstance::UAirlockDoorAnimInstance() {
	isOpen = true;
}

void UAirlockDoorAnimInstance::NativeUpdateAnimation(float DeltaSeconds) {
	Super::NativeUpdateAnimation(DeltaSeconds);

	AActor *OwningActor = GetOwningActor();

	if (OwningActor != nullptr) {
		AAirlockDoorActor *AirlockDoorActor = Cast<AAirlockDoorActor>(OwningActor);

		if (AirlockDoorActor != nullptr) {
			isOpen = AirlockDoorActor->GetIsOpen();
		}
	}
}
