// Fill out your copyright notice in the Description page of Project Settings.


#include "ElvenBoss.h"

void AElvenBoss::BeginPlay()
{
	Hit();
}

void AElvenBoss::Hit()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("AElvenBoss::Hit"));
}
