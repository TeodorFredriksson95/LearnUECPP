// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FishInventoryComponent.generated.h"

USTRUCT(BlueprintType)
struct FItem
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	FName ID;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FText ItemName;

	UPROPERTY(BlueprintReadWrite)
	int32 Quantity;
};

UENUM(BlueprintType)
enum class EMyEnum : uint8
{
	ThingOne,
	ThingTwo,
	ThingThree
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), BlueprintType, Blueprintable)
class LEARNUECPP_API UFishInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UFishInventoryComponent();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<FName, FItem> InventoryItems;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, DisplayName="Add Item Two")
	void AddItem(const FItem& Item);

	UFUNCTION(BlueprintCallable, BlueprintPure, meta=(ReturnDisplayName ="Success"))
	bool GetItem(FName Key, FItem& Item);

	UFUNCTION(BlueprintCallable)
	bool RemoveItem(FName Key);
};
