// Fill out your copyright notice in the Description page of Project Settings.

/**
* Данный паттерн используется, когда объект должен существовать в игре
* в единственном экземпляре. Я использую его для имитации формирования
* "сессии" в какой-нибудь онлайн игре. Например, для объединения игроков
* в отряды и т.п.
* Мы также могли бы использовать паттерн для работы с базой данных,
* тк два приложения не могут использовать файл одновременно.
*/


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
