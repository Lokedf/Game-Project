// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPSetMovementSpeedState.h"
#include "AIController.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UCPPSetMovementSpeedState::EnterState(AAIController* Owner)
{
    if (Owner)
    {
        APawn* Pawn = Owner->GetPawn();
        if (Pawn)
        {
            ACharacter* Character = Cast<ACharacter>(Pawn);
            if (Character)
            {
                Character->GetCharacterMovement()->MaxWalkSpeed = MovementSpeed;
            }
        }
    }
}