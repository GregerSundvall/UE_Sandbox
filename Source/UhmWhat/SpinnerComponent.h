
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpinnerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UHMWHAT_API USpinnerComponent : public UActorComponent
{
	GENERATED_BODY()

	FQuat* rotationToAdd;
	AActor* actor;

	double cycleDuration;
	double cyclePosition;
	double phaseShiftY;
	double phaseShiftZ;


	
	double minSpeed;
	double maxSpeed;
	double currentValueX;
	double currentValueY;
	double currentValueZ;


	
	double phase;
	double phaseShift;
	double amplitude;
	double amplitudeShift;
	double const amplitudeNormalizer = 0.5;
	double peakSharpness;
	
	double GetValueOnCurve(double cycleValue);
	
public:	
	USpinnerComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	double       GetValue(double cycleValue);
};
