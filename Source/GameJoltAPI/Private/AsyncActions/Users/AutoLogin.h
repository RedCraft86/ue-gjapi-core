// Copyright by Free2Play-Entertainment (2020)

#pragma once

#include "CoreMinimal.h"
#include "GameJoltAsyncBase.h"
#include "AutoLogin.generated.h"

class UGameJolt;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAutoLoginSuccesDelegate);

/**
 * 
 */
UCLASS()
class GAMEJOLTAPI_API UAutoLogin : public UGameJoltAsyncBase
{
	GENERATED_BODY()
	
public:

	/**
	 * Looks for a .gj-credentials created by the GameJolt Client in order to login the user automatically.
	 */
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"))
	static UAutoLogin* AutoLogin(UGameJolt* GameJoltAPI);

	UPROPERTY(BlueprintAssignable)
	FAutoLoginSuccesDelegate Success;

	// UBlueprintAsyncActionBase interface
    virtual void Activate() override;
    //~UBlueprintAsyncActionBase interface

private:

	FString Name;
	FString Token;

	UFUNCTION()
	virtual void Callback(const bool bSuccess, UJsonData* JSON) final override;
};
