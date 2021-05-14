// Fill out your copyright notice in the Description page of Project Settings.


#include "DieSphere.h"
#include "Bounce/Player/SphereBase.h"
#include "Engine.h"
#include "Bounce/Gamemode/BounceGameModeBase.h"

//小球回到设置的sphereVEC的位置
void ADieSphere::OnHitSphere(class AActor* sphere)
{
	ABounceGameModeBase* TempGMBase = Cast<ABounceGameModeBase>(GetWorld()->GetAuthGameMode());
	TempGMBase->SetPlayerLocation();
}
