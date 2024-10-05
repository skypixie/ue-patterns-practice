// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "Squad.h"
#include "SessionSystem.h"

#include "SquadDirector.generated.h"

/**
 * 
 */
UCLASS()
class CPPMIDDLEPRACTICE_API USquadDirector : public UObject
{
	GENERATED_BODY()

protected:
	USquad* Result = nullptr;

public:

	USquadDirector();

	USquadDirector(USquad* Squad);

	UFUNCTION(BlueprintCallable)
	void MakeSolo();
	UFUNCTION(BlueprintCallable)
	void MakeDuo();
	UFUNCTION(BlueprintCallable)
	void MakeFull();

	UFUNCTION(BlueprintCallable)
	USquad* GetResult();
	
};
