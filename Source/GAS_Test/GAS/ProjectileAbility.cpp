// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileAbility.h"
#include "GAS_Test/GAS_TestProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "GAS_Test/GAS_TestCharacter.h"
#include "PlayerAbilitySystemComponent.h"
#include "NativeTags.h"
#include "PlayerAttributeSet.h"

UProjectileAbility::UProjectileAbility()
{
	MuzzleOffset = FVector(100.0f, 0.0f, 10.0f);

	ActivationBlockedTags.AddTag(FNativeTags::Get().FireWait);
}

void UProjectileAbility::ActivateAbility(
	const FGameplayAbilitySpecHandle Handle,
	const FGameplayAbilityActorInfo* ActorInfo, 
	const FGameplayAbilityActivationInfo ActivationInfo, 
	const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	SpawnProjectile(Handle, ActorInfo);

	EndAbility(Handle, ActorInfo, ActivationInfo, false, false);
}

void UProjectileAbility::SpawnProjectile(
	const FGameplayAbilitySpecHandle Handle, 
	const FGameplayAbilityActorInfo* ActorInfo)
{
	if (ProjectileClass)
	{
		UWorld* const World = GetWorld();
		if (World)
		{
			APlayerController* PlayerController = ActorInfo->PlayerController.Get();
			const FRotator SpawnRotation = PlayerController->PlayerCameraManager->GetCameraRotation();
			const FVector SpawnLocation = ActorInfo->AvatarActor->GetActorLocation() + SpawnRotation.RotateVector(MuzzleOffset);

			FActorSpawnParameters ActorSpawnParams;
			if (AGAS_TestCharacter* Pawn = Cast<AGAS_TestCharacter>(ActorInfo->AvatarActor))
			{
				//弾丸の発射者を設定
				ActorSpawnParams.Owner = Pawn;
				ActorSpawnParams.Instigator = Pawn;
			}
			ActorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;
			AGAS_TestProjectile* Projectile = World->SpawnActor<AGAS_TestProjectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
		}
	}

	if (FireSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, FireSound, ActorInfo->AvatarActor->GetActorLocation());
	}

	AGAS_TestCharacter* Character = Cast<AGAS_TestCharacter>(ActorInfo->AvatarActor);
	if (FireAnimation && Character)
	{
		UAnimInstance* AnimInstance = Character->GetMesh1P()->GetAnimInstance();
		if (AnimInstance)
		{
			AnimInstance->Montage_Play(FireAnimation, 1.f);
		}
	}

	if (UPlayerAbilitySystemComponent* ASC = Character->GetAbilitySystemComponent())
	{
		// エフェクトスペックを作成
		FGameplayEffectContextHandle EffectContext = MakeEffectContext(Handle, ActorInfo);
		FGameplayEffectSpecHandle FireHandle = ASC->MakeOutgoingSpec(FireEffect, GetAbilityLevel(), EffectContext);

		if (FireHandle.IsValid())
		{
			// 弾数を減らす効果適用
			ASC->ApplyGameplayEffectSpecToSelf(*FireHandle.Data.Get());
		}

		if (ASC->GetNumericAttribute(UPlayerAttributeSet::GetBulletCountAttribute()) < 1)
		{
			FGameplayEffectSpecHandle FireWaitHandle = ASC->MakeOutgoingSpec(FireWaitEffect, GetAbilityLevel(), EffectContext);

			if (FireWaitHandle.IsValid())
			{
				// リロードのタグ付与効果適用
				ASC->ApplyGameplayEffectSpecToSelf(*FireWaitHandle.Data.Get());
			}
		}
	}
}
