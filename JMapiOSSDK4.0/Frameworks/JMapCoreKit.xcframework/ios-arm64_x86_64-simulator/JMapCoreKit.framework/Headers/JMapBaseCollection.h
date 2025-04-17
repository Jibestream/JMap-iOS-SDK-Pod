//
//  JMapBaseCollection.h
//  JMapCore
//
//  Created by Louie Yuen on 2016-09-23.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JMapCoreKit/JMapBaseModel.h>

/**
 *  The JMapBaseCollection model.
 */
@interface JMapBaseCollection : NSObject
/**
 *  The child collection model class extending the JMapBaseModel.
 */
@property (nonatomic, strong, readonly, nonnull) JMapBaseModel * collectionModelClass;
/**
 * Initializes a JMapBaseController.
 *
 * @return A JMapBaseCollection instance.
 */
- (nonnull instancetype)init;
/**
 * Create a batch in a collection. Used to create a collection object from an array of object data and add to the collection.
 *
 * @param dict An NSDictionary containing data to be parsed.
 * @return An NSArray of JMapBaseModel objects if found, otherwise nil. If the array is not sorted by ID the behavior is undefined.
 */
- (nonnull NSArray<JMapBaseModel*>*)createBatch:(nonnull NSDictionary *)dict;
/**
 * Assigns the child's collection model class.
 *
 * @params collectionModelClass Subclassed from JMapBaseModel.
 */
- (void)assignCollectionModelClass:(nonnull JMapBaseModel *)collectionModelClass;
/**
 * Creates the collection object. Used to create a collection object and add to the collection.
 *
 * @param dictionary An NSDictionary <NSString *, id> of object data to be parse.
 */
- (void)create:(nonnull NSDictionary <NSString *, id>*)dictionary;
/**
 * Gets the count of collection size.
 *
 * @return An NSInteger size of the collection.
 */
- (NSInteger)getCount;
/**
 * Gets all the objects in the collection.
 *
 * @return An NSArray of JMapBaseModel objects
 */
- (nonnull NSArray <JMapBaseModel *>*)getAll;

/**
 * Gets JMapBaseModel objects by external ID.
 *
 * @param externalId The ID to search for.
 * @return An NSArray of JMapBaseModel objects associated to the external ID.
 */
- (nonnull NSArray <JMapBaseModel *>*)getByExternalId:(nonnull NSString *)externalId;

/**
 * Gets JMapBaseModel objects by ID in the collection.
 *
 * @param id The ID to search for.
 * @return A JMapBaseModel associated to the ID or a nil if JMapBaseModel with ID does not exist.
 */
- (nullable JMapBaseModel *)getById:(NSInteger)id;

@end
