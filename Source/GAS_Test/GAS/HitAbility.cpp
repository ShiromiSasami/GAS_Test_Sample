// Fill out your copyright notice in the Description page of Project Settings.


#include "HitAbility.h"
#include "AbilitySystemComponent.h"
#include "NativeTags.h"

UHitAbility::UHitAbility()
{
	FAbilityTriggerData TriggerData;
	TriggerData.TriggerTag = FNativeTags::Get().Hit;
	AbilityTriggers.Add(TriggerData);
}

void UHitAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle, 
	const FGameplayAbilityActorInfo* ActorInfo, 
	const FGameplayAbilityActivationInfo ActivationInfo, 
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

    const AActor* Source = TriggerEventData->Instigator.Get();
	const AActor* Target = TriggerEventData->Target.Get();

	FString Message = FString::Printf(TEXT("Hit!!  Source:%s  Target:%s"), *Source->GetName(), *Target->GetName());
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, Message);
    

	EndAbility(Handle, ActorInfo, ActivationInfo, false, false);
}
