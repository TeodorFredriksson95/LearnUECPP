// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyTestComponent.generated.h"


UCLASS(Blueprintable, BlueprintType)
class LEARNUECPP_API UMyTestComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMyTestComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	AActor* MyGetActorOfClass(TSubclassOf<AActor> myActor);

	void MyPosses(APawn* MyPawn) const;
};
