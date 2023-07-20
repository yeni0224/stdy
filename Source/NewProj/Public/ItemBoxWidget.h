// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemBoxWidget.generated.h"

/**
 * 
 */
UCLASS()
class NEWPROJ_API UItemBoxWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UProgressBar* hpBar;
	UPROPERTY(EditDefaultsOnly, meta = (BindWidget))
	class UTextBlock* txt_boxHP;

	void ShowHPBar(float hp, float maxhp);
};
