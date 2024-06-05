// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPAICombatState.h"
#include "AIController.h"
#include "MyAIController.h"
#include "GameFramework/Actor.h"

void UCPPAICombatState::EnterState(AAIController* Owner)
{
    // Code to execute when entering the Combat state
    if (AMyAIController* MyAIController = Cast<AMyAIController>(Owner))
    {
        MyAIController->WieldWeaponEnemyBase();
    }
}

void UCPPAICombatState::UpdateState(AAIController* Owner, float DeltaTime) 
{
    // Code to execute while in the Combat state
}

void UCPPAICombatState::ExitState(AAIController* Owner)
{
    // Code to execute when exiting the Combat state
    if (AMyAIController* MyAIController = Cast<AMyAIController>(Owner))
    {
        MyAIController->UnWieldWeaponEnemyBase();
    }
}

void UCPPAICombatState::OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors)
{
    // Handle perception updates specific to the Combat state
    for (AActor* Actor : UpdatedActors)
    {
        if (Actor->ActorHasTag("Player"))
        {
            // Change state based on perception update
        }
    }
}