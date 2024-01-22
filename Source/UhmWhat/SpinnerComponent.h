
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

	UPROPERTY(EditAnywhere, Category=Attributes)
	double cycleDuration;
	UPROPERTY(EditAnywhere, Category=Attributes)
	double separation;
	UPROPERTY(EditAnywhere, Category=Attributes)
	double maxSpeed;

	double timeInCycle;
	
public:	
	USpinnerComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
