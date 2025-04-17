//
//  JMapVenueCollection.h
//  JMapCore
//
//  Created by Aaron Wong on 2016-10-04.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>

/**
 *  The JMapVenueCollection model.
 */
@interface JMapVenueCollection : JMapBaseCollection
/**
 *  Gets the default JMapVenue object.
 *
 *  @return A JMapVenue object. Nil if default venue doesn't exist.
 */
- (nullable JMapVenue *)getDefault;
/**
 *  Gets all the JMapVenue objects in collection.
 *
 *  @return An NSArray of JMapVenue objects.
 */
- (nonnull NSArray <JMapVenue *>*)getAll;
/**
 *  Gets a list of JMapVenue objects by external ID.
 *
 *  @param externalId The ID to search for.
 *  @return An NSArray of JMapVenue objects associated to the external ID.
 */
- (nonnull NSArray <JMapVenue *>*)getByExternalId:(nonnull NSString *)externalId;
/**
 *  Gets a JMapVenue object by ID in the collection.
 *
 *  @param id The ID to search for.
 *  @return A JMapVenue object associated to the ID or a nil if JMapVenue does not exist.
 */
- (nullable JMapVenue *)getById:(NSInteger)id;
/**
 *  Gets a JMapVenue by name.
 *
 *  @param name An NSString name of the venue to search for.
 *  @return A JMapVenue object result or nil if no matches found
 */
-(nullable JMapVenue *)getByName:(nonnull NSString *)name;

@end
