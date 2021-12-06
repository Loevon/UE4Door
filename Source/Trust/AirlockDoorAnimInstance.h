// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AirlockDoorAnimInstance.generated.h"

/**
 *
 */
UCLASS(transient, Blueprintable, hideCategories = AnimInstance, BlueprintType)
class UAirlockDoorAnimInstance: public UAnimInstance{
	GENERATED_BODY()

public:
	UAirlockDoorAnimInstance();

	UPROPERTY(EditANywhere, BlueprintReadWrite, Category = "Generic")
	bool isOpen;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
};
