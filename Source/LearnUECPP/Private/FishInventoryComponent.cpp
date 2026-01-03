// Fill out your copyright notice in the Description page of Project Settings.


#include "LearnUECPP/Public/FishInventoryComponent.h"


// Sets default values for this component's properties
UFishInventoryComponent::UFishInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFishInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void UFishInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                            FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UFishInventoryComponent::AddItem(const FItem& Item)
{
	InventoryItems.Add(Item.ID, Item);
}

bool UFishInventoryComponent::GetItem(FName Key, FItem& Item)
{
	// if map contains Key, return true and output the FItem reference
	if (InventoryItems.Contains(Key))
	{
		Item = InventoryItems[Key];
		return true;
	}
	return false;
}

bool UFishInventoryComponent::RemoveItem(FName Key)
{
	if (InventoryItems.Remove(Key) > 0) return true;

	return false;
}
