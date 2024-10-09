// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "CPPAIStateMachine.h"
#include "CPPAIStates.h"
#include "MyBaseCPPAIBlackBoardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "MyAIController.generated.h"

UCLASS()
class GAMEPROJECT_API AMyAIController : public AAIController
{
    GENERATED_BODY()

public:
    AMyAIController();

    UFUNCTION(BlueprintCallable, Category = "AIState")
    void ChangeState(UCPPAIStateBase* NewState);

    virtual void Tick(float DeltaTime) override;

    //void ChangeAIState(EAIState NewState);

    bool WieldWeaponEnemyBase();
    bool UnWieldWeaponEnemyBase();
    UFUNCTION()
    void EndAction();
    AActor* myTarget = nullptr;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Blackboard")
    UMyBaseCPPAIBlackBoardComponent* myBlackboard;

protected:
    virtual void BeginPlay() override;

    // Perception Component
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
    UAIPerceptionComponent* AIPerceptionComponent;

    // Sight Configuration
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AI")
    UAISenseConfig_Sight* SightConfig;

    UFUNCTION()
    void OnStateChange(EAIState NewState);

    UFUNCTION()
    void OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors);



private:
    UPROPERTY()
    UCPPAIStateMachine* StateMachine;

    UPROPERTY()
    UCPPAIStateBase* CurrentState;



};