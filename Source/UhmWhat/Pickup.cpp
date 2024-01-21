
#include "Pickup.h"


APickup::APickup()
{
	PrimaryActorTick.bCanEverTick = true;
	rotationToAdd = new FQuat(0, 0, 0, 1);
}

void APickup::BeginPlay()
{
	Super::BeginPlay();

	cycleDuration = 3;
	minSpeed = 0;
	maxSpeed = 4;
	
	cycleValueX = 0;
	cycleValueY = cycleDuration / 3;
	cycleValueZ = cycleValueY * 2;
}

double APickup::GetValueOnCurve(double current)
{
	return 0.5 * FMath::Sin((current / cycleDuration) * (2 * PI) - (PI / 2)) + 0.5;
}


void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	cycleValueX += DeltaTime;
	if(cycleValueX >= cycleDuration) cycleValueX = 0;
	cycleValueY += DeltaTime;
	if(cycleValueY >= cycleDuration) cycleValueY = 0;
	cycleValueZ += DeltaTime;
	if(cycleValueZ >= cycleDuration) cycleValueZ = 0;
	
	rotationToAdd->X = GetValueOnCurve(cycleValueX) * maxSpeed * DeltaTime;
	rotationToAdd->Y = GetValueOnCurve(cycleValueY) * maxSpeed * DeltaTime;
	rotationToAdd->Z = GetValueOnCurve(cycleValueZ) * maxSpeed * DeltaTime;
	AddActorLocalRotation(*rotationToAdd);
	
}

