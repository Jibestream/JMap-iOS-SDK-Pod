//
//  JMapOptions.h
//  JMapController
//
//  Created by Louie Yuen on 2017-11-22.
//  Copyright © 2017 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JMapCoreKit/JMapCoreKit.h>
#import <JMapRenderingKit/JMapRenderingKit.h>

/**
 *  The JMapOptions object.
 */
@interface JMapOptions : NSObject

/**
 *  Client ID passed in for initializing the JMapCore
 */
@property (nonatomic, strong) NSString *clientId;

/**
 *  Client secret passed in for initializing the JMapCore
 */
@property (nonatomic, strong) NSString *clientSecret;

/**
 *  Host endpoint passed in for initializing the JMapCore
 */
@property (nonatomic, strong) NSString *host;

/**
 *  Customer ID passed in for initializing the JMapCore
 */
@property (nonatomic, assign) int customerId;

/**
 *  Canvas instance passed in for initializing the JMapController
 */
@property (nonatomic, strong) JMapCanvas *stage;

/**
 *  Venue ID passed in for initializing the JMapCore
 */
@property (nonatomic, assign) int venueId;

/**
 *  Building ID passed in for populating building data
 */
@property (nonatomic, assign) int buildingId;

/**
 *  Locale code to be passed in for localization, defaults to en-US
 */
@property (nonatomic, strong) NSString *locale;

/**
 *  Boolean property for showing default map, if showMapWithId is set it will override this
 */
@property (nonatomic, assign) BOOL showDefaultMap;

/**
 *  Map ID to be shown on the canvas
 */
@property (nonatomic, assign) int showMapWithId;

/**
 *  Map Options to be applied to shown map
 *
 *  @code
 @{
    @"backgroundImage": NSString, background image Url
 }
 */
@property (nonatomic, strong) NSDictionary *mapOptions;

/**
 *  Set the minimum zoom scale for the map
 */
@property (nonatomic, assign) float minScale;

/**
 *  Set the maximum zoom scale for the map
 */
@property (nonatomic, assign) float maxScale;

/**
 *  List of layer names to be hidden on load
 */
@property (nonatomic, strong) NSArray <NSString *>* hiddenLayers;

/**
 *  Boolean property for showing all amenities, defaults to false
 */
@property (nonatomic, assign) BOOL showAllAmenities;

/**
 *  Boolean property for showing all path types, defaults to false
 */
@property (nonatomic, assign) BOOL showAllPathTypes;

/**
 *  Boolean property for showing all image map labels, defaults to false
 */
@property (nonatomic, assign) BOOL showAllImageMapLabels;

/**
 *  Amenity options property to be used, if showing amenites
 *
 *  @code
 @{
    @"scaleWithMap": [NSNumber numberWithBool:true/false], default false
    @"rotateWithMap": [NSNumber numberWithBool:true/false], default false
    @"flipWithRotation": [NSNumber numberWithBool:true/false], default false
    @"scale": NSNumber, default to 1
 }
 */
@property (nonatomic, strong) NSDictionary * amenityOptions;

/**
 *  Pathtype options property to be used, if showing amenites
 *
 *  @code
 @{
    @"scaleWithMap": [NSNumber numberWithBool:true/false], default false
    @"rotateWithMap": [NSNumber numberWithBool:true/false], default false
    @"flipWithRotation": [NSNumber numberWithBool:true/false], default false
    @"scale": NSNumber, default to 1
 }
 */

@property (nonatomic, strong) NSDictionary * pathTypeOptions;
/**
 *  ImageMapLabel options property to be used, if showing amenites
 *
 *  @code
 @{
    @"rotateWithMap": [NSNumber numberWithBool:true/false], default false
    @"flipWithRotation": [NSNumber numberWithBool:true/false], default false
    @"scaleWithMap": [NSNumber numberWithBool:true/false], default false
    @"scale": NSNumber, default to 1
 }
 */
@property (nonatomic, strong) NSDictionary * imageMapLabelOptions;

/**
 *  TextMapLabel options property to be used, if showing amenites
 *
 *  @code
 @{
    @"scaleWithMap": [NSNumber numberWithBool:true/false], default false
    @"rotateWithMap": [NSNumber numberWithBool:true/false], default false
    @"flipWithRotation": [NSNumber numberWithBool:true/false], default true
    @"scale": NSNumber, default to 1
 }
 */
@property (nonatomic, strong) NSDictionary * textMapLabelOptions;

/**
 *  Boolean property for showing all text map labels, defaults to false
 */
@property (nonatomic, assign) BOOL showAllTextMapLabels;

/**
 *  Boolean property for applying display mode to units, defaults to false
 */
@property (nonatomic, assign) BOOL applyDisplayMode;

/**
 *  JSON style configuration to be applied to the map
 */
@property (nonatomic, strong) NSString * jsonStyle;

/**
 *  Font property to be applied to text in displayMode
 */
@property (nonatomic, strong) UIFont * displayModeFont;

/**
 *  Font property to be applied to text map labels
 */
@property (nonatomic, strong) UIFont * mapLabelFont;

/**
 *  JMapFont property to be applied to text in displayMode
 */
@property (nonatomic, strong) JMapFont * displayModeJMapFont;

/**
 *  JMapFont property to be applied to text map labels
 */
@property (nonatomic, strong) JMapFont * mapLabelJMapFont;

/**
 *  Boolean property for enabling/disabling pan gesture, defaults to true
 */
@property (nonatomic, assign) BOOL panGesture;

/**
 *  Boolean property for enabling/disabling zoom gesture, defaults to true
 */
@property (nonatomic, assign) BOOL scaleGesture;

/**
 *  Boolean property for enabling/disabling rotation gesture, defaults to true
 */
@property (nonatomic, assign) BOOL rotationGesture;

/**
 *  UserLocation options property to be used, if displaying user location
 *
 *  @code
 @{
    @"point": CGPoint,
    @"floor": JMapMap,
    @"orientation": NSNumber,
    @"confidenceRadius": NSNumber
 }
 */
@property (nonatomic, strong) NSDictionary * userLocationOptions;

/**
 *  Boolean property for parsing all maps, defaults to false
 */
@property (nonatomic, assign) BOOL parseAllMaps;

/**
 *  Cache reload flag for checking cache updates, defaults to true
 */
@property (nonatomic) NSNumber *autoReloadCache;

/**
 *  Boolean property to load a fresh instance of the data from server, defaults to false
 */
@property (nonatomic, assign) BOOL clearCacheData;

@end
