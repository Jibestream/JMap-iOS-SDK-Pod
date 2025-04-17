//
//  JMapDestinationCollection.h
//  JMapCore
//
//  Created by Louie Yuen on 2016-09-23.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>

@class JMapDestination;
@class JMapBuilding;
@class JMapFloor;
@class JMapMap;
@class JMapWaypoint;

/**
 *  The JMapDestinationCollection model.
 */
@interface JMapDestinationCollection : JMapBaseCollection

/**
 *  Gets all JMapDestination objects in collection.
 *
 *  @return An NSArray of JMapDestination objects.
 */
- (nonnull NSArray <JMapDestination *>*)getAll;
/**
 *  Gets a list of JMapDestination objects by external ID.
 *
 *  @param externalId NSString ID to search for.
 *  @return An array of JMapDestination objects associase to the external ID.
 */
- (nonnull NSArray <JMapDestination *>*)getByExternalId:(nonnull NSString *)externalId;
/**
 *  Gets a JMapDestination object by ID in the collection.
 *
 *  @param id An NSInteger ID to search for.
 *  @return A JMapDestination object associated to the ID or a nil if JMapDestination with the ID does not exist.
 */
- (nullable JMapDestination *)getById:(NSInteger)id;
/**
 *  Gets a list of JMapDestination objects by tag.
 *
 *  @param tag An NSString tag to search for.
 *  @return An NSArray of JMapDestination objects associated to the tag.
 */
-(nullable NSArray <JMapDestination *>*)getByTag:(nonnull NSString *)tag;
/**
 *  Gets a list of JMapDestination objects by keyword.
 *
 *  @param keyword An NSString keyword to search for.
 *  @return An NSArray of JMapDestination objects associated to the keyword.
 */
-(nullable NSArray <JMapDestination *>*)getByKeyword:(nonnull NSString *)keyword;
/**
 *  Gets a list of JMapDestination objects by buidling.
 *
 *  @param building The JMapBuilding object to search for.
 *  @return An NSArray of JMapDestination objects associated to the building.
 */
-(nullable NSArray <JMapDestination *>*)getByBuilding:(nonnull JMapBuilding *)building;
/**
 *  Gets a list of JMapDestination objects by floor.
 *
 *  @param floor The JMapFloor object to search for.
 *  @return An NSArray of JMapDestination* objects associated to the floor.
 */
-(nullable NSArray <JMapDestination *>*)getByFloor:(nonnull JMapFloor *)floor;
/**
 *  Gets a list of JMapDestination objects by map.
 *
 *  @param map The JMapMap object to search for.
 *  @return An NSArray of JMapDestination objects associated to the map.
 */
-(nullable NSArray <JMapDestination *>*)getByMap:(nonnull JMapMap *)map;
/**
 *  Gets a list of JMapDestination objects by waypoint.
 *
 *  @param waypoint The JMapWaypoint object to search for.
 *  @return An NSArray of JMapDestination objects associated to the waypoint.
 */
-(nullable NSArray <JMapDestination *>*)getByWaypoint:(nonnull JMapWaypoint *)waypoint;
/**
 *  Gets a list of JMapDestination objects by unit number.
 *
 *  @param unitNumber An NSString unit number to search for.
 *  @return An NSArray of JMapDestination objects associated to the unit number.
 */
-(nullable NSArray <JMapDestination *>*)getByUnitNumber:(nonnull NSString *)unitNumber;

@end
