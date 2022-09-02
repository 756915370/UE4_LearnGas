// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "GameplayAbilities/Public/Abilities/GameplayAbility.h"
#include "GameplayAbilities/Public/AbilitySystemComponent.h"
#include "BaseCharacter.generated.h"

class UBaseAttributeSet;
UCLASS()
class LEARNGAS_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="BaseCharacter")
	UAbilitySystemComponent* AbilitySystemComp;

	UFUNCTION(BlueprintCallable, Category="BaseCharacter")
	void InitializeAbility(TSubclassOf<UGameplayAbility> AbilityToGet, int32 AbilityLevel);

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="BaseCharacter")
	const class UBaseAttributeSet* BaseAttributeSetComp;

	UFUNCTION(BlueprintPure,Category="BaseCharacter")
	void GetHealthValues(float& Health,float& MaxHealth);

	UFUNCTION(BlueprintPure,Category="BaseCharacter")
	void GetManaValue(float& Mana,float& MaxMana);

	UFUNCTION(BlueprintPure,Category="BaseCharacter")
	void GetStaminaValues(float& Sta,float& MaxSta);
	
	UFUNCTION(BlueprintPure,Category="BaseCharacter")
	void GetShieldsValues(float& Shield,float& MaxShield);

	void OnHealthChangedNative(const FOnAttributeChangeData& Data);
	void OnManaChangedNative(const FOnAttributeChangeData& Data);
	void OnStaminaChangedNative(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent,Category="BaseCharacter")
	void OnHealthChanged(float Old,float New);
	UFUNCTION(BlueprintImplementableEvent,Category="BaseCharacter")
	void OnManaChanged(float Old,float New);
	UFUNCTION(BlueprintImplementableEvent,Category="BaseCharacter")
	void OnStaminaChanged(float Old,float New);
};
