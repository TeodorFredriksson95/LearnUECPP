// Fill out your copyright notice in the Description page of Project Settings.


#include "LearnUECPP/Public//Core/Inventory/LearnInventoryComponent.h"

#include "Kismet/KismetSystemLibrary.h"


// Sets default values for this component's properties
ULearnInventoryComponent::ULearnInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;


	for (int i = 0; i < InventorySlots; ++i)
	{
		InventoryItems[i] = FSlotStruct{};
	}


	FSlotStruct InventoryItem;
	InventoryItem.Quantity = 1;
	InventoryItem.ItemID = FName("Apple");
	InventoryItems[0] = InventoryItem;
}


// Called when the game starts
void ULearnInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void ULearnInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                             FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool ULearnInventoryComponent::AddItemToInventory(const FName ItemID, int32 Quantity, int32& OutQuantity)
{
	// This entire function should probably be removed from C++ and the entire flow of functions is what defines
	// the act of "adding to inventory". Looking at the while loop below, it makes no sense to expose
	// UFUNCTIONS defining different inputs and outputs, and then nesting those functions inside this function.
	// I'd have to chain every input and output all the way from this function to the last. That'd be insane.
	// Sleep on it.

	FString DebugText = FString::Printf(
		TEXT("Added %d %s to inventory"),
		Quantity,
		*ItemID.ToString()
	);

	constexpr FLinearColor TextColor = FLinearColor(1.0f, 1.0f, 1.0f);

	UKismetSystemLibrary::PrintString(GetWorld(), DebugText, true, false, TextColor, 4);

	int32 LocalQuantity = Quantity;
	bool bLocalHasFailed = false;

	int32 Index;
	while (LocalQuantity > 0 && !bLocalHasFailed)
	{
		if (FindSlot(ItemID, Index))
		{
			AddToStack(Index, Quantity);
			LocalQuantity--;
		}

		else
		{
			// Check if there are any available slots in inventory

			// if no space
			// bLocalHasFailed = true;

			//else
			// TODO: CreateNewStackImplementation
			// CreateNewStack(FName ItemID, int32 Quantity

			// if successfully added
			// decrement LocalQuantity

			// else
			// bLocalHasFailed = true;
		}
	}


	OutQuantity = LocalQuantity;
	return !bLocalHasFailed;
}

bool ULearnInventoryComponent::FindSlot(FName ItemID, int32& OutIndex)
{
	for (int i = 0; i < InventoryItems.Num(); ++i)
	{
		if (InventoryItems[i].ItemID == ItemID)
		{
			if (GetMaxStackSize(ItemID) < InventoryItems[i].Quantity)
			{
				OutIndex = i;
				return true;
			}
		}
	}

	OutIndex = -1;
	return false;
}

void ULearnInventoryComponent::AddToStack(int32 Index, int32 Quantity)
{
	InventoryItems[Index].Quantity += Quantity;

	FString DebugText = FString::Printf(
		TEXT("Added %d to inventory"),
		InventoryItems[Index].Quantity
	);

	constexpr FLinearColor TextColor = FLinearColor(1.0f, 1.0f, 1.0f);

	UKismetSystemLibrary::PrintString(GetWorld(), DebugText, true, false, TextColor, 4);
}

bool ULearnInventoryComponent::AnyEmptySlotsAvailable(int32& OutIndex)
{
	for (int i = 0; i < InventoryItems.Num(); ++i)
	{
		if (InventoryItems[i].Quantity == 0)
		{
			OutIndex = i;
			return true;
		}
	}

	OutIndex = -1;
	return false;
}
