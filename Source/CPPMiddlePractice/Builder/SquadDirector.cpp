// Fill out your copyright notice in the Description page of Project Settings.

/*
* Данный паттерн используется для настройки сложных объектов.
* Например, его можно использовать для создания сложной карты.
* В своем примере я его использую для создания лобби в разных режимах игры.
* Например, есть режим игры, где надо воевать, а есть, где надо строить или собирать ресурсы.
* В таком случае, нам понадобится настройка и подготовка игроков к своим ролям.
*/

/**
 * squad interface
 * we can derive other types of squads from it
 * for example, Battle squad or squad for Mining
 * that will have different types of members
 * for example, miner, support, technician etc.
 */

#include "SquadDirector.h"

USquadDirector::USquadDirector()
{
}

USquadDirector::USquadDirector(USquad* Squad)
{
	if (Squad) Result = Squad;
}

void USquadDirector::MakeSolo()
{
	if (Result)
	{
		Result->BuildSolo();
	}
}

void USquadDirector::MakeDuo()
{
	if (Result)
	{
		Result->BuildDuo();
	}
}

void USquadDirector::MakeFull()
{
	if (Result)
	{
		Result->BuildFull();
	}
}

USquad* USquadDirector::GetResult()
{
	return nullptr;
}
