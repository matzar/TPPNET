// Fill out your copyright notice in the Description page of Project Settings.

#include "TPPNETGameInstance.h"

UTPPNETGameInstance::UTPPNETGameInstance(const FObjectInitializer& ObjectIn)
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Constructor"));
}

void UTPPNETGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("GameInstance Init"));
}
