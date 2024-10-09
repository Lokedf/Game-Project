// Fill out your copyright notice in the Description page of Project Settings.


#include "MoveForwardEffect.h"
#include "GameFramework/Actor.h"

void UMoveForwardEffect::ApplyEffect_Implementation(UObject* Target)
{
    if (AActor* TargetActor = Cast<AActor>(Target))
    {
        FVector NewLocation = TargetActor->GetActorLocation() + FVector(100, 0, 0);
        TargetActor->SetActorLocation(NewLocation);
    }
}