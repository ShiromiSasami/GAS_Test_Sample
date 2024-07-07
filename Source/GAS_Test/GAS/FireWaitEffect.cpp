// Fill out your copyright notice in the Description page of Project Settings.


#include "FireWaitEffect.h"
#include "NativeTags.h"
#include "GameplayEffectComponents/TargetTagsGameplayEffectComponent.h"

UFireWaitEffect::UFireWaitEffect()
{
	DurationPolicy = EGameplayEffectDurationType::HasDuration;
	DurationMagnitude = FGameplayEffectModifierMagnitude(FScalableFloat(5.0f));

	UTargetTagsGameplayEffectComponent* TargetTagsComponent = CreateDefaultSubobject<UTargetTagsGameplayEffectComponent>(TEXT("TargetTagsComponent"));
	FInheritedTagContainer TagContainer;
	TagContainer.AddTag(FNativeTags::Get().FireWait);
	TargetTagsComponent->SetAndApplyTargetTagChanges(TagContainer);
	GEComponents.Add(TargetTagsComponent);

	FGameplayEffectCue ReloadCue = FGameplayEffectCue(FNativeTags::Get().Reload, 0, 0);
	GameplayCues.Add(ReloadCue);
}

