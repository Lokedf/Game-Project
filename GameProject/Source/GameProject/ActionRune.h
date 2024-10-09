//// Fill out your copyright notice in the Description page of Project Settings.
//
//#pragma once
//
//#include "CoreMinimal.h"
//#include "Rune.h"
//#include "ActionRune.generated.h"
//
//UCLASS()
//class MYPROJECT_API UActionRune : public UObject
//{
//    GENERATED_BODY()
//
//public:
//    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rune")
//    FRune Rune;
//
//    UActionRune()
//    {
//        Rune.Name = TEXT("Move Forward");
//        Rune.RuneType = ERuneType::Action;
//        Rune.EffectDescription = TEXT("Moves the target forward.");
//    }
//
//    void ApplyEffect(AActor* Target)
//    {
//        // Implement the effect logic
//    }
//};