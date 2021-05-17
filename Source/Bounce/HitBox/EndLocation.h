// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bounce/HitBox/HitBoxBase.h"
#include "EndLocation.generated.h"

/**
 * 
 */
UCLASS()
class BOUNCE_API AEndLocation : public AHitBoxBase
{
	GENERATED_BODY()

public:
	AEndLocation();

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	class UStaticMeshComponent* EndMeshComp;
	
public:
	
	virtual void OnHitSphere(AActor* sphere) override;
	
};
