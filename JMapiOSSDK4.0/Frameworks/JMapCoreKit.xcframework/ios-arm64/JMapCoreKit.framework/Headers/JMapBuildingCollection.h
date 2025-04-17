//
//  JMapBuildingCollection.h
//  JMapCore
//
//  Created by Aaron Wong on 2016-10-04.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>

/**
 *  The JMapBuildingCollection model.
 */
@interface JMapBuildingCollection : JMapBaseCollection
/**
 *  Gets the default building object.
 *
 *  @return A default JMapBuilding object, nil if default is not set.
 */
- (nullable JMapBuilding *)getDefault;
/**
 *  Assigns default building ID in the building collection.
 *
 *  @param defaultId NSInteger ID value.
 */
- (void)assignDefaultBuildingWithId:(NSInteger)defaultId;
/**
 *  Gets all the JMapBuilding objects in the collection.
 *
 *  @return An NSArray of JMapBuilding objects.
 */
- (nonnull NSArray <JMapBuilding *>*)getAll;
/**
 *  Gets a list of JMapBuilding objects by external ID.
 *
 *  @param externalId The ID to search for.
 *  @return An NSArray of JMapBuilding objects associated to the external ID.
 */
- (nonnull NSArray <JMapBuilding *>*)getByExternalId:(nonnull NSString *)externalId;
/**
 *  Gets a JMapBuilding object by ID in the collection.
 *
 *  @param id The ID to search for.
 *  @return A JMapBuilding associated to the ID or a nil if JMapBuilding with ID does not exist.
 */
- (nullable JMapBuilding *)getById:(NSInteger)id;
/**
 *  Gets a JMapBuilding object by name.
 *
 *  @param name A NSString name to search for.
 *  @return A JMapBuilding object associated to the name.
 */
-(nullable JMapBuilding *)getByName:(nonnull NSString *)name;
/**
 *  Gets a JMapBuilding object by floor.
 *
 *  @param floor The JMapFloor object to search for.
 *  @return A JMapBuilding object associated to the floor.
 */
- (nullable JMapBuilding *)getByFloor:(nonnull JMapFloor *)floor;
/**
 *  Gets a JMapBuilding object by map.
 *
 *  @param map The JMapMap to search for.
 *  @return A JMapBuilding object associated to the map.
 */
- (nullable JMapBuilding *)getByMap:(nonnull JMapMap *)map;
/**
 *  Gets a JMapFloor object by map
 *
 *  @param map The JMapMap to search for.
 *  @return A JMapFloor object associated to the map.
 */
- (nullable JMapFloor *)getFloorByMap:(nonnull JMapMap *)map;
/**
 *  Gets all JMapFloor objects.
 *
 *  @return A NSArray of JMapFloor objects.
 */
- (nonnull NSArray <JMapFloor*> *)getAllFloors;

@end
