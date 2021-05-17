// Copyright Epic Games, Inc. All Rights Reserved.


#include "BounceGameModeBase.h"
#include "Engine.h"
#include "Bounce/Player/SphereBase.h"

ABounceGameModeBase::ABounceGameModeBase()
{
	PrimaryActorTick.bCanEverTick = true;
	PlayerDieNumber = 0.0f;
	IsEnd = false;
}

void ABounceGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	//cast pawn，把我们新建的playpawn赋值
	ASphereBase* TempPawn = Cast<ASphereBase>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (TempPawn)
	{
		PlayPawn = TempPawn;
		CurrentStart = PlayPawn->GetActorLocation();
	}
}

void ABounceGameModeBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

//设置playpawn的位置 存档点
void ABounceGameModeBase::SetPlayerLocation()
{
	PlayPawn->SetActorLocation(CurrentStart);
	PlayPawn->SphereMeshComp->SetPhysicsLinearVelocity(FVector(0, 0, 0));
	PlayPawn->SphereMeshComp->SetPhysicsAngularVelocityInDegrees(FVector(0, 0, 0));
	PlayerDieNumber++;

}

//设置playpawn的位置  特殊位置
void ABounceGameModeBase::SetPlayerLocation(FVector Start)
{
	PlayPawn->SetActorLocation(Start);
	PlayPawn->SphereMeshComp->SetPhysicsLinearVelocity(FVector(0, 0, 0));
	PlayPawn->SphereMeshComp->SetPhysicsAngularVelocityInDegrees(FVector(0, 0, 0));
}

void ABounceGameModeBase::SetPlayerInput(bool isInput)
{
	PlayPawn->IsInput = isInput;
	if (!isInput)
	{
		IsEnd = true;
	}
}

void ABounceGameModeBase::SetCurrentStart(FVector Location)
{
	if (Location != FVector(0, 0, 0))
	{
		CurrentStart = Location;
	}
}
