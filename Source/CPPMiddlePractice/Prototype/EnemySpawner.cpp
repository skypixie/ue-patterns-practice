// Fill out your copyright notice in the Description page of Project Settings.


#include "Prototype/EnemySpawner.h"

/*
* Spawner spawns enemies
* enemies are copies of prototype
* 
*/

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	Collision->SetupAttachment(GetRootComponent());
	Collision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	Collision->OnComponentBeginOverlap.AddDynamic(this, &AEnemySpawner::OnOverlapBegin);

}

void AEnemySpawner::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IsValid(Prototype))
	{
		FVector SpawnLocation = FMath::RandPointInBox(Collision->GetNavigationBounds());
		FTransform SpawnTransform(SpawnLocation);
		FActorSpawnParameters SpawnParams;

		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
		// Template copies all properties the prototype !!!
		// So we do not need "clone" function in Unreal
		SpawnParams.Template = Prototype;

		GetWorld()->SpawnActor(Prototype->GetClass(), &SpawnTransform, SpawnParams);
	}
}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

