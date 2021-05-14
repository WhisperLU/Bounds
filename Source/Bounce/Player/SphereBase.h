// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SphereBase.generated.h"

UCLASS()
class BOUNCE_API ASphereBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASphereBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaticMesh")
	class UStaticMeshComponent* SphereMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraArm")
	class USpringArmComponent* CameraArmComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraArm")
	class UCameraComponent* CameraComp;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsInput;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "SphereSpeed")
	float SphereSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "SphereSpeed")
	float SpeedMax;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category= "SphereSpeed")
	float SpeedMin;

	FVector AngularVector;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input ///pawn默认带有的输入映射函数
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UFUNCTION(BlueprintCallable, Category = "MoveForward")
	void MoveForward(float val);
	UFUNCTION(BlueprintCallable, Category = "MoveRight")
	void MoveRight(float val);
	UFUNCTION(BlueprintCallable, Category = "MoveRight")
	void SpeedUp();
	UFUNCTION(BlueprintCallable, Category = "MoveRight")
	void SpeedLow();
};
