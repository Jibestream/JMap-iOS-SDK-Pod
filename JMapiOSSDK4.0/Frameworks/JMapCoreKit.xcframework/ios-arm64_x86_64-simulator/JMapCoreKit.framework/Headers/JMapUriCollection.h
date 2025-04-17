//
//  JMapUriCollection.h
//  JMapCore
//
//  Created by Louie Yuen on 2016-10-04.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>

@class JMapUri;

/**
 *  The JMapUriCollection model.
 */
@interface JMapUriCollection : JMapBaseCollection
/**
 *  Gets all the JMapUri objects in the collection.
 *
 *  @return An NSArray of JMapUri objects.
 */
- (nonnull NSArray <JMapUri *>*)getAll;
/**
 *  Gets a list of JMapUri objects by external ID.
 *
 *  @param externalId The ID to search for.
 *  @return An NSArray of JMapUri objects associated to the external ID.
 */
- (nonnull NSArray <JMapUri *>*)getByExternalId:(nonnull NSString *)externalId;
/**
 *  Gets a JMapUri object by ID in the collection.
 *
 *  @param id The ID to search for.
 *  @return A JMapUri object associated to ID or nil if JMapUri with ID does not exist.
 */
- (nullable JMapUri *)getById:(NSInteger)id;
/**
 *  Gets a list of JMapUri objects by mime type.
 *
 *  @param mimeType A NSString mime type to search for.
 *  @return An NSArray of JMapUri objects associated to the mime type.
 */
-(nonnull NSArray <JMapUri*>*)getByMimeType:(nonnull NSString *)mimeType;
/**
 *  Gets a list of JMapUri objects by resource type.
 *
 *  @param resourceType An NSString resource type to search for.
 *  @return An NSArray of JMapUri objects associated to the resource type.
 */
-(nonnull NSArray <JMapUri*>*)getByResourceType:(nonnull NSString *)resourceType;

@end
