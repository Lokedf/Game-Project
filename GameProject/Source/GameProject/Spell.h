//// Fill out your copyright notice in the Description page of Project Settings.
//
//#pragma once
//
//#include "CoreMinimal.h"
//#include "Rune.h"
//#include "Spell.generated.h"
//
//USTRUCT(BlueprintType)
//struct FSpell
//{
//    GENERATED_BODY()
//
//    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spell")
//    TArray<FRune> Runes;
//
//    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spell")
//    FString Description;
//
//    FSpell()
//        : Description(TEXT("Unnamed Spell")) {}
//
//    void GenerateDescription()
//    {
//        Description = TEXT("Spell: ");
//        for (const FRune& Rune : Runes)
//        {
//            Description += Rune.EffectDescription + TEXT(" ");
//        }
//    }
//};
