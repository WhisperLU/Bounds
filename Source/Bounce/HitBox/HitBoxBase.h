// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HitBoxBase.generated.h"

UCLASS()
class BOUNCE_API AHitBoxBase : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AHitBoxBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UBoxComponent* HitBoxComp;
	
	//申明一个类似于OverLap的方法
	UFUNCTION(BlueprintCallable, Category = "BeginHit")
	void BeginHit(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	              int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void OnHitSphere(class AActor* sphere);
};
