// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CPPAIDecorator.generated.h"
/**
 * 
 */
class AAIController;
UCLASS(Blueprintable)
class GAMEPROJECT_API UCPPAIDecorator : public UObject
{

    GENERATED_BODY()
public:
    UCPPAIDecorator();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Decorator")
    bool CheckCondition(AAIController* Owner) const;
    virtual bool CheckCondition_Implementation(AAIController* Owner) const;
};
