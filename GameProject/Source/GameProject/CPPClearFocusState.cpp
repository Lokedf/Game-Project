// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPClearFocusState.h"
#include "AIController.h"

void UCPPClearFocusState::EnterState(AAIController* Owner)
{
    if (Owner)
    {
        Owner->ClearFocus(EAIFocusPriority::Default);
    }
}
