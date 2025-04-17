//
//  JMapAmenityCollection.h
//  JMapCore
//
//  Created by Aaron Wong on 2016-09-28.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>

@class JMapMap;

/**
 *  The JMapAmenityCollection model.
 */
@interface JMapAmenityCollection : JMapBaseCollection
/**
 *  Gets all the JMapAmenity objects in the collection.
 *
 *  @return An NSArray of JMapAmenity objects.
 */
- (nonnull NSArray <JMapAmenity *>*)getAll;
/**
 *  Gets a list of JMapAmenity objects by external ID.
 *
 *  @param externalId The ID to search for.
 *  @return An NSArray of JMapAmenity objects associated to the external ID.
 */
- (nonnull NSArray <JMapAmenity *>*)getByExternalId:(nonnull NSString *)externalId;
/**
 *  Gets a JMapAmenity object by ID in the collection.
 *
 *  @param id The ID to search for.
 *  @return A JMapAmenity associated to the ID or nil if JMapAmenity with ID does not exist.
 */
- (nullable JMapAmenity *)getById:(NSInteger)id;
/**
 *  Gets a list of JMapAmenity objects by waypoint.
 *
 *  @params waypoint The JMapWaypoint to search for.
 *  @return AN NSArray of JMapAmenity objects associated to the waypoint.
 */
- (nonnull NSArray <JMapAmenity *>*)getByWaypoint:(nonnull JMapWaypoint *)waypoint;
/**
 *  Gets a list of JMapAmenity objects by keyword.
 *
 *  @params keyword The NSString keyword to search for.
 *  @return AN NSArray of JMapAmenity objects associated to the keyword.
 */
- (nonnull NSArray <JMapAmenity *>*)getByKeyword:(nonnull NSString *)keyword;
/**
 *  Gets a list of JMapAmenity objects by floor.
 *
 *  @params floor The JMapFloor object to search for.
 *  @return An NSArray of JMapAmenity objects associated to the floor.
 */
- (nonnull NSArray <JMapAmenity *>*)getByFloor:(nonnull JMapFloor *)floor;
/**
 *  Gets a list of JMapAmenity objects by map.
 *
 *  @params map The JMapMap object to search for.
 *  @return An NSArray of JMapAmenity objects associated to the map.
 */
- (nonnull NSArray <JMapAmenity *>*)getByMap:(nonnull JMapMap *)map;

/**
 *  Gets a list of JMapAmenity objects by building.
 *
 *  @params building The JMapBuilding object to search for.
 *  @return An NSArray of JMapAmenity objects associated to the building.
 */
- (nonnull NSArray <JMapAmenity *>*)getByBuilding:(nonnull JMapBuilding *)building;

/**
 *  Gets a list of JMapAmenity objects by name.
 *
 *  @params name The NSString name to search for.
 *  @return An NSArray of JMapAmenity objects associated to the name.
 */
- (nonnull NSArray <JMapAmenity *>*)getByName:(nonnull NSString *)name;

@end
