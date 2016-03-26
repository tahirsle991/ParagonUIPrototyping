// Fill out your copyright notice in the Description page of Project Settings.

#include "DeckBuilderDesktop.h"
#include "CardBlueprintLibrary.h"


TArray<FCardStat> UCardBlueprintLibrary::GetValidCardStats(FCardData CardData)
{
	TArray<FCardStat> validStats;

	for (TFieldIterator<UProperty> PropIt(CardData.StaticStruct()); PropIt; ++PropIt)
	{
		UProperty* Property = *PropIt;
		// Do something with the property
		if (Property->IsA(UFloatProperty::StaticClass()))
		{
			UFloatProperty *NumericProp = CastChecked<UFloatProperty>(Property);
			float value = NumericProp->GetPropertyValue_InContainer(&CardData);
			if (value != -0.0 && value != 0.0)
			{
				FCardStat stat;
				stat.Type = NumericProp->GetFName();
				stat.Value = FString::Printf(TEXT("%f"), value);
				validStats.Add(stat);
			}
		}
		else if (Property->IsA(UStrProperty::StaticClass()))
		{
			UStrProperty *StrProp = CastChecked<UStrProperty>(Property);
			FString Value = StrProp->GetPropertyValue_InContainer(&CardData);
			if (Value.Len() > 0) 
			{
				FCardStat stat;
				stat.Type = StrProp->GetFName();
				stat.Value = Value;
				validStats.Add(stat);
			}
		}
	}

	return validStats;
}
