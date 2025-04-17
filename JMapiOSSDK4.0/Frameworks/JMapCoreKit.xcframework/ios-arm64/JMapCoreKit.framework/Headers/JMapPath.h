//
//  JMapPath.h
//  JMapCore
//
//  Created by Louie Yuen on 2016-09-22.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>
/**
 *  The JMapPath model.
 */
@interface JMapPath : JMapBaseModel
/**
 *  The path type ID that the path belongs to.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *pathTypeId;
/**
 *  The name of the path.
 */
@property (nonatomic, strong, readonly, nullable) NSString *name;
/**
 *  The direction of the path.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *direction;
/**
 *  List of waypoint ID's associated with the path.
 */
@property (nonatomic, strong, readonly, nullable) NSArray<NSNumber *> *waypointIds;
/**
 *  Initializes a JMapPath.
 *
 *  @param dict An NSDictionary parsed from the server.
 *  @return An initialized JMapPath instance.
 */
-(nullable instancetype)initWithDictionary:(nonnull NSDictionary *)dict;

@end
