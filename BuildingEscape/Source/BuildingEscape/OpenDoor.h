// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Runs a Method to Open the Door
	void OpenDoor();
	void CloseDoor();
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:

	UPROPERTY(EditAnywhere)
		float OpenAngle = -75.f; // Door open angle 90 degrees in private class member

	UPROPERTY(EditAnywhere)
		float CloseDoorDelay = 1.f;

	float DoorLastOpenTime;
	float TimeSinceDoorOpen;

	UPROPERTY(EditAnywhere)
		ATriggerVolume* PressurePlate;
		AActor* ActorThatOpens; // Note Pawn Inherits from actor
		AActor* Owner; // The Owning Door
};
