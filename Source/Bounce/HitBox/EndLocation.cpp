// Fill out your copyright notice in the Description page of Project Settings.


#include "Bounce/HitBox/EndLocation.h"
#include "Bounce/GameMode/BounceGameModeBase.h"
#include "Components/StaticMeshComponent.h"
#include "Engine.h"

AEndLocation::AEndLocation()
{
	EndMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EndMeshComp"));
	HitBoxComp->SetupAttachment(EndMeshComp);

}

void AEndLocation::OnHitSphere(AActor* sphere)
{
	ABounceGameModeBase* TempGMBase = Cast<ABounceGameModeBase>(GetWorld()->GetAuthGameMode());
	TempGMBase->SetPlayerInput(false);
}
