# JMapiOSSDK4.0

[![CI Status](http://img.shields.io/travis/Louie/JMapiOSSDK4.0.svg?style=flat)](https://travis-ci.org/Louie/JMapiOSSDK4.0)
[![Version](https://img.shields.io/cocoapods/v/JMapiOSSDK4.0.svg?style=flat)](http://cocoapods.org/pods/JMapiOSSDK4.0)
[![License](https://img.shields.io/cocoapods/l/JMapiOSSDK4.0.svg?style=flat)](http://cocoapods.org/pods/JMapiOSSDK4.0)
[![Platform](https://img.shields.io/cocoapods/p/JMapiOSSDK4.0.svg?style=flat)](http://cocoapods.org/pods/JMapiOSSDK4.0)

## Example

To run the example project, clone the repo, and run `pod install` from the Example directory first.

## Requirements

- **iOS 15.0 or later**, as of 6.0.0. Releases 5.13.3 and earlier declare an
  iOS 10.0 floor and remain resolvable, so a project that cannot move to
  iOS 15 yet can stay pinned to 5.13.3.
- **Xcode 15 or later** for Swift Package Manager (`Package.swift` declares
  `swift-tools-version:5.9`). CocoaPods has no additional Xcode requirement
  beyond what the SDK binaries themselves need.
- **`-ObjC` in your target's Other Linker Flags.** `JMapRenderingKit` and
  `JMapControllerKit` ship as static archives (`JMapCoreKit` is a dynamic
  framework), and `-ObjC` forces the linker to load every Objective-C member
  of a static archive, including categories that nothing references directly.
  Without it a category can go unregistered and produce an
  `unrecognized selector` crash at runtime. CocoaPods writes this flag into
  its generated xcconfig automatically; with Swift Package Manager you must
  set it on your own target.

## Installation

The SDK supports **both** Swift Package Manager and CocoaPods. Both are served
from this one repository and the same git tag: SPM reads `Package.swift`,
CocoaPods reads `JMapiOSSDK.podspec`, and both point at the same XCFrameworks
under `JMapiOSSDK4.0/Frameworks/`. Each ignores the other's manifest.

> **Pick one.** Adding the SDK through both CocoaPods and Swift Package Manager
> in the same project links the frameworks twice and fails with duplicate
> symbol errors.

### Swift Package Manager (6.0.0 and later)

In Xcode, choose **File > Add Package Dependencies…**, enter
`https://github.com/Jibestream/JMap-iOS-SDK-Pod.git`, pick **Up to Next Major Version** from `6.0.0`,
and add the `JMapiOSSDK` product to your app target.

Or, in a `Package.swift`:

```swift
dependencies: [
    .package(url: "https://github.com/Jibestream/JMap-iOS-SDK-Pod.git", from: "6.0.0")
],
targets: [
    .target(
        name: "YourTarget",
        dependencies: [.product(name: "JMapiOSSDK", package: "JMap-iOS-SDK-Pod")]
    )
]
```

The product provides the `JMapCoreKit`, `JMapRenderingKit` and `JMapControllerKit` modules.

Swift Package Manager support is available from **6.0.0** onward. Earlier tags do not contain a
`Package.swift` and cannot be resolved by SPM.

### CocoaPods (deprecated)

CocoaPods support continues for now but will be removed in a future release; please move to
Swift Package Manager.

JMapiOSSDK4.0 is available through [CocoaPods](http://cocoapods.org). To install
it, simply add the following line to your Podfile:

```ruby
pod 'JMapiOSSDK', :git => 'https://github.com/Jibestream/JMap-iOS-SDK-Pod.git'
```

For installing the first time run:
```ruby
pod install
```

To get the latest version of the pod run:
```ruby
pod update
```

## Author

Louie, lyuen@jibestream.com
