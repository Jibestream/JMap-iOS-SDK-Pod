//
//  JMapWaypoint.h
//  JMapCore
//
//  Created by Aaron Wong on 2016-08-17.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>

@class JMapAssociation;

/**
 *  The JMapWaypoint model.
 */
@interface JMapWaypoint : JMapBaseModel
/**
 *  Unit number field set by user in the CMS.
 */
@property (nonatomic, strong, readonly, nullable) NSString *unitNumber;
/**
 *  The map id associated with the waypoint.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *mapId;
/**
 *  The coordinates of the waypoint in the form of [x,y].
 */
@property (nonatomic, strong, readonly, nullable) NSArray <NSNumber *>* coordinates;
/**
 *  List of JMapAssociation objects for the waypoint. Associations contain an array of destination and amenities ID's.
 */
@property (nonatomic, strong, readonly, nullable) JMapAssociation *associations;
/**
 *  Initializes a JMapWaypoint.
 *
 *  @param dict An NSDictionary parsed from the server.
 *  @return An initialized JMapWaypoint instance.
 */
-(nullable instancetype)initWithDictionary:(nonnull NSDictionary *)dict;
@end
