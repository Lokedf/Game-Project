// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPPAIStateBase.h"
#include "CPPWaitState.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT_API UCPPWaitState : public UCPPAIStateBase
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    float WaitTime;

    virtual void EnterState(AAIController* Owner) override;

private:
    FTimerHandle TimerHandle;
    void OnWaitCompleted(AAIController* Owner);
	
};
