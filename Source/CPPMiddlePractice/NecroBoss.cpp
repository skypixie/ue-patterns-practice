// Fill out your copyright notice in the Description page of Project Settings.


#include "NecroBoss.h"

void ANecroBoss::BeginPlay()
{
	Hit();
}

void ANecroBoss::Hit()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("ANecroBoss::Hit"));

}
