// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBoxWidget.h"

#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UItemBoxWidget::ShowHPBar(float hp, float maxhp)
{
	hpBar->SetPercent(maxhp / hp);
	txt_boxHP->SetText(FText::AsNumber(maxhp / hp * 10));
}
