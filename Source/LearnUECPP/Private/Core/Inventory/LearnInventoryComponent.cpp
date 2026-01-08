// Fill out your copyright notice in the Description page of Project Settings.


#include "LearnUECPP/Public//Core/Inventory/LearnInventoryComponent.h"

#include "Kismet/KismetSystemLibrary.h"


// Sets default values for this component's properties
ULearnInventoryComponent::ULearnInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
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
			// TODO: AddToStack function implementation
			// AddToStack(Index, Quantity)

			// TODO: decrement local quantity
			// LocalQuantity--;
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


// int32 ULearnInventoryComponent::GetMaxStackSize(FName ItemID, UDataTable* DataTable)
// {
// 	if (!DataTable)
// 	{
// 		UE_LOG(LogTemp, Warning, TEXT("DataTable is NULL"));
// 		return -1;
// 	}
//
// 	const FInventoryItem* InventoryItem = DataTable->FindRow<FInventoryItem>(ItemID, "");
//
// 	if (!InventoryItem)
// 	{
// 		return -1;
// 	}
//
// 	return InventoryItem->StackSize;
// }
