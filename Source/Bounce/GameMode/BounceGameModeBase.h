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

public:
	// UFUNCTION(BlueprintCallable, Category = "SetLocation")
	void SetPlayerLocation();
	void SetPlayerLocation(FVector Start);

	void SetCurrentStart(FVector Location);
};
