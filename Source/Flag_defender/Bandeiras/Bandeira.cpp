// Fill out your copyright notice in the Description page of Project Settings.

#include "Bandeira.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
ABandeira::ABandeira()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh_Bandeira = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh_Bandeira"));
	RootComponent = Mesh_Bandeira;

}

// Called when the game starts or when spawned
void ABandeira::BeginPlay()
{
	Super::BeginPlay();
	Mesh_Bandeira->OnComponentBeginOverlap.AddDynamic(this, &ABandeira::FlagColetada);
}

void ABandeira::FlagColetada(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("FlagColetada.."));
	Destroy();
}

// Called every frame
void ABandeira::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

