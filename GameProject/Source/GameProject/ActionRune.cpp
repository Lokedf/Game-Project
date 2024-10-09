//// Fill out your copyright notice in the Description page of Project Settings.
//
//
//#include "ActionRune.h"
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
//FRune CreateMoveForwardRune()
//{
//    FRune Rune;
//    Rune.Name = TEXT("Move Forward");
//    Rune.RuneType = ERuneType::Action;
//    Rune.EffectDescription = TEXT("Moves the target forward.");
//    Rune.Effect = FRuneEffectDelegate::CreateStatic(MoveForwardEffect);
//    return Rune;
//}