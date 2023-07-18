#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DogCreature.generated.h"

/** Please add a class description */
UCLASS(Blueprintable, BlueprintType, Abstract)
class BELUGA_API UDogCreature : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
		FString CPP_Hello();

	UFUNCTION(BlueprintCallable)
		FName CPP_GetName();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
		void BP_SetHelloMessage();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
		void BOTH_Update();

public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	FName Name;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
	int32 MaxHP;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default", Transient)
	int32 CurrentHP;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FString HelloMsg;
};