// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#pragma once

#include "FCardStat.h"
#include "FCardData.h"
#include "CardBlueprintLibrary.generated.h"

UCLASS()
class UCardBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
		/** Starts an analytics session without any custom attributes specified */
	UFUNCTION(BlueprintCallable, Category = "CardStat Query")
		static TArray<FCardStat> GetValidCardStats(FCardData CardData);
};

