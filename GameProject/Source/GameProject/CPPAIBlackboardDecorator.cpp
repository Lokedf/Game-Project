// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPAIBlackboardDecorator.h"
#include "MyAIController.h"

bool UCPPAIBlackboardDecorator::CheckCondition_Implementation(AAIController* Owner) const
{
    AMyAIController* MyAIController = Cast<AMyAIController>(Owner);
    if (MyAIController && MyAIController->myBlackboard)
    {
        return MyAIController->myBlackboard->GetValue<bool>(KeyName) == ExpectedValue;
    }
    return false;
}
