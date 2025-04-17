//
//  JMapMapLabelCollection.h
//  JMapCore
//
//  Created by Aaron Wong on 2016-10-04.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>
#import <JMapCoreKit/JMapMapLabelInstances.h>

@class JMapMapLabel;
@class JMapMapLabelInstances;

/**
 *  The JMapMapLabelCollection model.
 */
@interface JMapMapLabelCollection : JMapBaseCollection
/**
 *  Gets all the JMapMapLabel objects in the collection.
 *
 *  @return An NSArray of JMapMapLabel objects.
 */
- (nonnull NSArray <JMapMapLabel *>*)getAll;
/**
 *  Gets a list of JMapMapLabel objects by external ID.
 *
 *  @param externalId An NSString external ID to search for.
 *  @return An NSArray of JMapMapLabel objects associate to the external ID.
 */
- (nonnull NSArray <JMapMapLabel *>*)getByExternalId:(nonnull NSString *)externalId;
/**
 *  Gets a JMapMapLabel object by ID in the collection.
 *
 *  @param id The ID to search for.
 *  @return A JMapMapLabel associated to the ID or nil if JMapMapLabel with ID does not exist.
 */
- (nullable JMapMapLabel *)getById:(NSInteger)id;
/**
 *  Gets a list of JMapMapLabel objects by map.
 *
 *  @param map The JMapMap object to search for.
 *  @return An NSArray of JMapMapLabel objects associated to the map.
 */
- (nonnull NSArray <JMapMapLabel *>*)getByMap:(nonnull JMapMap *)map;
/**
 *  Gets a list of JMapMapLabel objects with image associations.
 *
 *  @return An NSArray of JMapMapLabel objects.
 */
- (nonnull NSArray <JMapMapLabel *>*)getLabelsWithImage;
/**
 *  Gets a list of JMapMapLabel objects without image associations.
 *
 *  @return An NSArray of JMapMapLabel objects.
 */
- (nonnull NSArray <JMapMapLabel *>*)getLabelsWithoutImage;

@end
