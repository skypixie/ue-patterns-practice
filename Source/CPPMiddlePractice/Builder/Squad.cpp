// Fill out your copyright notice in the Description page of Project Settings.


#include "Squad.h"

#include "Members/Member.h"
#include "Members/Fighter.h"

void UBattleSquad::BuildSolo()
{
	AMember* newMember = dynamic_cast<AFighter*>(GetWorld()->SpawnActor(FighterClass));
	Members.Add(newMember);
}

void UBattleSquad::BuildDuo()
{
	AMember* newMember1 = dynamic_cast<AFighter*>(GetWorld()->SpawnActor(FighterClass));
	AMember* newMember2 = dynamic_cast<AFighter*>(GetWorld()->SpawnActor(SupportClass));
	Members.Add(newMember1);
	Members.Add(newMember2);
}

void UBattleSquad::BuildFull()
{
	AMember* newMember1 = dynamic_cast<AFighter*>(GetWorld()->SpawnActor(FighterClass));
	AMember* newMember2 = dynamic_cast<AFighter*>(GetWorld()->SpawnActor(SupportClass));
	AMember* newMember3 = dynamic_cast<AFighter*>(GetWorld()->SpawnActor(ShooterClass));
	AMember* newMember4 = dynamic_cast<AFighter*>(GetWorld()->SpawnActor(TankClass));
	Members.Add(newMember1);
	Members.Add(newMember2);
	Members.Add(newMember3);
	Members.Add(newMember4);
}

void UBattleSquad::Reset()
{
	for (int32 i = 0; i < Members.Num(); ++i)
	{
		Members.RemoveAt(i);
	}
}
