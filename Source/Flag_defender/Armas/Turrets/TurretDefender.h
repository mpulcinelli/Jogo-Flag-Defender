// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TurretDefender.generated.h"

UCLASS()
class FLAG_DEFENDER_API ATurretDefender : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATurretDefender();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* Mesh_Turret_Tripod_Inferior;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* Mesh_Turret_Tripod_Superior;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* Mesh_Turret_Gun_default;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* Mesh_Turret_UnderPlate_default;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* Mesh_Turret_Chrgmtr_default;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* Mesh_Turret_Bolts_default;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UAISenseConfig_Sight* SenseConfig;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UAIPerceptionComponent* PerceptionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class TSubclassOf<class AProjetil> ProjetilParaTurret;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	class UParticleSystem* ParticleSystem;


	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UArrowComponent* PositionToSpawn;

	UFUNCTION()
	void OnPerceptionUpdate(const TArray<AActor*>& UpdatedActors);

	class AFlag_defenderCharacter* TargerActor;

	FRotator RotacaoInicialTurret;

	void UpdateTurretPosition();

	void StartFire();

	void StopFire();

	void Firing();

	FTimerHandle TimerHandle_TurretFire;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
