//
//  JMapFloorCollection.h
//  JMapCore
//
//  Created by Aaron Wong on 2016-09-28.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>

@class JMapFloor;
@class JMapDestination;

/**
 *  The JMapFloorCollection model.
 */
@interface JMapFloorCollection : JMapBaseCollection
/**
 *  Gets the default JMapFloor object.
 *
 *  @return The default JMapFloor object, nil if default is not set.
 */
- (nullable JMapFloor *)getDefault;
/**
 *  Gets all the JMapFloor objects in the collection.
 *
 *  @return An NSArray of JMapFloor objects.
 */
- (nonnull NSArray <JMapFloor *>*)getAll;

/**
 *  Gets a list of JMapFloor objects by external ID.
 *
 *  @param externalId The ID to search for.
 *  @return An NSArray of JMapFloor objects associated to the external ID.
 */
- (nonnull NSArray <JMapFloor *>*)getByExternalId:(nonnull NSString *)externalId;
/**
 *  Gets a JMapFloor object by ID in the collection.
 *
 *  @param id The ID to search for.
 *  @return A JMapFloor associated to the ID or a nil if JMapFloor with the ID does not exist.
 */
- (nullable JMapFloor *)getById:(NSInteger)id;
/**
 *  Gets a JMapFloor object by level.
 *
 *  @param level The level number to search for.
 *  @return A JMapFloor object associated to the level.
 */
- (nullable JMapFloor *)getByLevel:(int)level;
/**
 *  Gets a JMapFloor object by map.
 *
 *  @return A JMapFloor object associated to the map.
 */
- (nullable JMapFloor *)getByMap:(nonnull JMapMap *)map;
/**
 *  Gets a list of JMapFloor objects by destination.
 *
 *  @param destination The destination to search for.
 *  @return An NSArray of JMapFloor objects associated to the destination.
 */
- (nonnull NSArray <JMapFloor *>*)getByDestination:(nonnull JMapDestination *)destination;
/**
 *  Gets all JMapFloor objects sorted by preference.
 *
 *  @return An NSArray of all JMapFloor objects ordered by preference.
 */
- (nonnull NSArray <JMapFloor *>*)getAllSortedByPreference;
/**
 *  Gets all JMapFloor objects sorted by level.
 *
 *  @return An NSArray of all JMapFloor objects ordered by level.
 */
- (nonnull NSArray <JMapFloor *>*)getAllSortedByLevel;
/**
 *  Gets all JMapFloor objects sorted by elevation.
 *
 *  @return An NSArray of all JMapFloor objects ordered by elevation.
 */
- (nonnull NSArray <JMapFloor *>*)getAllSortedByElevation;

/**
 *  Gets all JMapFloor objects sorted by altitude.
 *
 *  @return An NSArray of all JMapFloor objects ordered by altitude.
 */
- (nonnull NSArray <JMapFloor *>*)getAllSortedByAltitude;

@end
