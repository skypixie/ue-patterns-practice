// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemy.h"
#include "ElvenBoss.generated.h"

/**
 * 
 */
UCLASS()
class CPPMIDDLEPRACTICE_API AElvenBoss : public AEnemy
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	void Hit() override;
	
};
