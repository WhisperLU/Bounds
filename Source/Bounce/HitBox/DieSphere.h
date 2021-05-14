// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HitBoxBase.h"
#include "DieSphere.generated.h"

/**
 * 
 */
UCLASS()
class BOUNCE_API ADieSphere : public AHitBoxBase
{
	GENERATED_BODY()

public:
	//定义一个vector向量来代替小球的位置
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector sphereVEC;


	virtual void OnHitSphere(class AActor* sphere) override;
};
