// Fill out your copyright notice in the Description page of Project Settings.

//
//#include "Rune.h"
//#include "Engine/Texture2D.h"
//#include "UObject/UObjectGlobals.h"
//
//void MoveForwardEffect(UObject* Target)
//{
//    if (AActor* TargetActor = Cast<AActor>(Target))
//    {
//        FVector NewLocation = TargetActor->GetActorLocation() + FVector(100, 0, 0);
//        TargetActor->SetActorLocation(NewLocation);
//    }
//}
//
//void FireElementEffect(UObject* Target)
//{
//    // Implement fire effect logic
//}
//
//// Factory function to create a Move Forward rune
//FRune CreateMoveForwardRune()
//{
//    FRune Rune;
//    Rune.Name = TEXT("Move Forward");
//    Rune.RuneType = ERuneType::Action;
//    Rune.EffectDescription = TEXT("Moves the target forward.");
//    Rune.Effect = FRuneEffectDelegate::CreateStatic(MoveForwardEffect);
////    Rune.Icon = LoadObject<UTexture2D>(nullptr, TEXT("/Game/Textures/MoveForwardIcon"));
//    return Rune;
//}
//
//// Factory function to create a Fire Element rune
//FRune CreateFireElementRune()
//{
//    FRune Rune;
//    Rune.Name = TEXT("Fire");
//    Rune.RuneType = ERuneType::Element;
//    Rune.EffectDescription = TEXT("Adds fire element.");
//    Rune.Effect = FRuneEffectDelegate::CreateStatic(FireElementEffect);
//    Rune.Icon = LoadObject<UTexture2D>(nullptr, TEXT("/Game/Textures/FireElementIcon"));
//    return Rune;
//}