// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"
//#include "CPPAIStates.h"
#include "MyAIController.h"
#include "CPPSequenceState.h"
#include "CPPSelectorState.h"
#include "CPPClearFocusState.h"
#include "CPPSetMovementSpeedState.h"
#include "CPPMoveToState.h"
#include "CPPWaitState.h"
#include "CPPFocusState.h"

// Sets default values
AEnemyBase::AEnemyBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEnemyBase::StartFSM()
{
    AAIController* AIController = Cast<AAIController>(GetController());
    if (AIController)
    {
        AMyAIController* MyAIController = Cast<AMyAIController>(AIController);
        if (MyAIController)
        {
            MyAIController->myBlackboard->SetValue<bool>("WeaponEquipped", false);
            // Create the main sequence state
            UCPPSelectorState* MainSelector = NewObject<UCPPSelectorState>(this);

            // Create a nested sequence state
            UCPPSelectorState* CombatSelector = NewObject<UCPPSelectorState>(this);
            UCPPSelectorState* InvestigateSelector = NewObject<UCPPSelectorState>(this);
            UCPPSelectorState* IdleSelector = NewObject<UCPPSelectorState>(this);
            CombatSelector->AddChildState(NewObject<UCPPClearFocusState>(this));
            CombatSelector->AddChildState(NewObject<UCPPSetMovementSpeedState>(this));

            // Combat States
            UCPPSequenceState* CombatEquipSequence = NewObject<UCPPSequenceState>(this);
            UCPPSequenceState* CombatCoverSequence = NewObject<UCPPSequenceState>(this);
            UCPPSequenceState* CombatChaseSequence = NewObject<UCPPSequenceState>(this);
            UCPPSelectorState* CombatStrafeSelector = NewObject<UCPPSelectorState>(this);

            // Equip weapons
            CombatEquipSequence->AddChildState(NewObject<UCPPFocusState>(this));
            
            // Strafe states
            UCPPSequenceState* CombatStrafeRangeSequence = NewObject<UCPPSequenceState>(this);
            UCPPSequenceState* CombatStrafeDoSequence = NewObject<UCPPSequenceState>(this);
            //Strafe Range states
            UCPPSetMovementSpeedState* StrafeRangeSpeed = NewObject<UCPPSetMovementSpeedState>(this);
            StrafeRangeSpeed->MovementSpeed = 500.0f;
            CombatStrafeRangeSequence->AddChildState(NewObject<UCPPClearFocusState>(this));
            CombatStrafeRangeSequence->AddChildState(StrafeRangeSpeed);
            //Strafe do states
            UCPPMoveToState* MoveToState = NewObject<UCPPMoveToState>(this);
            MoveToState->TargetLocation = FVector(100.0f, 100.0f, 100.0f);
            MoveToState->AcceptanceRadius = 50.0f;

            UCPPWaitState* WaitState = NewObject<UCPPWaitState>(this);
            WaitState->WaitTime = 2.0f;

            // Add states to the main sequence
            MainSelector->AddChildState(CombatSelector);
            MainSelector->AddChildState(CombatSelector);
            MainSelector->AddChildState(CombatSelector);
            MainSelector->AddChildState(MoveToState);
            MainSelector->AddChildState(WaitState);

            // Set up state transitions (if needed)
            for (int32 i = 0; i < MainSelector->ChildStates.Num() - 1; ++i)
            {
                MainSelector->ChildStates[i]->NextState = MainSelector->ChildStates[i + 1];
            }

            for (int32 i = 0; i < CombatSelector->ChildStates.Num() - 1; ++i)
            {
                CombatSelector->ChildStates[i]->NextState = CombatSelector->ChildStates[i + 1];
            }

            // Start the FSM
            MyAIController->ChangeState(MainSelector);
        }
    }
}

// Called every frame
void AEnemyBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemyBase::CPPWieldWeapon()
{
	// Implement your function logic here
}

void AEnemyBase::CPPUnWieldWeapon()
{
	// Implement your function logic here
}

void AEnemyBase::CPPEndAction()
{
    AAIController* AIController = Cast<AAIController>(GetController());
    if (AIController)
    {
        AMyAIController* MyAIController = Cast<AMyAIController>(AIController);
        if (MyAIController)
        {
            MyAIController->EndAction();
        }
    }
}

// Called to bind functionality to input
void AEnemyBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

