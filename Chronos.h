// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Chronos.generated.h"

UCLASS(Abstract)
class NOWHERE_API AChronos : public AActor
{
	GENERATED_BODY()
	
public:	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	//  
	void UpdateSkylight();

	/* Primary sun of the level. Assigned in Blueprint during BeginPlay (BlueprintReadWrite is required as tag instead of EditDefaultsOnly) */
	UPROPERTY(BlueprintReadWrite, Category = "DayNight")
	class ADirectionalLight* PrimarySunLight;
	
	UPROPERTY(BlueprintReadWrite, Category = "DayNight")
	class ASkyLight* SkyLightActor;

	/* Last local time of day to apply sun movement prediction */
	float LastTimeOfDay;

	/* Delta seconds since the time of day was last updated */
	float TimeSinceLastIncrement;


protected:
	// Sets default values for this actor's properties
	AChronos();

	/* Cached bool of bIsNight to determine when we entered/left the night */
	bool LastNightState;

	/* Sunbrightness as specified in the level (considered as daytime sun) */
	float OriginalSunBrightness;

	/* Target brightness to lerp towards */
	float TargetSunBrightness;

	/* Last skylight intensity that was captured */
	float LastCapturedIntensity;

	/* Maps intensity to time of day */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DayNight")
	class UCurveFloat* SkylightIntensityCurve;

	/* Maps skylight color to time of day */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DayNight")
	class UCurveVector* SkylightColorCurve;

	
private:	

};
