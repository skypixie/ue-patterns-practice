// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "Members/Member.h"
#include "Kismet/GameplayStatics.h"

#include "SessionSystem.generated.h"

/**
 * Imaginary system for managing players that
 * joined the online game
 */
UCLASS()
class CPPMIDDLEPRACTICE_API USessionSystem : public UObject
{
	GENERATED_BODY()

public:

	static USessionSystem& instance();

	void GetAllPlayers(TArray<AMember*>& Members_out);

private:
	USessionSystem() {}
};
