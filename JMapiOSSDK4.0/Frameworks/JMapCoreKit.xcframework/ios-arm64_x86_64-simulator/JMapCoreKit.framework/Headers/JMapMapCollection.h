//
//  JMapMapCollection.h
//  JMapCore
//
//  Created by Louie Yuen on 2016-09-30.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>

@class JMapWaypoint;
@class JMapDestination;
@class JMapAmenity;
@class JMapFloor;
@class JMapMap;
@class JMapBuilding;

/**
 *  The JMapMapCollection model.
 */
@interface JMapMapCollection : JMapBaseCollection
/**
 *  Gets all the JMapMap objects in the collection.
 *
 *  @return An NSArray of JMapWaypoint objects.
 */
- (nonnull NSArray <JMapMap *>*)getAll;
/**
 *  Gets a list of JMapMap objects by external ID.
 *
 *  @param externalId The ID to search for.
 *  @return An NSArray of JMapMap objects associated to the external ID.
 */
- (nonnull NSArray <JMapMap *>*)getByExternalId:(nonnull NSString *)externalId;
/**
 *  Geta a JMapMap object by ID in the collection.
 *
 *  @param id The ID to search for.
 *  @return A JMapMap associated to the ID or nil if JMapMap with ID does not exist.
 */
- (nullable JMapMap *)getById:(NSInteger)id;
/**
 *  Gets a list of JMapWaypoint objects on the map.
 *
 *  @return An NSArray of JMapWaypoint objects.
 */
-(nonnull NSArray <JMapWaypoint*>*)getAllWaypoints;
/**
 *  Gets a list of JMapWaypoint objects with destination associations.
 *
 *  @return An NSArray* of JMapWaypoint objects.
 */
-(nonnull NSArray <JMapWaypoint*>*)getWaypointsWithDestinations;
/**
 *  Gets a list of JMapWaypoint objects with amenity associations.
 *
 *  @return An NSArray of JMapWaypoint objects.
 */
-(nonnull NSArray <JMapWaypoint*>*)getWaypointsWithAmenities;
/**
 *  Gets a list of JMapWaypoint objects by destination.
 *
 *  @param destination The JMapDestination object to search for.
 *  @return An NSArray of JMapWaypoint objects associated to the destination.
 */
-(nonnull NSArray <JMapWaypoint*>*)getWaypointsByDestination:(nonnull JMapDestination*)destination;
/**
 *  Gets a list of JMapWaypoint objects by amenity.
 *
 *  @param amenity The JMapAmenity object to search for.
 *  @return An NSArray of JMapWaypoint objects associated to the amenity.
 */
-(nonnull NSArray <JMapWaypoint*>*)getWaypointsByAmenity:(nonnull JMapAmenity*)amenity;
/**
 *  Gets a list of JMapWaypoint objects by floor.
 *
 *  @param floor The JMapFloor object to search for.
 *  @return An NSArray of JMapWaypoint objects associated to the floor.
 */
-(nonnull NSArray <JMapWaypoint*>*)getWaypointsByFloor:(nonnull JMapFloor*)floor;
/**
 *  Gets a list of JMapWaypoint objects by map.
 *
 *  @param map The JMapMap object to search for.
 *  @return An NSArray of JMapWaypoint objects associated to the map.
 */
-(nonnull NSArray <JMapWaypoint*>*)getWaypointsByMap:(nonnull JMapMap*)map;
/**
 *  Gets a list of JMapWaypoint objects by building.
 *
 *  @param building The JMapBuilding object to search for.
 *  @return An NSArray of JMapWaypoint objects associated to the building.
 */
-(nonnull NSArray <JMapWaypoint*>*)getWaypointsByBuilding:(nonnull JMapBuilding*)building;


@end
