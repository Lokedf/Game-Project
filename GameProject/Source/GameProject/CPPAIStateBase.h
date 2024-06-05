// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CPPAIStates.h"
#include "CPPAIStateBase.generated.h" 


class AAIController;
UCLASS()
class GAMEPROJECT_API UCPPAIStateBase : public UObject
{

    GENERATED_BODY()

public:
    //virtual ~UCPPAIStateBase() = default;

    virtual void EnterState(AAIController* Owner) {}
    virtual void UpdateState(AAIController* Owner, float DeltaTime) {}
    virtual void ExitState(AAIController* Owner) {}
};