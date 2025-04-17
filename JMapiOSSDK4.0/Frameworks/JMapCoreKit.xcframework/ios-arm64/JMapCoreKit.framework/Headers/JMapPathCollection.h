//
//  JMapPathCollection.h
//  JMapCore
//
//  Created by Louie Yuen on 2016-09-28.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>

@class JMapPathType;
@class JMapWaypoint;
@class JMapPath;

/**
 *  The JMapPathCollection model.
 */
@interface JMapPathCollection : JMapBaseCollection

/**
 *  Gets all the JMapPath objects in the collection.
 *
 *  @return An NSArray of JMapPath objects.
 */
- (nonnull NSArray <JMapPath *>*)getAll;
/**
 *  Gets a list of JMapPath objects by external ID.
 *
 *  @param externalId The ID to search for.
 *  @return An NSArray of JMapWaypoint objects associated to the external ID.
 */
- (nonnull NSArray <JMapPath *>*)getByExternalId:(nonnull NSString *)externalId;
/**
 *  Gets a JMapPath object by ID in the collection.
 *
 *  @param id The ID to search for.
 *  @return A JMapPath object associated to the ID or nil if JMapPath with ID does not exist.
 */
- (nullable JMapPath *)getById:(NSInteger)id;
/**
 *  Gets a list of JMapPath objects by path type.
 * 
 *  @param pathType The JMapPathType object to search for.
 *  @return An NSArray of JMapPath objects associated to the path type.
 */
-(nonnull NSArray <JMapPath*>*)getByPathType:(nonnull JMapPathType *)pathType;
/**
 *  Gets a list of JMapPath objects by name.
 *
 *  @param name An NSString name to search for.
 *  @return An NSArray of JMapPath objects associated to the name.
 */
-(nonnull NSArray <JMapPath*>*)getByName:(nonnull NSString *)name;
/**
 *  Gets a list of JMapPath objects by waypoint.
 *
 *  @param waypoint The JMapWaypoint object to search for.
 *  @return An NSArray of JMapPath objects associated to the waypoint.
 */
-(nonnull NSArray <JMapPath*>*)getByWaypoint:(nonnull JMapWaypoint *)waypoint;
/**
 *  Gets a list of JMapPath objects by direction.
 *
 *  @param direction An NSInteger direction to search for.
 *  @return An NSArray of JMapPath objects associated to the direction.
 */
-(nonnull NSArray <JMapPath*>*)getByDirection:(NSInteger)direction;

@end
