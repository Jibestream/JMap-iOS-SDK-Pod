//
//  JMapAssociation.h
//  JMapCore
//
//  Created by Aaron Wong on 2016-08-17.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>
/**
 *  The JMapAssociation model.
 */
@interface JMapAssociation : JMapBaseModel
/**
 *  The list of destination ID's that the object is associated with.
 */
@property (nonatomic, strong, readonly) NSArray <NSNumber*>* destinations;
/**
 *  The list of amenity ID's that the object is associated with.
 */
@property (nonatomic, strong, readonly) NSArray <NSNumber*>* amenities;
/**
 *  Initializes a JMapAssociation.
 *
 *  @param dict An NSDictionary parsed from the server.
 *  @return An initialized JMapAssociation instance.
 */
-(instancetype)initWithDictionary:(NSDictionary *)dict;
@end
