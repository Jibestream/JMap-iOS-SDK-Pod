//
//  JMapMap.h
//  JMapCore
//
//  Created by Louie Yuen on 2016-09-23.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>

@class JMapWaypointCollection;
@class JMapPathCollection;

/**
 *  The JMapMap model.
 */
@interface JMapMap : JMapBaseModel
/**
 *  The svg string of the map.
 */
@property (nonatomic, strong, readonly, nullable) NSString *svg;
/**
 *  The geoJSON string of the map.
 */
@property (nonatomic, strong, readonly, nullable) NSDictionary *geojson;
/**
 *  The mm/px scale of the map.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *mmPerPixel;
/**
 *  The scale of the map.
 */
@property (nonatomic, strong, readonly, nullable) NSArray *scale;
/**
 *  The skew of the map.
 */
@property (nonatomic, strong, readonly, nullable) NSArray *skew;
/**
 *  The transform of the map.
 */
@property (nonatomic, strong, readonly, nullable) NSArray *trans;
/**
 *  The width value of the map.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *width;
/**
 *  The height value of the map.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *height;
/**
 *  The JMapWaypointCollection object associated with the map.
 */
@property (nonatomic, strong, readonly, nullable) JMapWaypointCollection *waypoints;
/**
 *  The JMapPathCollection object associated with the map.
 */
@property (nonatomic, strong, readonly, nullable) JMapPathCollection *paths;

/**
 *  The JMapUriCollection associated with the map.
 */
@property (nonatomic, strong, readonly, nullable) JMapUriCollection *uris;

/**
 *  Initializes a JMapMap.
 *
 *  @param dict An NSDictionary parsed from the server.
 *  @return An initialized JMapMap instance.
 */
-(nullable instancetype)initWithDictionary:(nonnull NSDictionary *)dict;

@end
