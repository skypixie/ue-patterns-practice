// Fill out your copyright notice in the Description page of Project Settings.


#include "SessionSystem.h"

USessionSystem& USessionSystem::instance()
{
	static USessionSystem* instance_ = NewObject<USessionSystem>();
	return *instance_;
}

void USessionSystem::GetAllPlayers(TArray<AMember*>& Members_out)
{
	// get all online players
}
