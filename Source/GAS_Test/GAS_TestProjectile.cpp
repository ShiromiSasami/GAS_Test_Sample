// Copyright Epic Games, Inc. All Rights Reserved.

#include "GAS_TestProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "GAS_TestCharacter.h"
#include "GAS/PlayerAbilitySystemComponent.h"
#include "GAS/NativeTags.h"
#include "AbilitySystemComponent.h"


AGAS_TestProjectile::AGAS_TestProjectile() 
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AGAS_TestProjectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;
}

void AGAS_TestProjectile::OnHit(
	UPrimitiveComponent* HitComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp, 
	FVector NormalImpulse,
	const FHitResult& Hit)
{
	if (AGAS_TestCharacter* SourceCharacter = Cast<AGAS_TestCharacter>(GetInstigator()))
	{
		UPlayerAbilitySystemComponent* SourceASC = SourceCharacter->GetAbilitySystemComponent();
		FGameplayEventData Payload;
		Payload.EventMagnitude = 1.0f;
		Payload.Instigator = GetInstigator();
		Payload.Target = OtherActor;
		Payload.OptionalObject = this;
		Payload.ContextHandle = SourceASC->MakeEffectContext();
		SourceASC->HandleGameplayEvent(FNativeTags::Get().Hit, &Payload);
	}

	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());

		Destroy();
	}
}