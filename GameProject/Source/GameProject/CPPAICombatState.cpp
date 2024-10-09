// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPAICombatState.h"
#include "AIController.h"
#include "MyAIController.h"
#include "GameFramework/Actor.h"

void UCPPAICombatState::EndAction()
{
}

void UCPPAICombatState::EnterState(AAIController* Owner)
{
	// Code to execute when entering the Combat state
	if (AMyAIController* MyAIController = Cast<AMyAIController>(Owner))
	{
		MyAIController->WieldWeaponEnemyBase();
		if (MyAIController->myTarget != nullptr)
			MyAIController->SetFocus(MyAIController->myTarget);
	}
}

void UCPPAICombatState::UpdateState(AAIController* Owner, float DeltaTime)
{
	// Code to execute while in the Combat state
	if (AMyAIController* myAIController = Cast<AMyAIController>(Owner))
	{
		if (myModes == ECombatModes::EUnsheathe)
		{
			if (UnsheatheWeapons(myAIController))
				myModes = ECombatModes::EFindCover;
		}
		if (myModes == ECombatModes::EFindCover)
		{

		}
	}
}

void UCPPAICombatState::ExitState(AAIController* Owner)
{
	// Code to execute when exiting the Combat state
	if (AMyAIController* MyAIController = Cast<AMyAIController>(Owner))
	{
		MyAIController->UnWieldWeaponEnemyBase();
	}
}

void UCPPAICombatState::MoveTo()
{
	AAIController AIC;
}

void UCPPAICombatState::OnPerceptionUpdated(const TArray<AActor*>& UpdatedActors)
{
	// Handle perception updates specific to the Combat state
	for (AActor* Actor : UpdatedActors)
	{
		if (Actor->ActorHasTag("Player"))
		{
			// Change state based on perception update
		}
	}
}

bool UCPPAICombatState::UnsheatheWeapons(AMyAIController* aMyAIController)
{
	if (aMyAIController->myTarget != nullptr)
		aMyAIController->SetFocus(aMyAIController->myTarget);
	return aMyAIController->WieldWeaponEnemyBase();
}
