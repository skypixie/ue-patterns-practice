// Fill out your copyright notice in the Description page of Project Settings.


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
