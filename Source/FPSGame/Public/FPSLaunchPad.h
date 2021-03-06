// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSLaunchPad.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class UDecalComponent;



UCLASS()
class FPSGAME_API AFPSLaunchPad : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSLaunchPad();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* OverlapComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* LaunchPadBase;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* LaunchPadArrow;

	

	UPROPERTY(EditInstanceOnly, Category = "Launcher")
	float XVelocity = 1000.0f;
	UPROPERTY(EditInstanceOnly, Category = "Launcher")
	float ZVelocity = 1000.0f;
	UPROPERTY(EditInstanceOnly, Category = "Launcher")
	float YVelocity = 0.0f;

	UFUNCTION()
		void LaunchCharacter(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	
	
};
