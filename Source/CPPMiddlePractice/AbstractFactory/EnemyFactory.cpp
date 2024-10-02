// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyFactory.h"

#include "Enemy.h"
#include "NecroSoldier.h"
#include "NecroBoss.h"
#include "ElvenSoldier.h"
#include "ElvenBoss.h"

/*
* Client is the factory itself 
*/

// Sets default values
AEnemyFactory::AEnemyFactory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyFactory::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyFactory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AElvenFactory::AElvenFactory()
{
	SMComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sm Comp"));
	SMComp->OnComponentBeginOverlap.AddDynamic(this, &AElvenFactory::OnOverlapBegin);
}

AEnemy* AElvenFactory::CreateSoldier()
{
	AEnemy* newSoldier = dynamic_cast<AElvenSoldier*>(GetWorld()->SpawnActor(SoldierToSpawn));
	return newSoldier;
}

AEnemy* AElvenFactory::CreateBoss()
{
	return nullptr;
}

void AElvenFactory::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComponent,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& HitResult)
{
	CreateSoldier();
}

ANecroFactory::ANecroFactory()
{
	SMComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sm Comp"));
	SMComp->OnComponentBeginOverlap.AddDynamic(this, &ANecroFactory::OnOverlapBegin);
}

AEnemy* ANecroFactory::CreateSoldier()
{
	return nullptr;
}

AEnemy* ANecroFactory::CreateBoss()
{
	AEnemy* newSoldier = dynamic_cast<AElvenSoldier*>(GetWorld()->SpawnActor(SoldierToSpawn));
	return newSoldier;
}

void ANecroFactory::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComponent,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& HitResult)
{
	CreateBoss();
}
