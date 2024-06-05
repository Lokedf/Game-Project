// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPPassiveState.h"
#include "AIController.h"
#include "GameFramework/Actor.h"

void UCPPPassiveState::EnterState(AAIController* Owner)
{
    // Code to execute when entering the Idle state
}

void UCPPPassiveState::UpdateState(AAIController* Owner, float DeltaTime)
{
    // Code to execute while in the Idle state
}

void UCPPPassiveState::ExitState(AAIController* Owner)
{
    // Code to execute when exiting the Idle state
}

void UCPPPassiveState::OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors)
{
    // Handle perception updates specific to the Idle state
    for (AActor* Actor : UpdatedActors)
    {   
        if (Actor->ActorHasTag("Player"))
        {
            // Change state based on perception update
        }
    }
}