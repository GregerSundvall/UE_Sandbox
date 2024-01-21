
#include "SpinnerComponent.h"

#include "InterchangeResult.h"

USpinnerComponent::USpinnerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	actor = GetOwner();
	rotationToAdd = new FQuat(0, 0, 0, 1);
}


void USpinnerComponent::BeginPlay()
{
	Super::BeginPlay();

	cycleDuration = 3;
	separation = 0.6;
	timeInCycle = 0;
	maxSpeed = 4;
}


void USpinnerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	timeInCycle = FMath::Fmod(timeInCycle + DeltaTime, cycleDuration);
	
	double x = FMath::Sin(timeInCycle * ((2 * PI) / cycleDuration) - (PI/2)) * separation -separation +1;
	double y = FMath::Sin(timeInCycle * ((2 * PI) / cycleDuration) - (PI/2) - (2 * PI / 3)) * separation -separation +1;
	double z = FMath::Sin(timeInCycle * ((2 * PI) / cycleDuration) - (PI/2) - 2 * (2 * PI / 3)) * separation -separation +1;

	UE_LOG(LogTemp, Warning, TEXT("%f"), FMath::Max(0, x) );
	UE_LOG(LogTemp, Warning, TEXT("%f"), FMath::Max(0, y) );
	UE_LOG(LogTemp, Warning, TEXT("%f"), FMath::Max(0, z) );
	UE_LOG(LogTemp, Warning, TEXT(" "));
	
	rotationToAdd->X = FMath::Max(0, x)* maxSpeed * DeltaTime;
	rotationToAdd->Y = FMath::Max(0, y)* maxSpeed * DeltaTime;
	rotationToAdd->Z = FMath::Max(0, z)* maxSpeed * DeltaTime;
	actor->AddActorLocalRotation(*rotationToAdd);
}

