// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPSequenceState.h"

void UCPPSequenceState::OnChildStateCompleted(bool bSuccess)
{
    AAIController* Owner = Cast<AAIController>(GetOuter());
    if (Owner)
    {
        if (bSuccess)
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
                // Sequence completed successfully
                CompleteState(Owner, true);
            }
        }
        else
        {
            // Sequence failed
            CompleteState(Owner, false);
        }
    }
}