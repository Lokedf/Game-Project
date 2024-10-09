// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPMoveToState.h"
#include "AIController.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TimerManager.h"

void UCPPMoveToState::EnterState(AAIController* Owner)
{
    if (Owner)
    {
        Owner->MoveToLocation(TargetLocation, AcceptanceRadius);
        bIsMoving = true;
    }
}

void UCPPMoveToState::UpdateState(AAIController* Owner, float DeltaTime)
{
    if (Owner && bIsMoving)
    {
        if (Owner->GetMoveStatus() == EPathFollowingStatus::Idle)
        {
            bIsMoving = false;
            CompleteState(Owner, true);
        }
    }
}