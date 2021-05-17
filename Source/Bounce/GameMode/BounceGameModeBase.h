// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BounceGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class BOUNCE_API ABounceGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	ABounceGameModeBase();
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="PlayPawn")
	class ASphereBase* PlayPawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CurrentStart")
	FVector CurrentStart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerDieNumber")
	int32 PlayerDieNumber;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsEnd;
public:
	UFUNCTION(BlueprintCallable)
	void SetPlayerLocation();
	
	void SetPlayerLocation(FVector Start);
	
	UFUNCTION(BlueprintCallable)
	void SetPlayerInput(bool isInput);
	
	UFUNCTION(BlueprintCallable)
	void SetCurrentStart(FVector Location);
};
