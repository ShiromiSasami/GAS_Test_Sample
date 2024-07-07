// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "HitAbility.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEST_API UHitAbility : public UGameplayAbility
{
	GENERATED_BODY()
public:
	UHitAbility();

public:
	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData) override;
};
