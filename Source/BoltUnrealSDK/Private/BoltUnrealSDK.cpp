#include "BoltUnrealSDK.h"
#include "Components/WebBrowser.h"
#include "Engine/Engine.h"

void UBoltUnrealSDK::OpenWebView(const FString& URL)
{
    if (GEngine && GEngine->GameViewport)
    {
        UUserWidget* WebWidget = CreateWidget<UUserWidget>(GEngine->GameViewport, LoadClass<UUserWidget>(nullptr, TEXT("/Game/WebViewWidget.WebViewWidget_C")));
        if (WebWidget)
        {
            WebWidget->AddToViewport();
            UWebBrowser* WebBrowser = (UWebBrowser*)(WebWidget->GetWidgetFromName(TEXT("WebBrowser")));
            if (WebBrowser)
            {
                WebBrowser->LoadURL(URL);
            }
        }
    }
}

void UBoltUnrealSDK::SendAPIRequest(const FString& Endpoint, const FString& Verb, const FString& Content)
{
    TSharedRef<IHttpRequest> Request = FHttpModule::Get().CreateRequest();
    Request->SetURL(Endpoint);
    Request->SetVerb(Verb);
    Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
    Request->SetContentAsString(Content);
    Request->OnProcessRequestComplete().BindUObject(this, &UBoltUnrealSDK::OnAPIResponseReceived);
    Request->ProcessRequest();
}

void UBoltUnrealSDK::OnAPIResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
    if (bWasSuccessful && Response.IsValid())
    {
        FString ResponseString = Response->GetContentAsString();
        UE_LOG(LogTemp, Log, TEXT("Bolt SDK Response: %s"), *ResponseString);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Bolt SDK API call failed."));
    }
}
