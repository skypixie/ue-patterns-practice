// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyFactory.h"

#include "Components/BoxComponent.h"

#include "Enemy.h"
#include "NecroSoldier.h"
#include "NecroBoss.h"
#include "ElvenSoldier.h"
#include "ElvenBoss.h"

/*
* Данный паттерн может применяться, когда нужно создавать
* объкеты с одним интерфейсом, но разными рализациями методов.
* Например, враги разного внешнего вида, с разным поведением и тп.
* Здесь я использую его для того, чтобы создавать врагов разных классов
* И игровой уровень использует фабрики, чтобы она создавала врагов.
*/

// Sets default values
AEnemyFactory::AEnemyFactory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SMComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Satic Mesh"));
	SMComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SMComp->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	SMComp->OnComponentBeginOverlap.AddDynamic(this, &AEnemyFactory::OnOverlapBegin);

	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	Collision->SetupAttachment(SMComp);
	Collision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Collision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);

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
	//Super::AEnemyFactory();
	SMComp->OnComponentEndOverlap.AddDynamic(this, &AElvenFactory::OnOverlapEnd);
}

AEnemy* AElvenFactory::CreateSoldier()
{
	FVector SpawnLocation = FMath::RandPointInBox(Collision->GetNavigationBounds());
	FTransform SpawnTransform(SpawnLocation);

	AEnemy* newSoldier = dynamic_cast<AElvenSoldier*>(GetWorld()->SpawnActor(SoldierToSpawn, &SpawnTransform));
	return newSoldier;
}

AEnemy* AElvenFactory::CreateBoss()
{
	FVector SpawnLocation = FMath::RandPointInBox(Collision->GetNavigationBounds());
	FTransform SpawnTransform(SpawnLocation);

	AEnemy* newSoldier = dynamic_cast<AElvenBoss*>(GetWorld()->SpawnActor(SoldierToSpawn, &SpawnTransform));
	return newSoldier;
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

void AElvenFactory::OnOverlapEnd(UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	CreateBoss();
}

ANecroFactory::ANecroFactory()
{
	//Super::AEnemyFactory();
	SMComp->OnComponentEndOverlap.AddDynamic(this, &ANecroFactory::OnOverlapEnd);
}

AEnemy* ANecroFactory::CreateSoldier()
{
	FVector SpawnLocation = FMath::RandPointInBox(Collision->GetNavigationBounds());
	FTransform SpawnTransform(SpawnLocation);

	AEnemy* newSoldier = dynamic_cast<ANecroSoldier*>(GetWorld()->SpawnActor(SoldierToSpawn, &SpawnTransform));
	return newSoldier;
}

AEnemy* ANecroFactory::CreateBoss()
{
	FVector SpawnLocation = FMath::RandPointInBox(Collision->GetNavigationBounds());
	FTransform SpawnTransform(SpawnLocation);

	AEnemy* newSoldier = dynamic_cast<ANecroBoss*>(GetWorld()->SpawnActor(BossToSpawn, &SpawnTransform));
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

void ANecroFactory::OnOverlapEnd(UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	CreateBoss();
}
