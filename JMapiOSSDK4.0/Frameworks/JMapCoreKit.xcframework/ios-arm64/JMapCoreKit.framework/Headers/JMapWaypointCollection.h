//
//  JMapWaypointCollection.h
//  JMapCore
//
//  Created by Louie Yuen on 2016-09-28.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>

@class JMapDestination;
@class JMapAmenity;

/**
 *  The JMapWaypointCollection model.
 */
@interface JMapWaypointCollection : JMapBaseCollection
/**
 *  Gets all the JMapWaypoint objects in the collection.
 *
 *  @return An NSArray of JMapWaypoint objects.
 */
- (nonnull NSArray <JMapWaypoint *>*)getAll;
/**
 *  Gets a JMapWaypoint object by external ID.
 *
 *  @param externalId The ID to search for.
 *  @return An NSArray of JMapWaypoint objects associated to the external ID.
 */
- (nonnull NSArray <JMapWaypoint *>*)getByExternalId:(nonnull NSString *)externalId;

/**
 *  Gets a JMapWaypoint object by ID in the collection.
 * 
 *  @param id The ID to search for.
 *  @return A JMapWaypoint object associated to the ID or nil if JMapWaypoint with ID does not exist.
 */
- (nullable JMapWaypoint *)getById:(NSInteger)id;
/**
 *  Gets a list of JMapWaypoint objects by destination.
 *
 *  @param destination A JMapDestination to search for.
 *  @return An NSArray of JMapWaypoint objects associated to the destination.
 */
-(nonnull NSArray <JMapWaypoint*>*)getByDestination:(nonnull JMapDestination *)destination;
/**
 *  Gets a list of JMapWaypoint objects by amenity.
 *
 *  @param amenity A JMapAmenity to search for.
 *  @return An NSArray of JMapWaypoint objects associated to the amenity.
 */
-(nonnull NSArray <JMapWaypoint*>*)getByAmenity:(nonnull JMapAmenity *)amenity;

@end
