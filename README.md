# Bolt Unreal Engine SDK

<img src="https://github.com/BoltApp/bolt-gameserver-sample/blob/main/public/banner-unreal.png?raw=true" alt="Bolt Charge Hero" />

## What is this?

Native Unreal Engine support for [Bolt Charge](https://www.bolt.com/charge), a fully hosted webshop for out-of-app purchases and subscriptions.

We also support other platforms:

<table>
  <tr>
    <td align="center" width="150">
      <img src="https://upload.wikimedia.org/wikipedia/commons/6/6a/JavaScript-logo.png" width="60" height="60" alt="JavaScript"/><br>
      <b>JavaScript</b><br>
      <a href="https://github.com/BoltApp/bolt-frontend-sdk">JavaScript SDK</a>
    </td>
    <td align="center" width="150">
      <img src="https://cdn.sanity.io/images/fuvbjjlp/production/bd6440647fa19b1863cd025fa45f8dad98d33181-2000x2000.png" width="60" height="60" alt="Unity"/><br>
      <b>Unity</b><br>
      <a href="https://github.com/BoltApp/bolt-unity-sdk">Unity SDK</a>
    </td>
    <td align="center" width="150">
      <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRUf3R8LFTgqC_8mooGEx7Fpas9kHu8OUxhLA&s" width="60" height="60" alt="Unreal"/><br>
      <b>Unreal Engine</b><br>
      <i>This Repo</i>
    </td>
  </tr>
  <tr>
    <td align="center" width="150">
      <img src="https://developer.apple.com/assets/elements/icons/swift/swift-64x64.png" width="60" height="60" alt="iOS"/><br>
      <b>iOS</b><br>
      Coming Soon 🚧
    </td>
    <td align="center" width="150">
      <img src="https://avatars.githubusercontent.com/u/32689599?s=200&v=4" width="60" height="60" alt="Android"/><br>
      <b>Android</b><br>
      Coming Soon 🚧
    </td>
    <td align="center" width="150">
      <!-- filler -->
    </td>
  </tr>
</table>

<br>

<div align="center">

[![Discord](https://img.shields.io/badge/Discord-Have%20A%20Request%3F-7289DA?style=for-the-badge&logo=discord&logoColor=white&logoWidth=60)](https://discord.gg/BSUp9qjtnc)

### Chat with us on Discord for help and inquiries!

</div>

## 💰 Why Bolt

Only with Bolt you get **2.1% + $0.30 on all transactions**. That's 10x better than traditional app stores which take 30% of your revenue! That's the fair and transparent pricing you get with using Bolt.

<p style="font-size:12px;font-style:italic;opacity:85%">
<strong>Disclaimer:</strong> Fees are subject to change but will continue to remain highly competitive. See <a href="https://www.bolt.com/pricing">bolt.com/pricing</a> for up to date rates and visit  <a href="https://www.bolt.com/end-user-terms">bolt.com/end-user-terms</a> for end user terms and conditions.
</p>

## 🛠️ Prerequisites

You need 3 things to get started:

1. **Existing App:** You will need an application in the same platform as this SDK
2. **Backend Server:** You will need to bring your own backend server (any language)
3. **Bolt Merchant Account:** Dashboard access to manage your store ([signup](https://merchant.bolt.com/onboarding/get-started) or [login](https://merchant.bolt.com/))

## 📚 Documentation

For broad documentation and API reference visit our [documentation site](https://docs.bolt.com).


**Have a feature request?** We are constantly improving our SDKs and looking for suggestions. [Join our discord](https://discord.gg/BSUp9qjtnc) and chat directly with our development team to help with our roadmap!

## 📦 Installation

This SDK supports Unreal Engine 5+. Code might work for older versions but is not officially supported.

### Step 1: Install the Bolt Unreal Engine SDK

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
            ├── README.md
            └── Source/BoltUnrealSDK/...
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

### Step 2: Set up your backend server

You need to bring your own server to safely handle transactions and api keys.
1. Integrate the Bolt API
    - This is how you will interact with the Charge API and manage digital subscriptions
    - Docs: https://help.bolt.com/products/bolt-charge/charge-setup/ 
    - API: https://help.bolt.com/api-subscriptions/ 
    - Example server: https://github.com/BoltApp/bolt-gameserver-sample
2. Set up the Authorization Webhook
    - _"Authorization"_ is an industry term for transactions
    - This is how you will check if a user completed a transaction
    - Webhook Docs: https://help.bolt.com/developers/webhooks/webhooks
    - Webhook Events: https://help.bolt.com/developers/webhooks/webhooks/#authorization-events
    - API: https://help.bolt.com/api-merchant/#tag/webhooks/POST/webhooks_transaction 
3. Note your server URL (like `https://your-server.herokuapp.com`)
    - You will use this URL for initializing the api client in Step 4
    - Consider using configs for managing different environments

### Step 3: Get your Bolt account

1. Go to [merchant.bolt.com](https://www.merchant.bolt.com) and login to the dashboard. You can [signup here](https://merchant.bolt.com/onboarding/get-started) if you don't have an account.
2. Set up your products in the Bolt dashboard. You can find [helpful instructions in our documentation](https://help.bolt.com/products/bolt-charge/charge-setup/#set-up-your-products).
3. Get your checkout links (they look like: `https://digital-subscriptions-test-14-04.c-staging.bolt.com/c?u=SRZKjocdzkUmJfS2J7JNCQ&publishable_key=BQ9PKQksUGtj.Q9LwVLfV3WF4.32122926f7b9651a416a5099dc92dc2b4c87c8b922c114229f83b345d65f4695`)

### Step 4: Add code to your game

You may copy this code into a new script in your project or use it for reference on how to initialize the bolt client and webview.

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

## Step 5: Test it

1. Add the Actor to your Level:
   - In the Content Browser, right-click and select "Blueprint Class" → "Actor"
   - Name it `BP_BoltDemoActor`
   - Open the Blueprint and add the C++ `BoltDemoActor` class as the parent class
   - Drag the Blueprint into your level

2. Configure the Actor:
   - Select the `BP_BoltDemoActor` in your level
   - In the Details panel, find the "Bolt Config" category
   - Set the `Backend Base Url` field to your server URL (e.g., `https://your-backend-server.com`)

3. Test the Integration:
   - **Note:** You can use our staging URL for testing purposes: `https://digital-subscriptions-test-14-04.c-staging.bolt.com/c?u=SRZKjocdzkUmJfS2J7JNCQ&publishable_key=BQ9PKQksUGtj.Q9LwVLfV3WF4.32122926f7b9651a416a5099dc92dc2b4c87c8b922c114229f83b345d65f4695`
   - Play the game in the editor or package and run
   - The checkout page should automatically open as a WebView overlay when the level starts
   - The WebView will display the Bolt payment interface

4. Customize the WebView Widget:
   - Open the `WebViewWidget` Blueprint in `/Game/UI/`
   - Modify the Web Browser component styling to match your game's UI
   - Add a close button if needed and bind it to remove the widget from viewport
   - Ensure the widget handles user interaction appropriately

**Congratulations 🎉**
<br>You have successfully integrated Bolt Charge into your Unreal Engine game!

## Next Steps

Now that you have a single checkout working, you will want to adopt some best practices to make it easy to maintain.

#### Configs
Use a config for managing your collection of checkout links. We recommend using JSON and mapping links to readable names. You can swap configs based on environment. Example:
```
{
  GEMS_100:   'https://your-checkout-link-here.com',
  GEMS_500:   'https://your-checkout-link-here.com',
  GEMS_1000:  'https://your-checkout-link-here.com',
  BUNDLE_ONE: 'https://your-checkout-link-here.com',
  BUNDLE_TWO: 'https://your-checkout-link-here.com'
  // etc...
}
```

#### Integration Tests
We recommend setting up automated testing against the most common flows. Good test coverage should include UI or API test coverage of the following scenarios:
- Checkout is possible to open
- Checkout is possible to close
- User gets success state from successful transaction
- User gets failed state from failed transaction
- User network interrupted after good payment, is shown success screen on reboot of app
- User network interrupted after bad payment, is shown fail screen on reboot of app

#### Translations 🚧

Bolt does support translations and handles many checkouts on the global market. However, right now the SDK is tailored to the U.S. market so only English is officially provided.

We will be rolling out official multi-region support to Bolt Charge in the very near future. If you would like a preview or are curious about the timeline, you can reach out to our team directly.

## Need help?

<div class="discord-link">
    Got questions, roadmap suggestions, or requesting new SDKs?
    <br>
    <a href="https://discord.gg/BSUp9qjtnc" 
    target="_blank" class="discord-link-anchor">
      <span class="discord-text mr-2">Get help and chat with 
      us about anything on Discord</span>
      <span class="discord-icon-wrapper">
        <img src="https://cdn.prod.website-files.com/6257adef93867e50d84d30e2/66e3d80db9971f10a9757c99_Symbol.svg"
        alt="Discord" class="discord-icon" 
        width="16px">
      </span>
    </a>
  </div>



## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.