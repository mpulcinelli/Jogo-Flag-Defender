// Fill out your copyright notice in the Description page of Project Settings.

#include "Projetil.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include <GameFramework/ProjectileMovementComponent.h>


// Sets default values
AProjetil::AProjetil()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	if (!ensure(SphereComponent != nullptr))return;

	RootComponent = SphereComponent;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	if (!ensure(StaticMeshComponent != nullptr))return;

	StaticMeshComponent->SetupAttachment(RootComponent);

	ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystemComponent"));
	if (!ensure(ParticleSystemComponent != nullptr))return;
	ParticleSystemComponent->SetupAttachment(RootComponent);
	
	
	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	if (!ensure(ProjectileMovementComponent != nullptr))return;

	ProjectileMovementComponent->UpdatedComponent = RootComponent;
	
	ProjectileMovementComponent->InitialSpeed = 10000.0f;
	ProjectileMovementComponent->MaxSpeed = 10000.0f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
	ProjectileMovementComponent->bShouldBounce = false;
}

// Called when the game starts or when spawned
void AProjetil::BeginPlay()
{
	Super::BeginPlay();
	
	if (SphereComponent != nullptr) {
		SphereComponent->SetNotifyRigidBodyCollision(true);
		SphereComponent->OnComponentHit.AddDynamic(this, &AProjetil::OnSphereColisionHit);
	}

}

void AProjetil::OnSphereColisionHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("OnSphereColisionHit"));
	Destroy();
}


