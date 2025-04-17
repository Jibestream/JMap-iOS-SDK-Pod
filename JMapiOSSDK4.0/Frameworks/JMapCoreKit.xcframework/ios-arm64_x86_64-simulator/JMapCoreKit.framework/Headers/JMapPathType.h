//
//  JMapPathType.h
//  JMapCore
//
//  Created by Louie Yuen on 2016-09-22.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>

@class JMapUriCollection;
@class JMapLocation;
@class JMapWaypoint;
/**
 *  The JMapPathType model.
 */
@interface JMapPathType : JMapBaseModel
/**
 *  The name of the path type.
 */
@property (nonatomic, strong, readonly, nullable) NSString *name;
/**
 *  The description of the path type.
 */
@property (nonatomic, strong, readonly, nullable) NSString *description;
/**
 *  The accessibility value of the path type.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *accessibility;
/**
 *  The vertical weight of the path type.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *verticalWeight;
/**
 *  The speed value of the path type.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *speed;
/**
 *  The maximum floor limited to the path type.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *maxFloors;
/**
 *  The weight of the path type.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *weight;
/**
 *  The direction of the path type.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *direction;
/**
 *  The uri collection associated with path type.
 */
@property (nonatomic, strong, readonly, nullable) JMapUriCollection *uris;
/**
 *  List of JMapLocation objects associated with the path type.
 */
@property (nonatomic, strong, readonly, nullable) NSArray <JMapLocation*> *locations;
/**
 *  The svg string of the path type.
 */
@property (nonatomic, strong, readonly, nullable) NSString *svg;
/**
 *  List of JMapWaypoint objects associated with the path type.
 */
@property (nonatomic, strong, readonly, nullable) NSArray<JMapWaypoint *>*waypoints;
/**
 *  Initializes a JMapPathType.
 *
 *  @param dict An NSDictionary parsed from the server.
 *  @return An initialized JMapPathType instance.
 */
-(nullable instancetype)initWithDictionary:(nonnull NSDictionary *)dict;

@end
