
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
	double timeInCycle;
	double separation;
	double maxSpeed;

	
public:	
	USpinnerComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
