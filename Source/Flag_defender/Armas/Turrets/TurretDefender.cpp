// Fill out your copyright notice in the Description page of Project Settings.

#include "TurretDefender.h"
#include <Components/StaticMeshComponent.h>
#include <Perception/AIPerceptionComponent.h>
#include <Perception/AISenseConfig_Sight.h>
#include "Flag_defenderCharacter.h"
#include <Kismet/KismetMathLibrary.h>


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
	
	SenseConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SenseConfig"));
	SenseConfig->DetectionByAffiliation.bDetectEnemies = true;
	SenseConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SenseConfig->DetectionByAffiliation.bDetectNeutrals = true;

	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComponent"));

	PerceptionComponent->ConfigureSense(*SenseConfig);
	PerceptionComponent->SetDominantSense(SenseConfig->GetSenseImplementation());

}

// Called when the game starts or when spawned
void ATurretDefender::BeginPlay()
{
	Super::BeginPlay();
	
	RotacaoInicialTurret = GetActorRotation();

	PerceptionComponent->OnPerceptionUpdated.AddDynamic(this, &ATurretDefender::OnPerceptionUpdate);
}

void ATurretDefender::OnPerceptionUpdate(const TArray<AActor*>& UpdatedActors)
{
	//UE_LOG(LogTemp, Warning, TEXT("OnPerceptionUpdate"));

	TArray<AActor*> UpdActors;
	PerceptionComponent->GetCurrentlyPerceivedActors(nullptr, UpdActors);

	if (UpdActors.Num() > 0) {
		
		for (int i=0;i<UpdActors.Num();i++)
		{
			TargerActor = Cast<AFlag_defenderCharacter>(UpdActors[i]);

			if (TargerActor != nullptr) {
				UpdateTurretPosition();
				break;
			}
			else
			{
				TargerActor = nullptr;
				Mesh_Turret_Tripod_Superior->SetRelativeRotation(RotacaoInicialTurret);
			}
		}
	}
	else
	{
		TargerActor = nullptr;
		Mesh_Turret_Tripod_Superior->SetRelativeRotation(RotacaoInicialTurret);
	}
}


void ATurretDefender::UpdateTurretPosition()
{
	if (TargerActor == nullptr) return;

	FVector StartLocation = GetActorLocation();
	FVector EndLocation = TargerActor->GetActorLocation();

	FRotator MyActRotation = UKismetMathLibrary::FindLookAtRotation(StartLocation, EndLocation);

	FRotator MyArmActRotation = FRotator(0, 0, 0);

	MyArmActRotation.Pitch = MyActRotation.Pitch;

	Mesh_Turret_Gun_default->SetRelativeRotation(MyArmActRotation);

	MyActRotation.Pitch = RotacaoInicialTurret.Pitch;

	Mesh_Turret_Tripod_Superior->SetRelativeRotation(MyActRotation);
}

// Called every frame
void ATurretDefender::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UpdateTurretPosition();
}

// Called to bind functionality to input
void ATurretDefender::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

