//
//  JMapBaseModel.h
//  JMapCore
//
//  Created by Louie Yuen on 2016-09-21.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 *  The JMapBaseModel model.
 */
@interface JMapBaseModel : NSObject
/**
 *  The ID of the base model.
 */
@property (nonatomic, strong, nonnull) NSNumber *id;
/**
 *  The external ID of the base model.
 */
@property (nonatomic, strong, nullable) NSString *externalId;
/**
 *  Initializes a JMapBaseModel.
 *
 *  @param objectId An NSNumber ID associated to the base model.
 *  @param externalId An NSString external ID associated to the base model.
 *  @return An initialized JMapBaseModel instance.
 */
- (nonnull instancetype)initWithId:(nonnull NSNumber *)objectId externalId:(nonnull NSString *)externalId;
/**
 *  Initializes a JMapBaseModel.
 *
 *  @param dict An NSDictionary parsed from the server.
 *  @return An initialized JMapBaseModel instance.
 */
- (nullable instancetype)initWithDictionary:(nonnull NSDictionary *)dict;

@end
