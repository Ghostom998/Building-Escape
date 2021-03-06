// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;


private:
	//How far the player can reach
	float reach = 100.f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
		
	UInputComponent* InputComponent = nullptr;

	/// Ray-cast and grab what is within reach
	void Grab();
	void Release();

	void SetupInputComponent();
	void FindPhysicsHandleComponent();

	const FHitResult GetFirstPhyicsBodyInReach();

	// The Players reach start and end points
	FVector GetReachLineStart();
	FVector GetReachLineEnd();
	

};
