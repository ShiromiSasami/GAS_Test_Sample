// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayCueNotify_Static.h"
#include "ReloadCue.generated.h"

/**
 * 
 */
UCLASS()
class GAS_TEST_API UReloadCue : public UGameplayCueNotify_Static
{
	GENERATED_BODY()
public:
	UReloadCue();

protected:
	virtual void HandleGameplayCue(AActor* MyTarget, EGameplayCueEvent::Type EventType, const FGameplayCueParameters& Parameters) override;

};
