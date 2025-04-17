//
//  JMapMapLabelInstance.h
//  JMapCore
//
//  Created by Louie Yuen on 2016-09-23.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JMapCoreKit/JMapCoreKit.h>

/**
 *  The JMapMapLabelInstance model.
 */
@interface JMapMapLabelInstance : JMapBaseModel
/**
 *  The position of the map label instance in the form of [x,y].
 */
@property (nonatomic, strong, readonly, nullable) NSArray * position;
/**
 *  The name of the map label instance.
 */
@property (nonatomic, strong, readonly, nullable) NSString * name;
/**
 *  The map ID associated with the map label instance.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber * mapId;
/**
 *  The scale of the map label instance.
 */
@property (nonatomic, strong, readonly, nullable) NSArray * scale;
/**
 *  The skew of the map label instance.
 */
@property (nonatomic, strong, readonly, nullable) NSArray * skew;
/**
 *  The transform of the map label instance.
 */
@property (nonatomic, strong, readonly, nullable) NSArray * trans;
/**
 *  The rotation value of the map label instance.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *rotation;
/**
 *  Determines if the map label instance is on all levels in the building. 0 - false, 1 - true.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *allLevels;
/**
 *  Initializes a JMapMapLabelInstance.
 *
 *  @param dict An NSDictionary parsed from the server.
 *  @return An initialized JMapMapLabelInstance instance.
 */
-(nullable instancetype)initWithDictionary:(nonnull NSDictionary *)dict;

@end
