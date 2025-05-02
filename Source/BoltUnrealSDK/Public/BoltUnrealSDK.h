#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Http.h"
#include "BoltUnrealSDK.generated.h"

UCLASS()
class BOLTUNREALSDK_API UBoltUnrealSDK : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Bolt SDK")
    void OpenWebView(const FString& URL);

    UFUNCTION(BlueprintCallable, Category = "Bolt SDK")
    void SendAPIRequest(const FString& Endpoint, const FString& Verb, const FString& Content);

private:
    void OnAPIResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
};