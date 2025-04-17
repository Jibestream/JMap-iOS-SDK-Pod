//
//  JMapDestination.h
//  JMapCore
//
//  Created by Louie Yuen on 2016-09-21.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>

@class JMapLocation;
@class JMapUriCollection;
@class JMapWaypoint;
/**
 *  The JMapDestination model
 */
@interface JMapDestination : JMapBaseModel
/**
 *  Unit number field that can be inputted in the CMS.
 */
@property (nonatomic, strong, readonly, nullable) NSString *unitNumber;
/**
 *  Name of the destination defined by user in the CMS.
 */
@property (nonatomic, strong, readonly, nullable) NSString *name;
/**
 *  Text description of the destination.
 */
@property (nonatomic, strong, readonly, nullable) NSString *description;
/**
 *  Uri string of the destination for loading images.
 */
@property (nonatomic, strong, readonly, nullable) NSString *primaryUri;
/**
 *  Language code associated to the destination.
 */
@property (nonatomic, strong, readonly, nullable) NSString *localeCode;
/**
 *  List of extensor objects of type NSDictionary associated with the destination.
 */
@property (nonatomic, strong, readonly, nullable) NSDictionary *extensors;
/**
 *  List of uri's associated with the destination.
 */
@property (nonatomic, strong, readonly, nullable) JMapUriCollection *uris;
/**
 *  List of JMapLocation objects associated with the destination.
 */
@property (nonatomic, strong, readonly, nullable) NSArray<JMapLocation *> *locations;
/**
 *  List of Category ID strings associated with the destination.
 */
@property (nonatomic, strong, readonly, nullable) NSArray <NSString *> *categoryIds;
/**
 *  List of keyword strings associated with the destination.
 */
@property (nonatomic, strong, readonly, nullable) NSArray <NSString *> *keywords;
/**
 *  List of tag strings associated with the destination.
 */
@property (nonatomic, strong, readonly, nullable) NSArray <NSString *> *tags;
/**
 *  List of JMapWaypoint objects associated with the destination.
 */
@property (nonatomic, strong, readonly, nullable) NSArray <JMapWaypoint *> *waypoints;
/**
 *  Display mode associated with the destination for determining the content displayed in the destination unit
 *  0 - Display none
 *  1 - Display Text
 *  2 - Display Image
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *displayMode;
/**
 *  The SVG string associated to the destination.
 */
@property (nonatomic, strong, readonly, nullable) NSString *svg;
/**
 *  Initializes a JMapDestination.
 *
 *  @param dict An NSDictionary parsed from the server.
 *  @return An initialized JMapDestination instance.
 */
-(nullable instancetype)initWithDictionary:(nonnull NSDictionary *)dict;


@end
