# contentDock® SDK for iOS 
contentDock is a powerful service that combines the app development with designers, content editors, administration and software developers in one process and makes the app development more secure, easier, faster, cheaper and that without limits.

With the contentDock service, you can create your own mobile content platforms for iOS and Android and publish your content apps quickly and easily. Each content in-app can be individually extended with the SDK element and the contentDock SDK. The normal development process is faster in this way, because the developer is only responsible about the individual functions.

In addition, the contentDock SDK provides all the functions that you need to create a content platform so that you can present your public and private inApps in the best possible way. 

* [contentDock at a glance](https://www.contentdock.com/en)
* [contentDock for developer](https://www.contentdock.com/en/for-developer)


## The top five of the contentdock services 
1. easy creation of native content InApps (private or public) that can be individually extended with this SDK.
2. powerful CMS to manage all InApps, content and users
3. powerful contentDock Wireframer App for the creation of your InApps
4. powerful contentDock Viewer App for testing your InApps and customising styles
5. creation of app data containers so you can store your app data in the cloud

* [contentDock Wirerframer App in the Apple App Store](https://apps.apple.com/us/app/contentdock-wireframer/id971198068?l=en&ls=1)
* [contentDock Viewer App in the Apple App Store](https://apps.apple.com/us/app/contentdock-viewer/id971153474?l=en&ls=1)
* [contentDock Viewer App in the Google Play Store](https://play.google.com/store/apps/details?id=net.edit.contentdock)


## Documentation
A detailed documentation for this SDK you can be found at the website:

* [contentDock SDK Documentation for iOS](https://www.contentdock.com/en/documentation/sdk-ios)


## Development Languages
This SDK is optimized for iOS 14 or higher. 
The framework can be combined with Objective-C, Swift, Swift-UI and Flutter.


## Installing the XCFramework
### CocoaPods
1.  Add the following to your Podfile:

```
    use_frameworks!

    target 'TargetNameForYourApp' do
        pod 'CDockFramework'
    end 
```

2.  Run pod install to install the dependency.

### Carthage
1.  Open your project in Xcode.
2.  Confirm that you are using Carthage version 0.38.0 or higher.
3.  Add the following to your Cartfile:

``
    binary "https://contentdock-sdk.s3.eu-central-1.amazonaws.com/contentdock-ios-sdk.json" == 1.0.9
``

You can see the current version number here in the release view.

4.  Install the SDK with carthage ``update --use-xcframeworks``
5.  A Cartfile.resolved file and a Carthage directory will appear in the same directory where your .xcodeproj or .xcworkspace is
6.  Drag the .xcframework bundle from Carthage/Build into the "Frameworks and Libraries" section of your application’s Xcode project and select "Embed & Sign".

### Direct download
1.   Use the following command to load the current version of the SDK:

``
    git clone https://github.com/edit/contentdock-sdk-ios-universal
``

2.  Drag the .xcframework bundle into the "Frameworks and Libraries" section of your application’s Xcode project and select "Embed & Sign".


## Examples
You can view the sample projects in which the contentDock SDK is included:

1. contentDock SDK in the Multi mode: [https://github.com/edit/contentdock-sdk-ios-example-multi-mode](https://github.com/edit/contentdock-sdk-ios-example-multi-mode)

2. contentDock SDK in the Single mode: [https://github.com/edit/contentdock-sdk-ios-example-single-mode](https://github.com/edit/contentdock-sdk-ios-example-single-mode)


# Contributing
We are happy if you are convinced of the contentDock workflow and the associated possibilities. If you have any questions, comments or ideas, please feel free to write us a issue ticket.


# Authors
* **EDIT GmbH - Germany** 


# License
This project is licensed under the MIT License
