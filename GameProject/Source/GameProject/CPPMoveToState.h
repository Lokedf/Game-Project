// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPPAIStateBase.h"
#include "CPPMoveToState.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT_API UCPPMoveToState : public UCPPAIStateBase
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    FVector TargetLocation;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
    float AcceptanceRadius;

    virtual void EnterState(AAIController* Owner) override;
    virtual void UpdateState(AAIController* Owner, float DeltaTime) override;

private:
    bool bIsMoving;
};
