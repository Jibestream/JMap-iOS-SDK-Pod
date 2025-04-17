//
//  JMapFloor.h
//  JMapCore
//
//  Created by Louie Yuen on 2016-09-22.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>

@class JMapMap;

/**
 *  The JMapFloor model.
 */
@interface JMapFloor : JMapBaseModel
/**
 *  The building ID of the floor.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *buildingId;
/**
 *  The map object associated with the floor.
 */
@property (nonatomic, strong, readonly, nullable) JMapMap *map;
/**
 *  The level value associated with the floor.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *level;
/**
 *  The preference value associated with the floor.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *preference;
/**
 *  The elevation value associated with the floor.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *elevation;
/**
 *  The altitude value associated with the floor.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *altitude;
/**
 *  The name of the floor.
 */
@property (nonatomic, strong, readonly, nullable) NSString *name;
/**
 *  The short name or abbreviated name of the floor.
 */
@property (nonatomic, strong, readonly, nullable) NSString *shortName;
/**
 *  Initializes a JMapFloor.
 *
 *  @param dict An NSDictionary parsed from the server.
 *  @return An initialized JMapFloor instance.
 */
-(nullable instancetype)initWithDictionary:(nonnull NSDictionary *)dict;

@end
