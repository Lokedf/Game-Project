// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPWaitState.h"
#include "AIController.h"
#include "TimerManager.h"

void UCPPWaitState::EnterState(AAIController* Owner)
{
    if (Owner)
    {
        Owner->GetWorldTimerManager().SetTimer(TimerHandle, FTimerDelegate::CreateUObject(this, &UCPPWaitState::OnWaitCompleted, Owner), WaitTime, false);
    }
}

void UCPPWaitState::OnWaitCompleted(AAIController* Owner)
{
    // Transition to the next state
    CompleteState(Owner, true);
}