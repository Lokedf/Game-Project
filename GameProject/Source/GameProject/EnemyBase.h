// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "EnemyBase.generated.h"

UCLASS()
class GAMEPROJECT_API AEnemyBase : public ACharacter
{
    GENERATED_BODY()

public:
    AEnemyBase();
    virtual void Tick(float DeltaTime);
    void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);

protected:
    virtual void BeginPlay() override;

public:
    UFUNCTION(BlueprintCallable, Category = "AIState")
    void StartFSM();

    // Declare a variable and a function to be used in Blueprint
    UFUNCTION(BlueprintCallable, Category = "Enemy")
    void CPPWieldWeapon();
    UFUNCTION(BlueprintCallable, Category = "Enemy")
    void CPPUnWieldWeapon();
    UFUNCTION(BlueprintCallable, Category = "Enemy")
    void CPPEndAction();
};
