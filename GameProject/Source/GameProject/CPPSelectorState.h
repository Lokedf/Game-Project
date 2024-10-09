// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CPPCompositeState.h"
#include "CPPSelectorState.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT_API UCPPSelectorState : public UCPPCompositeState
{
    GENERATED_BODY()

public:
    virtual void OnChildStateCompleted(bool bSuccess) override;
};
