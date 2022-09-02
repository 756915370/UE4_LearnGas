// Fill out your copyright notice in the Description page of Project Settings.


#include "GATargetActor.h"

#include "Abilities/GameplayAbility.h"

AGATargetActor::AGATargetActor()
{
	PrimaryActorTick.bCanEverTick = true;
	TraceRange = 1500.0f;
	bDestroyOnConfirmation = true;
}

AGATargetActor* AGATargetActor::NewTargetActorTest()
{
	AGATargetActor* TA = NewObject<AGATargetActor>();
	return TA;
}

void AGATargetActor::StartTargeting(UGameplayAbility* Ability)
{
	OwningAbility = Ability;
	
	MyDelegate.Broadcast(FMyStruct());
	MasterPC = Cast<APlayerController>(Ability->GetOwningActorFromActorInfo()->GetInstigatorController());
}

void AGATargetActor::ConfirmTargetingAndContinue()
{
	FHitResult HitResult;
	bool TryTrace = LineTrace(HitResult);
	FGameplayAbilityTargetDataHandle TargetData;
	TargetData = StartLocation.MakeTargetDataHandleFromHitResult(OwningAbility, HitResult);
	if (TargetData != nullptr)
	{
		TargetDataReadyDelegate.Broadcast(TargetData);
	}
	else
	{
		TargetDataReadyDelegate.Broadcast(FGameplayAbilityTargetDataHandle());
	}
}

bool AGATargetActor::LineTrace(FHitResult& HitResult)
{
	FVector ViewPort;
	FRotator ViewRotation;
	MasterPC->GetPlayerViewPoint(ViewPort, ViewRotation);
	FCollisionQueryParams QueryParams;
	QueryParams.bTraceComplex = false;

	APawn* MasterPawn = MasterPC->GetPawn();
	if (MasterPawn)
	{
		QueryParams.AddIgnoredActor(MasterPawn);
	}
	bool TryTrace = GetWorld()->LineTraceSingleByChannel(HitResult, ViewPort,
	                                                     ViewPort + ViewRotation.Vector() * TraceRange, ECC_Visibility,
	                                                     QueryParams);
	return TryTrace;
}
