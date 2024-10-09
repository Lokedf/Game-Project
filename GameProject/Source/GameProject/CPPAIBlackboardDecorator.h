// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPPAIDecorator.h"
#include "CPPAIBlackboardDecorator.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT_API UCPPAIBlackboardDecorator : public UCPPAIDecorator
{
    GENERATED_BODY()

public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blackboard")
    FName KeyName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Blackboard")
    bool ExpectedValue;

    virtual bool CheckCondition_Implementation(AAIController* Owner) const override;
	
};
