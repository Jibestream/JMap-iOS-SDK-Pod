// swift-tools-version:5.9
// Swift Package Manager distribution of the Jibestream JMap iOS SDK, starting at 6.0.0.
// The same git tag also serves the CocoaPods podspec (JMapiOSSDK.podspec) until CocoaPods is retired.
//
// Release: tag the commit with the bare semantic version (e.g. `6.0.0`, no `v` prefix) and keep
// `s.version` in JMapiOSSDK.podspec in step with it.
import PackageDescription

let package = Package(
    name: "JMapiOSSDK",
    platforms: [
        // The shipped binaries are built for iOS 10 and stay forward-compatible, so this is a
        // policy floor rather than a technical one. Xcode warns below iOS 12 but still builds.
        .iOS(.v15)
    ],
    products: [
        // A single product keeps parity with `pod 'JMapiOSSDK'`, which vends all three frameworks.
        // JMapControllerKit links JMapRenderingKit, which links JMapCoreKit, so they ship together.
        .library(
            name: "JMapiOSSDK",
            targets: ["JMapCoreKit", "JMapRenderingKit", "JMapControllerKit"]
        )
    ],
    targets: [
        // Dynamic Swift framework.
        .binaryTarget(
            name: "JMapCoreKit",
            path: "JMapiOSSDK4.0/Frameworks/JMapCoreKit.xcframework"
        ),
        // Static Objective-C frameworks. They carry no LC_LINKER_OPTION, so they auto-link
        // nothing by themselves; their system frameworks (UIKit, WebKit, ...) are linked
        // through the consumer's Clang module graph instead, because the public headers
        // import them. Verified by linking an app against all three modules, where WebKit
        // and CoreLocation both end up in the app binary. Hence no linkerSettings here.
        .binaryTarget(
            name: "JMapRenderingKit",
            path: "JMapiOSSDK4.0/Frameworks/JMapRenderingKit.xcframework"
        ),
        .binaryTarget(
            name: "JMapControllerKit",
            path: "JMapiOSSDK4.0/Frameworks/JMapControllerKit.xcframework"
        )
    ]
)
