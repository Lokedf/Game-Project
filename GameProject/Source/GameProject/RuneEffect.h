// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RuneEffect.generated.h"

UCLASS(Blueprintable)
class GAMEPROJECT_API URuneEffect : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "RuneEffect")
    void ApplyEffect(UObject* Target);
    virtual void ApplyEffect_Implementation(UObject* Target);
};