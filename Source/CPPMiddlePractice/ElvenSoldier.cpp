// Fill out your copyright notice in the Description page of Project Settings.


#include "ElvenSoldier.h"

void AElvenSoldier::BeginPlay()
{
	Hit();
}

void AElvenSoldier::Hit()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("AElvenSoldier::Hit"));
}
