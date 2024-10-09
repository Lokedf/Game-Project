// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyBaseCPPAIBlackBoardComponent.generated.h"

/**
 * 
 */
UCLASS()
class GAMEPROJECT_API UMyBaseCPPAIBlackBoardComponent : public UObject
{
    GENERATED_BODY()

public:
    UMyBaseCPPAIBlackBoardComponent();

    // SetValue function template
    template <typename VariableType>
    UFUNCTION(BlueprintCallable, Category = "Blackboard")
    void SetValue(FName KeyName, VariableType Value);

    // GetValue function template
    template <typename VariableType>
    UFUNCTION(BlueprintCallable, Category = "Blackboard")
    VariableType GetValue(FName KeyName) const;

private:
    //// Specializations of SetValue function template
    //void SetValue(FName KeyName, bool Value);
    //void SetValue(FName KeyName, float Value);
    //void SetValue(FName KeyName, AActor* Value);

    //// Specializations of GetValue function template
    //bool GetValue(FName KeyName) const;
    //float GetValue(FName KeyName) const;
    //AActor* GetValue(FName KeyName) const;

    // Storage for different types
    TMap<FName, bool> BoolValues;
    TMap<FName, float> FloatValues;
    TMap<FName, AActor*> ActorValues;
};

// Implementations
UMyBaseCPPAIBlackBoardComponent::UMyBaseCPPAIBlackBoardComponent()
{
}

template <typename VariableType>
void UMyBaseCPPAIBlackBoardComponent::SetValue(FName KeyName, VariableType Value)
{
    // This function should never be called, it exists for template compatibility
    ensureMsgf(false, TEXT("Unsupported type"));
}

template <>
void UMyBaseCPPAIBlackBoardComponent::SetValue<bool>(FName KeyName, bool Value)
{
    BoolValues.Add(KeyName, Value);
}

template <>
void UMyBaseCPPAIBlackBoardComponent::SetValue<float>(FName KeyName, float Value)
{
    FloatValues.Add(KeyName, Value);
}

template <>
void UMyBaseCPPAIBlackBoardComponent::SetValue<AActor*>(FName KeyName, AActor* Value)
{
    ActorValues.Add(KeyName, Value);
}

template <typename VariableType>
VariableType UMyBaseCPPAIBlackBoardComponent::GetValue(FName KeyName) const
{
    // This function should never be called, it exists for template compatibility
    ensureMsgf(false, TEXT("Unsupported type"));
    return VariableType();
}

template <>
bool UMyBaseCPPAIBlackBoardComponent::GetValue<bool>(FName KeyName) const
{
    const bool* Value = BoolValues.Find(KeyName);
    return Value ? *Value : false;
}

template <>
float UMyBaseCPPAIBlackBoardComponent::GetValue<float>(FName KeyName) const
{
    const float* Value = FloatValues.Find(KeyName);
    return Value ? *Value : 0.0f;
}

template <>
AActor* UMyBaseCPPAIBlackBoardComponent::GetValue<AActor*>(FName KeyName) const
{
    AActor* const* Value = ActorValues.Find(KeyName);
    return Value ? *Value : nullptr;
}