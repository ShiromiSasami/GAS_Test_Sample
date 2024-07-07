// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "ProjectileAbility.generated.h"

class AGAS_TestProjectile;

/**
 * 
 */
UCLASS()
class GAS_TEST_API UProjectileAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UProjectileAbility();
	
public:
	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo, 
		const FGameplayEventData* TriggerEventData) override;

private:
	void SpawnProjectile(
		const FGameplayAbilitySpecHandle Handle, 
		const FGameplayAbilityActorInfo* ActorInfo);

protected:
	UPROPERTY(EditDefaultsOnly, Category = GAS)
	TSubclassOf<AGAS_TestProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GAS)
	USoundBase* FireSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GAS)
	UAnimMontage* FireAnimation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GAS)
	FVector MuzzleOffset;

	UPROPERTY(EditDefaultsOnly, Category = GAS)
	TSubclassOf<UGameplayEffect> FireEffect;

	UPROPERTY(EditDefaultsOnly, Category = GAS)
	TSubclassOf<UGameplayEffect> FireWaitEffect;
};
