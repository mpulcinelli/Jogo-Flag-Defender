// Fill out your copyright notice in the Description page of Project Settings.

#include "TurretDefender.h"


// Sets default values
ATurretDefender::ATurretDefender()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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

