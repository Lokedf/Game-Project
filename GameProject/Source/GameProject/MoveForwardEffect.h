// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuneEffect.h"
#include "MoveForwardEffect.generated.h"

UCLASS()
class GAMEPROJECT_API UMoveForwardEffect : public URuneEffect
{
    GENERATED_BODY()

public:
    virtual void ApplyEffect_Implementation(UObject* Target) override;
};