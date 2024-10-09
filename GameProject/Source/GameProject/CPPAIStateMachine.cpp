// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPAIStateMachine.h"
#include "CPPPassiveState.h"
#include "Engine/World.h"


UCPPAIStateMachine::UCPPAIStateMachine() : CurrentState(nullptr)
{
}

UCPPAIStateMachine::~UCPPAIStateMachine()
{

    StateMap.Empty();
}

void UCPPAIStateMachine::Initialize(AAIController* Owner)
{
    StateMap.Add(EAIState::Passive, NewObject<UCPPPassiveState>(this));
    // Add other states similarly...
}

void UCPPAIStateMachine::ChangeState(EAIState NewState, AAIController* Owner)
{
    if (CurrentState)
    {
        CurrentState->ExitState(Owner);
    }

    if (StateMap.Contains(NewState))
    {
        CurrentState = StateMap[NewState].Get();
    }

    if (CurrentState)
    {
        CurrentState->EnterState(Owner);
    }
}


void UCPPAIStateMachine::UpdateCurrentState(AAIController* Owner, float DeltaTime)
{
    if (CurrentState)
    {
        CurrentState->UpdateState(Owner, DeltaTime);
    }
}

void UCPPAIStateMachine::EndAction()
{
}

void UCPPAIStateMachine::OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors, AAIController* Owner)
{
    if (CurrentState)
    {
        // Example: Forward perception updates to the current state
        if (UCPPPassiveState* PassiveState = Cast<UCPPPassiveState>(CurrentState))
        {
            PassiveState->OnPerceptionUpdated(UpdatedActors);
        }
    }
}