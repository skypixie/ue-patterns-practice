// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "Members/Member.h"

#include "Squad.generated.h"

/**
 * squad interface
 * we can derive other types of squads from it
 * for example, Battle squad or squad for Mining
 * that will have different types of members
 * for example, miner, support, technician etc.
 */


/*
* For my example, I will only create Battle squad
* but we could create many more play modes
*/
UCLASS()
class CPPMIDDLEPRACTICE_API USquad : public UObject
{
	GENERATED_BODY()

protected:
	TArray<AMember*> Members;

public:
	UFUNCTION(BlueprintCallable)
	virtual void BuildSolo() PURE_VIRTUAL(USquad::BuildSolo,);
	UFUNCTION(BlueprintCallable)
	virtual void BuildDuo() PURE_VIRTUAL(USquad::BuildDuo,);
	UFUNCTION(BlueprintCallable)
	virtual void BuildFull() PURE_VIRTUAL(USquad::BuildFull, );
	UFUNCTION(BlueprintCallable)
	virtual void Reset() PURE_VIRTUAL(USquad::Reset, );

	
};

UCLASS()
class CPPMIDDLEPRACTICE_API UBattleSquad : public USquad
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AMember> FighterClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AMember> ShooterClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AMember> SupportClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AMember> TankClass;

	void BuildSolo() override;
	void BuildDuo() override;
	void BuildFull() override;
	void Reset() override;

};
