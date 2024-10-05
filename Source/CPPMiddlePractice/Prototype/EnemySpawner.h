// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"

#include "EnemyPrototype.h"

#include "EnemySpawner.generated.h"

UCLASS()
class CPPMIDDLEPRACTICE_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual AEnemyPrototype* SpawnEnemy() PURE_VIRTUAL(AEnemySpawner::SpawnEnemy, return nullptr;);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp,
		class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AEnemyPrototype* Prototype;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* Collision = nullptr;

};
