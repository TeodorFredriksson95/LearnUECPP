// Fill out your copyright notice in the Description page of Project Settings.


#include "LearnUECPP/Public/MyTestComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UMyTestComponent::UMyTestComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMyTestComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void UMyTestComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

AActor* UMyTestComponent::MyGetActorOfClass(TSubclassOf<AActor> myActor)
{
	return UGameplayStatics::GetActorOfClass(GetWorld(), myActor);
}

void UMyTestComponent::MyPosses(APawn* MyPawn) const
{
	APlayerController* pc = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	pc->Possess(MyPawn);
}
