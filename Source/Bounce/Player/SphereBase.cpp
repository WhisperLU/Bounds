// Fill out your copyright notice in the Description page of Project Settings.


#include "SphereBase.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/InputComponent.h"
#include "Engine.h"

// Sets default values
ASphereBase::ASphereBase()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//初始化值
	IsInput = true;
	SphereSpeed = 200.0f;
	SpeedMax = 500.0f;
	SpeedMin = SphereSpeed;

	SphereMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereMeshComp"));
	SphereMeshComp->SetSimulatePhysics(true);

	CameraArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraArmComp"));
	CameraArmComp->SetupAttachment(SphereMeshComp);
	CameraArmComp->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));

	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(CameraArmComp);

}

// Called when the game starts or when spawned
void ASphereBase::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASphereBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	//输入事件且FVector都不为0，小球受力执行函数
	if (IsInput && AngularVector != FVector(0, 0, 0))
	{
		SphereMeshComp->SetPhysicsAngularVelocityInDegrees(AngularVector);
	}
}

// Called to bind functionality to input
void ASphereBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	//轴映射
	PlayerInputComponent->BindAxis("MoveForward", this, &ASphereBase::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASphereBase::MoveRight);
	//按键映射
	PlayerInputComponent->BindAction("SpeedUp", IE_Pressed, this, &ASphereBase::SpeedUp);
	PlayerInputComponent->BindAction("SpeedUp", IE_Released, this, &ASphereBase::SpeedLow);
}

void ASphereBase::MoveForward(float val)
{
	if (IsInput)
	{
		AngularVector.Y = SphereSpeed * val;
	}
}

void ASphereBase::MoveRight(float val)
{
	if (IsInput)
	{
		AngularVector.X = SphereSpeed * val;
	}
}

void ASphereBase::SpeedUp()
{
	SphereSpeed = SpeedMax;
}

void ASphereBase::SpeedLow()
{
	SphereSpeed = SpeedMin;
}
