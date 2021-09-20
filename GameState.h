#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "GameState.generated.h"

UCLASS()
class NOWHERE_API AGameState : public AGameStateBase
{
	GENERATED_BODY()

public:

	AGameState();

	/* State of day vs. night */
	bool bIsNight;

	/* Time in wallclock hours the day begins */
	float SunriseTimeMark;

	/* Time in wallclock hours the night begins */
	float SunsetTimeMark;

	/* Is it nighttime? */
	bool GetIsNight();

	/* Get and set if it is nighttime */
	bool GetAndUpdateIsNight();

	/* Current time of day in the gamemode represented in full minutes */
	UPROPERTY(BlueprintReadOnly, Category = "TimeOfDay")
	int32 ElapsedGameMinutes;

	/* Conversion of 1 second real time to X seconds gametime of the day/night cycle */
	UPROPERTY(EditDefaultsOnly, Category = "TimeOfDay")
	float TimeScale;

	/* Returns the time of day increment every real second (converted to accelerated game time, eg. 1 real second is 1 minute in time of day increment) */
	float GetTimeOfDayIncrement();

	/* Returns how many days have passed since the game started */
	UFUNCTION(BlueprintCallable, Category = "TimeOfDay")
	int32 GetElapsedDays();

	/* Returns whole days elapsed, represented in minutes */
	UFUNCTION(BlueprintCallable, Category = "TimeOfDay")
	int32 GetElapsedFullDaysInMinutes();

	/* Return the time in real seconds till next sunrise */
	UFUNCTION(BlueprintCallable, Category = "TimeOfDay")
	int32 GetRealSecondsTillSunrise();

	/* Get number of minutes passed in the current 24-hour block */
	int32 GetElapsedMinutesCurrentDay();

	/* By passing in "exec" we expose it as a command line (press ~ to open) */
	UFUNCTION(exec)
	void SetTimeOfDay(float NewHourOfDay);
};
