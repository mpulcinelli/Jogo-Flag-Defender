// Fill out your copyright notice in the Description page of Project Settings.

#include "TurretDefender.h"
#include <Components/StaticMeshComponent.h>


// Sets default values
ATurretDefender::ATurretDefender()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh_Turret_Tripod_Inferior = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh_Turret_Tripod_Inferior"));
	if (!ensure(Mesh_Turret_Tripod_Inferior != nullptr)) return;
	
	Mesh_Turret_Tripod_Superior = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh_Turret_Tripod_Superior"));
	if (!ensure(Mesh_Turret_Tripod_Superior != nullptr)) return;

	Mesh_Turret_Gun_default = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh_Turret_Gun_default"));
	if (!ensure(Mesh_Turret_Gun_default != nullptr)) return;

	Mesh_Turret_UnderPlate_default = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh_Turret_UnderPlate_default"));
	if (!ensure(Mesh_Turret_UnderPlate_default != nullptr)) return;

	Mesh_Turret_Chrgmtr_default = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh_Turret_Chrgmtr_default"));
	if (!ensure(Mesh_Turret_Chrgmtr_default != nullptr)) return;

	Mesh_Turret_Bolts_default = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh_Turret_Bolts_default"));
	if (!ensure(Mesh_Turret_Bolts_default != nullptr)) return;

	Mesh_Turret_Tripod_Inferior->SetupAttachment(RootComponent);

	Mesh_Turret_Tripod_Superior->SetupAttachment(Mesh_Turret_Tripod_Inferior);
	Mesh_Turret_Bolts_default->SetupAttachment(Mesh_Turret_Tripod_Superior);

	Mesh_Turret_Gun_default->SetupAttachment(Mesh_Turret_Tripod_Superior);
	Mesh_Turret_UnderPlate_default->SetupAttachment(Mesh_Turret_Gun_default);
	Mesh_Turret_Chrgmtr_default->SetupAttachment(Mesh_Turret_Gun_default);
	

}

// Called when the game starts or when spawned
void ATurretDefender::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATurretDefender::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATurretDefender::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

