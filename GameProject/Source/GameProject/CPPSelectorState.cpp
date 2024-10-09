// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPSelectorState.h"

void UCPPSelectorState::OnChildStateCompleted(bool bSuccess)
{
    AAIController* Owner = Cast<AAIController>(GetOuter());
    if (Owner)
    {
        if (bSuccess)
        {
            // Selector succeeded
            CompleteState(Owner, true);
        }
        else
        {
            CurrentChildIndex++;
            if (CurrentChildIndex < ChildStates.Num())
            {
                if (ChildStates[CurrentChildIndex])
                {
                    ChildStates[CurrentChildIndex]->EnterState(Owner);
                }   
            }
            else
            {
                // Selector failed
                CompleteState(Owner, false);
            }
        }
    }
}