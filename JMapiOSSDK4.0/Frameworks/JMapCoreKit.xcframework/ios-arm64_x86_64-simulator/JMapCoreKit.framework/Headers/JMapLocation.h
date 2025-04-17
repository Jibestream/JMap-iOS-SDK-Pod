//
//  JMapLocation.h
//  JMapCore
//
//  Created by Louie Yuen on 2016-09-23.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>
/**
 *  The JMapLocation model.
 */
@interface JMapLocation : NSObject
/**
 *  The map ID that the object's location is associated to.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *mapId;
/**
 *  List of waypoint ID's that the object's location is associated to.
 */
@property (nonatomic, strong, readonly, nullable) NSArray<NSNumber *> *waypointIds;
/**
 *  Initializes a JMapLocation.
 *
 *  @param dict An NSDictionary parsed from the server.
 *  @return An initialized JMapLocation instance.
 */
-(nullable instancetype)initWithDictionary:(nonnull NSDictionary *)dict;
/**
 *  Handles parsing of location data from the server.
 *
 *  @param dict An NSDictionary parsed from the server.
 *  @return An NSArray of JMapLocation objects that the object is associated to.
 */
+ (nullable NSArray <JMapLocation *>*)parseLocationsIntoArrayFormDictionary:(nonnull NSDictionary *)dict;

@end
