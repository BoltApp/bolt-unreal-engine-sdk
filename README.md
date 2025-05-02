# bolt-unreal-engine-sdk

<div align="center" style="display:flex;justify-content:center;margin-bottom:20px">
  <img src="https://res.cloudinary.com/dugcmkito/image/upload/v1744983998/bolt_accounts_2x_6c96bccd82.png" alt="Bolt Charge Hero" width="40%" style="padding:20px">

  <img src="https://cdn2.unrealengine.com/ue-logotype-2023-vertical-white-1686x2048-bbfded26daa7.png" width="40%" />
</div>

<br>

Native Unreal Engine support for [Bolt Charge](https://www.bolt.com/charge), a fully hosted webshop for out-of-app purchases and subscriptions.

<div class="discord-link">
    Got Questions?
    <a href="https://discord.gg/BSUp9qjtnc" target="_blank" class="discord-link-anchor">
      <span class="discord-text mr-2">Chat with us on Discord</span>
      <span class="discord-icon-wrapper">
        <img src="https://help.bolt.com/images/brand/Discord-Symbol-White.svg" alt="Discord" class="discord-icon" width="15px">
      </span>
    </a>
  </div>


<br>
We also have [Native Unity](https://github.com/davidminin/bolt-unity-sdk) Support and a [Sample Backend](https://github.com/davidminin/bolt-gameserver-sample) for additional reference.

## 💰 Why Bolt

Only with Bolt you get **2.1% + $0.30 on all transactions**. That's 10x better than traditional app stores which take 30% of your revenue! That's the fair and transparent pricing you get with using Bolt.

<p style="font-size:12px;font-style:italic;opacity:85%">
<strong>Disclaimer:</strong> Fees are subject to change but will continue to remain highly competitive. See <a href="https://www.bolt.com/pricing">bolt.com/pricing</a> for up to date rates and visit  <a href="https://www.bolt.com/end-user-terms">bolt.com/end-user-terms</a> for end user terms and conditions.
</p>

## 🚀 Features

This open source package is a light-weight UE5 SDK.
- Bring your own UI
- Open webstore links directly inside your app
- Radically cheaper payment processing rates
- **Future:** User session management

The SDK supports Unreal Engine 5+. Code might work for older versions but is not officially supported.

**Have a feature request?** We are constantly improving our SDKs and looking for suggestions. [Join our discord](https://discord.gg/BSUp9qjtnc) and chat directly with our development team to help with our roadmap!

## 📦 Installation

**Note:** This project is still in early access but we plan to provide official package support in the near future.

**Clone / Copy the Plugin**

1. Create or open your Unreal Engine 5 project.
2. Inside your project folder, create a `Plugins` directory if it doesn't exist:

   ```bash
   mkdir Plugins
   ```
3. Copy the entire BoltUnrealSDK folder (this repo) into the Plugins folder. You can download the repo as a zip.

    ```
    YourProject/
    └── Plugins/
    └── BoltUnrealSDK/
        ├── BoltUnrealSDK.uplugin
        └── Source/
    ```
4. Restart Unreal Engine.
5. When prompted, click Yes to rebuild the plugin binaries if required.

**Create the WebView Widget Blueprint**

This plugin relies on a UI widget with a Web Browser component:

1. In the Unreal Content Browser, create a folder at:
2. Inside /Game/UI/, create a new User Widget Blueprint called:
3. Open WebViewWidget:
    - Add a Web Browser component from the Palette.
    - Set its anchor to Full Screen and stretch it to fill.
    - Rename the Web Browser component to `WebBrowser`
4. Save and compile.


## 🔧 Quick Start

**Requirements:** You must have a backend server for proxying API requests. See our [server sample](https://github.com/davidminin/bolt-gameserver-sample) for an example integration.

1. Add the SDK to your project
2. Add routes to your backend server [(see example usage)](https://github.com/davidminin/bolt-gameserver-sample/blob/main/example-usage.ts)
3. Use the staging api configs to test purchases in your dev environment

<br>

### Example Usage:
**BoltDemoActor.h**
```c++
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoltUnrealSDK.h"
#include "BoltDemoActor.generated.h"

UCLASS()
class YOURPROJECT_API ABoltDemoActor : public AActor
{
    GENERATED_BODY()

public:
    ABoltDemoActor();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, Category = "Bolt Config")
    FString BackendBaseUrl = TEXT("https://your-backend-server.com");

private:
    UPROPERTY()
    UBoltUnrealSDK* BoltSDK;

    void OpenCheckoutPage(const FString& WebUrl);
    void HandleWebViewClosed(); // Stub: hook into WebView event system later
};
```

**BoltDemoActor.cpp**
```c++
#include "BoltDemoActor.h"
#include "TimerManager.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"

ABoltDemoActor::ABoltDemoActor()
{
    PrimaryActorTick.bCanEverTick = false;
}

void ABoltDemoActor::BeginPlay()
{
    Super::BeginPlay();

    // Initialize SDK
    BoltSDK = NewObject<UBoltUnrealSDK>(this);
    
    // Example: Make an API call to get subscriptions
    const FString Email = TEXT("test@test.com");
    FString GetUrl = BackendBaseUrl + "/subscriptions?email=" + FGenericPlatformHttp::UrlEncode(Email);
    BoltSDK->SendAPIRequest(GetUrl, TEXT("GET"), TEXT(""));

    // Open a checkout webview
    const FString CheckoutUrl = TEXT("https://digital-subscriptions-test-14-04.c-staging.bolt.com/c?u=SRZKjocdzkUmJfS2J7JNCQ&publishable_key=BQ9PKQksUGtj.Q9LwVLfV3WF4.32122926f7b9651a416a5099dc92dc2b4c87c8b922c114229f83b345d65f4695");
    OpenCheckoutPage(CheckoutUrl);
}

void ABoltDemoActor::OpenCheckoutPage(const FString& WebUrl)
{
    if (BoltSDK)
    {
        BoltSDK->OpenWebView(WebUrl);
    }

    // You can trigger HandleWebViewClosed manually after a delay (for demo/testing):
    GetWorld()->GetTimerManager().SetTimerForNextTick([this]()
    {
        HandleWebViewClosed(); // Simulated for now
    });
}

void ABoltDemoActor::HandleWebViewClosed()
{
    UE_LOG(LogTemp, Log, TEXT("WebView was closed by the user."));

    // Trigger anything you want here:
    // - Check subscription status
    // - Refresh UI
    // - Resume gameplay
}

```

## 📚 Documentation

For detailed documentation and API reference, visit our [documentation site](https://docs.bolt.com).


## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
