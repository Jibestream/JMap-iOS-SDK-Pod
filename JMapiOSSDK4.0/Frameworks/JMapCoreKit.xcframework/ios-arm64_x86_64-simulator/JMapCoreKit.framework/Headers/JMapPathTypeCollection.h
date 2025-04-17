//
//  JMapPathTypeCollection.h
//  JMapCore
//
//  Created by Louie Yuen on 2016-09-29.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>

@class JMapPathType;

/**
 *  The JMapPathTypeCollection model.
 */
@interface JMapPathTypeCollection : JMapBaseCollection

/**
 *  Gets all JMapPathType objects in the collection.
 *
 *  @return An NSArray of JMapPathType objects.
 */
- (nonnull NSArray <JMapPathType *>*)getAll;

/**
 *  Gets a list of JMapPathType objects by external ID.
 *
 *  @param externalId The external ID to search for.
 *  @return An NSArray of JMapPathType objects associated to the external ID.
 */
- (nonnull NSArray <JMapPathType *>*)getByExternalId:(nonnull NSString *)externalId;

/**
 *  Gets a JMapPathType object by ID in the collection.
 *
 *  @param id The ID to search for.
 *  @return A JMapPathType object associated to ID or nil if JMapPathType does not exist.
 */
- (nullable JMapPathType *)getById:(NSInteger)id;

/**
 *  Gets a list of JMapPathType objects by name.
 *
 *  @param name An NSString name associated with the path type.
 *  @return An NSArray of JMapPathType objects.
 */
-(nullable NSArray <JMapPathType *>*)getByName:(nonnull NSString *)name;

/**
 *  Get a list of JMapPathType objects by direction.
 *
 *  @param direction A NSInteger direction associated with the path type.
 *  @return An NSArray of JMapPathType objects.
 */
-(nullable NSArray <JMapPathType *>*)getByDirection:(NSInteger)direction;

@end
