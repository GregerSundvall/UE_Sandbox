// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

UCLASS()
class UHMWHAT_API APickup : public AActor
{
	GENERATED_BODY()

	FQuat* rotationToAdd;
	// FVector3d* TickRotation;
	
	double cycleDuration;
	double minSpeed;
	double maxSpeed;
	double cycleValueX;
	double cycleValueY;
	double cycleValueZ;
	double valueX;
	double valueY;
	double valueZ;
	double valueXSign;
	double valueYSign;
	double valueZSign;

private:
	double GetValueOnCurve(double current);
	
public:	
	// Sets default values for this actor's properties
	APickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
