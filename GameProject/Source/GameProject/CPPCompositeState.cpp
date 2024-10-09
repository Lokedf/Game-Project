// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPCompositeState.h"


UCPPCompositeState::UCPPCompositeState()
    : CurrentChildIndex(0)
{
}

void UCPPCompositeState::EnterState(AAIController* Owner)
{
    if (ChildStates.Num() > 0)
    {
        CurrentChildIndex = 0;
        if (ChildStates[CurrentChildIndex])
        {
            ChildStates[CurrentChildIndex]->EnterState(Owner);
        }
    }
}

void UCPPCompositeState::UpdateState(AAIController* Owner, float DeltaTime)
{
    if (CurrentChildIndex < ChildStates.Num() && ChildStates[CurrentChildIndex])
    {
        ChildStates[CurrentChildIndex]->UpdateState(Owner, DeltaTime);
    }
}

void UCPPCompositeState::ExitState(AAIController* Owner)
{
    if (CurrentChildIndex < ChildStates.Num() && ChildStates[CurrentChildIndex])
    {
        ChildStates[CurrentChildIndex]->ExitState(Owner);
    }
}

void UCPPCompositeState::OnChildStateCompleted(bool bSuccess)
{
    // To be overridden by Sequence and Selector nodes
}

void UCPPCompositeState::AddChildState(UCPPAIStateBase* ChildState)
{
    ChildStates.Add(ChildState);
}