// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Rune.h"
#include "RuneFunctionLibrary.generated.h"

UCLASS()
class GAMEPROJECT_API URuneFunctionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Rune")
    static FRune CreateRune(const FString& Name, ERuneType RuneType, const FString& Description, UTexture2D* Icon, TSubclassOf<URuneEffect> EffectClass);
};