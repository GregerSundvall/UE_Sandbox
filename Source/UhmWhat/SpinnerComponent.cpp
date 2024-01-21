
#include "SpinnerComponent.h"

USpinnerComponent::USpinnerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	actor = GetOwner();
	rotationToAdd = new FQuat(0, 0, 0, 1);
}


void USpinnerComponent::BeginPlay()
{
	Super::BeginPlay();

	cycleDuration = 100;
	phaseShiftY = cycleDuration / 3;
	phaseShiftZ = phaseShiftY * 2;
	
	
	minSpeed = 0.3;
	maxSpeed = 50;
	
	currentValueX = 0;
	currentValueY = cycleDuration / 3;
	currentValueZ = currentValueY * 2;
		
	phase = 2 * PI / cycleDuration;
	// phaseShift = (PI / 2);
	amplitude = amplitudeNormalizer * (maxSpeed - minSpeed * 2);
	amplitudeShift = 0.5 * maxSpeed + minSpeed;
	peakSharpness = 1;
}


void USpinnerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	currentValueX = FMath::Fmod(currentValueX + DeltaTime, cycleDuration);
	currentValueY = FMath::Fmod(currentValueY + DeltaTime, cycleDuration);
	currentValueZ = FMath::Fmod(currentValueZ + DeltaTime, cycleDuration);
	
	// currentValueX += DeltaTime;
	// if(currentValueX >= cycleDuration) currentValueX = 0;
	// currentValueY += DeltaTime;
	// if(currentValueY >= cycleDuration) currentValueY = 0;
	// currentValueZ += DeltaTime;
	// if(currentValueZ >= cycleDuration) currentValueZ = 0;
	
	// UE_LOG(LogTemp, Warning, TEXT("%f"), currentValueY)
	// UE_LOG(LogTemp, Warning, TEXT("%f"), currentValueZ)
	// UE_LOG(LogTemp, Warning, TEXT(" "))

	
	
	rotationToAdd->X = GetValue(currentValueX) * DeltaTime;
	rotationToAdd->Y = GetValue(currentValueY) * DeltaTime;
	rotationToAdd->Z = GetValue(currentValueZ) * DeltaTime;
	UE_LOG(LogTemp, Warning, TEXT("%f"), currentValueX);
	actor->AddActorLocalRotation(*rotationToAdd);
}

double USpinnerComponent::GetValue(double const cycleValue)
{
	double sin1 = 0.1 * FMath::Sin(cycleValue * maxSpeed * PI * (6 / cycleDuration));
	double sin2 = 0.9 * FMath::Sin(cycleValue * maxSpeed * PI * (2 / cycleDuration) + (PI / 3));
	
	return FMath::Max(minSpeed, sin1 + sin2);
}

double USpinnerComponent::GetValueOnCurve(double const cycleValue)
{
	return (amplitude * FMath::Sin(cycleValue * phase) + amplitudeShift) * peakSharpness;
}
