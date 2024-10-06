// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyFactory.generated.h"

class AEnemy;
class UStaticMeshComponent;
class UBoxComponent;


UCLASS()
class CPPMIDDLEPRACTICE_API AEnemyFactory : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyFactory();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* SMComp = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* Collision = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AEnemy> SoldierToSpawn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AEnemy> BossToSpawn;
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual AEnemy* CreateSoldier() PURE_VIRTUAL(AEnemyFactory::CreateSoldier, return nullptr;);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual AEnemy* CreateBoss() PURE_VIRTUAL(AEnemyFactory::CreateBoss, return nullptr;);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComponent,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& HitResult) PURE_VIRTUAL(AEnemyFactory::OnOverlapBegin, );

};

UCLASS()
class CPPMIDDLEPRACTICE_API AElvenFactory : public AEnemyFactory
{
	GENERATED_BODY()

public:
	AElvenFactory();

	virtual AEnemy* CreateSoldier() override;

	virtual AEnemy* CreateBoss() override;

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComponent,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& HitResult) override;

	UFUNCTION()
	virtual void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp,
		class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);
};

UCLASS()
class CPPMIDDLEPRACTICE_API ANecroFactory : public AEnemyFactory
{
	GENERATED_BODY()

public:
	ANecroFactory();

	virtual AEnemy* CreateSoldier() override;

	virtual AEnemy* CreateBoss() override;

	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComponent,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& HitResult) override;

	UFUNCTION()
	virtual void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp,
		class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);
};