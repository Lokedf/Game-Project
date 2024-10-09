// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RuneEffect.h"
#include "Rune.generated.h"

UENUM(BlueprintType)
enum class ERuneType : uint8
{
    Action UMETA(DisplayName = "Action"),
    Element UMETA(DisplayName = "Element"),
    Modifier UMETA(DisplayName = "Modifier"),
    // Add more types as needed
};

USTRUCT(BlueprintType)
struct FRune
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rune")
    FString Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rune")
    ERuneType RuneType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rune")
    FString EffectDescription;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rune")
    UTexture2D* Icon; // Example additional property

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rune")
    TSubclassOf<URuneEffect> EffectClass; // Reference to the effect class

    FRune()
        : Name(TEXT("Unknown")), RuneType(ERuneType::Action), EffectDescription(TEXT("No Effect")), Icon(nullptr), EffectClass(nullptr) {}
};