// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "TPPNETGameInstance.generated.h"

/**
 *
 */
UCLASS()
class TTPNET_API UTPPNETGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UTPPNETGameInstance(const FObjectInitializer& ObjectIn);

	virtual void Init();

	UFUNCTION(BlueprintCallable)
	void LoadMenu();

	UFUNCTION(Exec)
	void Host();

	UFUNCTION(Exec)
	void Join(const FString& Address);

private:
	// class UUserWidget - that is a forward declaration
	TSubclassOf<UUserWidget> MenuClass;
};
