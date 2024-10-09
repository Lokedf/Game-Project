// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Rune.h"
#include "SpellCraftSystem.generated.h"

USTRUCT(BlueprintType)
struct FSpell
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spell")
    TArray<FRune> Runes;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spell")
    FString Description;

    FSpell()
        : Description(TEXT("Unnamed Spell")) {}

    void GenerateDescription()
    {
        Description = TEXT("Spell: ");
        for (const FRune& Rune : Runes)
        {
            Description += Rune.EffectDescription + TEXT(" ");
        }
    }
};

UCLASS()
class GAMEPROJECT_API ASpellCraftSystem : public AActor
{
    GENERATED_BODY()

public:
    ASpellCraftSystem();

protected:
    virtual void BeginPlay() override;

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Crafting")
    TArray<FRune> AvailableRunes;

    UFUNCTION(BlueprintCallable, Category = "Crafting")
    FSpell CraftSpell(const TArray<FRune>& SelectedRunes);

    UFUNCTION(BlueprintCallable, Category = "Crafting")
    void CastSpell(const FSpell& Spell, UObject* Target);
};