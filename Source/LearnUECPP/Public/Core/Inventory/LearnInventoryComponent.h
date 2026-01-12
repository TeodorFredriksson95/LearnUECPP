// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LearnInventoryComponent.generated.h"

USTRUCT(BlueprintType)
struct FInventoryItem : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText ItemName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText Description;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UTexture2D* Thumbnail = nullptr;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<AActor> ItemClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 StackSize = 0;
};

USTRUCT(BlueprintType)
struct FSlotStruct
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	FName ItemID = NAME_None;

	UPROPERTY(BlueprintReadWrite)
	int32 Quantity = 0;
};

UCLASS(Blueprintable, BlueprintType)
class LEARNUECPP_API ULearnInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	ULearnInventoryComponent();

	TArray<FSlotStruct> InventoryItems;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FDataTableRowHandle ItemDataTable;

	UPROPERTY(EditAnywhere)
	int32 InventorySlots = 16;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	bool AddItemToInventory(FName ItemID, int32 Quantity, int32& OutQuantity);

	UFUNCTION(BlueprintCallable, meta=(ReturnDisplayName="FoundSlot"))
	bool FindSlot(FName ItemID, int32& OutIndex);

	// UFUNCTION(BlueprintCallable)
	// int32 GetMaxStackSize(FName ItemID, UDataTable* DataTable);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	int32 GetMaxStackSize(FName ItemID) const;

	UFUNCTION(BlueprintCallable)
	void AddToStack(int32 Index, int32 Quantity);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool AnyEmptySlotsAvailable(int32& OutIndex);
};
