// Fill out your copyright notice in the Description page of Project Settings.


#include "Bounce/HitBox/SaveLocation.h"
#include "Engine.h"
#include "Bounce/GameMode/BounceGameModeBase.h"
#include "Components/StaticMeshComponent.h"


ASaveLocation::ASaveLocation()
{
	SaveMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
}

void ASaveLocation::OnHitSphere(AActor* sphere)
{
	ABounceGameModeBase* TempGMBase = Cast<ABounceGameModeBase>(GetWorld()->GetAuthGameMode());

	TempGMBase->SetCurrentStart(HitBoxComp->GetComponentLocation());
}
