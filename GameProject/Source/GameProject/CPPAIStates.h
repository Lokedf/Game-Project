// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

UENUM(BlueprintType)
enum class EAIState : uint8
{
    Passive       UMETA(DisplayName = "Passive"),
    Attack        UMETA(DisplayName = "Attack"),
    Patrol        UMETA(DisplayName = "Patrol"),
    Investigate   UMETA(DisplayName = "Investigate"),
    Frozen        UMETA(DisplayName = "Frozen"),
    Dead          UMETA(DisplayName = "Dead")
};
