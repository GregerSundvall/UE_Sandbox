
#include "SpinnerComponent.h"

USpinnerComponent::USpinnerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	actor = GetOwner();
	rotationToAdd = new FQuat(0, 0, 0, 1);
	timeInCycle = 0;
	cycleDuration = 3;
	separation = 0.5;
	maxSpeed = 4;
}

void USpinnerComponent::BeginPlay()
{
	Super::BeginPlay();
}

void USpinnerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	timeInCycle = FMath::Fmod(timeInCycle + DeltaTime, cycleDuration);
	
	double x = FMath::Sin(timeInCycle * ((2 * PI) / cycleDuration) - (PI/2)) * maxSpeed  * separation -separation +1;
	double y = FMath::Sin(timeInCycle * ((2 * PI) / cycleDuration) - (PI/2) - (2 * PI / 3)) * maxSpeed  * separation -separation +1;
	double z = FMath::Sin(timeInCycle * ((2 * PI) / cycleDuration) - (PI/2) - 2 * (2 * PI / 3)) * maxSpeed  * separation -separation +1;
	
	rotationToAdd->X = FMath::Max(0, x) * DeltaTime;
	rotationToAdd->Y = FMath::Max(0, y) * DeltaTime;
	rotationToAdd->Z = FMath::Max(0, z) * DeltaTime;
	actor->AddActorLocalRotation(*rotationToAdd);
}

