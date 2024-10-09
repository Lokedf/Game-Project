// Fill out your copyright notice in the Description page of Project Settings.


#include "RuneFunctionLibrary.h"

FRune URuneFunctionLibrary::CreateRune(const FString& Name, ERuneType RuneType, const FString& Description, UTexture2D* Icon, TSubclassOf<URuneEffect> EffectClass)
{
    FRune NewRune;
    NewRune.Name = Name;
    NewRune.RuneType = RuneType;
    NewRune.EffectDescription = Description;
    NewRune.Icon = Icon;
    NewRune.EffectClass = EffectClass;
    return NewRune;
}