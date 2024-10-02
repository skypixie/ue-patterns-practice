// Fill out your copyright notice in the Description page of Project Settings.


#include "NecroSoldier.h"

void ANecroSoldier::BeginPlay()
{
	Hit();
}

void ANecroSoldier::Hit()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("ANecroSoldier::Hit"));
}
