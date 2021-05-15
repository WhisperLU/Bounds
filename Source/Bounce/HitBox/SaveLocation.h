// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bounce/HitBox/HitBoxBase.h"
#include "SaveLocation.generated.h"

/**
 * 
 */
UCLASS()
class BOUNCE_API ASaveLocation : public AHitBoxBase
{
	GENERATED_BODY()
public:
	ASaveLocation();
	virtual void OnHitSphere(AActor* sphere) override;
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* SaveMeshComp;
};
