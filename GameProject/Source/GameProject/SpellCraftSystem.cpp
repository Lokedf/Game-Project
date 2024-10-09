 // Fill out your copyright notice in the Description page of Project Settings.


#include "SpellCraftSystem.h"

ASpellCraftSystem::ASpellCraftSystem()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ASpellCraftSystem::BeginPlay()
{
    Super::BeginPlay();
}

FSpell ASpellCraftSystem::CraftSpell(const TArray<FRune>& SelectedRunes)
{
    FSpell NewSpell;
    NewSpell.Runes = SelectedRunes;
    NewSpell.GenerateDescription();
    return NewSpell;
}

void ASpellCraftSystem::CastSpell(const FSpell& Spell, UObject* Target)
{
    for (const FRune& Rune : Spell.Runes)
    {
        if (Rune.EffectClass)
        {
            URuneEffect* Effect = NewObject<URuneEffect>(this, Rune.EffectClass);
            if (Effect)
            {
                Effect->ApplyEffect(Target);
            }
        }
    }
}