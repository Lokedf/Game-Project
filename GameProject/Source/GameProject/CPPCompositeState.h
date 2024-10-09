// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPPAIStateBase.h"
#include "CPPCompositeState.generated.h"

UCLASS(Blueprintable)
class GAMEPROJECT_API UCPPCompositeState : public UCPPAIStateBase
{
    GENERATED_BODY()

public:
    UCPPCompositeState();

    virtual void EnterState(AAIController* Owner) override;
    virtual void UpdateState(AAIController* Owner, float DeltaTime) override;
    virtual void ExitState(AAIController* Owner) override;


    UPROPERTY()
    TArray<UCPPAIStateBase*> ChildStates;
protected:
    int CurrentChildIndex;

    virtual void OnChildStateCompleted(bool bSuccess);

public:
    void AddChildState(UCPPAIStateBase* ChildState);
};