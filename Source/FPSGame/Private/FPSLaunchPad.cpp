// Fill out your copyright notice in the Description page of Project Settings.

#include "FPSLaunchPad.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "FPSCharacter.h"
#include "GameFramework/Character.h"
#include "Components/DecalComponent.h"




// Sets default values
AFPSLaunchPad::AFPSLaunchPad()
{
	OverlapComp = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComp"));
	//OverlapComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	//OverlapComp->SetCollisionResponseToAllChannels(ECR_Ignore);
	//OverlapComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	OverlapComp->SetBoxExtent(FVector(129.0f, 90.0f, 50.0f));
	RootComponent = OverlapComp;
	

	LaunchPadBase = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LaunchPadBase"));
	LaunchPadBase->SetRelativeScale3D(FVector(1.0f, 0.7f, 0.05f));
	LaunchPadBase->SetupAttachment(RootComponent);

	LaunchPadArrow = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LaunchPadArrow"));
	LaunchPadArrow->SetRelativeLocation(FVector(0.0f, 0.0f, 10.0f));
	LaunchPadArrow->SetupAttachment(RootComponent);

	OverlapComp->OnComponentBeginOverlap.AddDynamic(this, &AFPSLaunchPad::LaunchCharacter);
}

// Called when the game starts or when spawned
void AFPSLaunchPad::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFPSLaunchPad::LaunchCharacter(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AFPSCharacter* MyPawn = Cast<AFPSCharacter>(OtherActor);
	FVector ForwardVector;
	ForwardVector = GetActorForwardVector();
	if (MyPawn)
	{		
		MyPawn->LaunchCharacter(FVector((ForwardVector.X*XVelocity), (ForwardVector.Y*YVelocity), ZVelocity), true, true);
	}
	else if (OtherComp && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulse(FVector((ForwardVector.X*XVelocity), (ForwardVector.Y*YVelocity), ZVelocity), NAME_None,true);
		UE_LOG(LogTemp, Warning, TEXT("Trying to Launch Box"));
	}

}

