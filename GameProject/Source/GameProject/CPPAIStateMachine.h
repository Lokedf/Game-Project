// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPPAIStateBase.h"
#include "CPPAIStates.h"
#include "CPPAIStateMachine.generated.h"

class AAIController;

/**
 * 
 */

UCLASS()
class GAMEPROJECT_API UCPPAIStateMachine : public UObject
{

    GENERATED_BODY()

public:
    UCPPAIStateMachine();
    ~UCPPAIStateMachine();

    void Initialize(AAIController* Owner);
    void ChangeState(EAIState NewState, AAIController* Owner);
    void UpdateCurrentState(AAIController* Owner, float DeltaTime);
    void EndAction();

    // Handle perception updates
    void OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors, AAIController* Owner);


private:
    UCPPAIStateBase* CurrentState;
    TMap<EAIState, TWeakObjectPtr<UCPPAIStateBase>> StateMap;
};