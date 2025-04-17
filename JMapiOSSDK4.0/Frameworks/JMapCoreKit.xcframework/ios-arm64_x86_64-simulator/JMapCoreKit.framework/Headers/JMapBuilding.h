//
//  JMapBuilding.h
//  JMapCore
//
//  Created by Louie Yuen on 2016-09-22.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>

@class JMapPosition;
@class JMapFloorCollection;
/**
 *  The JMapBuilding model.
 */
@interface JMapBuilding : JMapBaseModel
/**
 *  The name of the building.
 */
@property (nonatomic, strong, readonly, nullable) NSString *name;
/**
 *  The JMapPosition object associated to the building.
 */
@property (nonatomic, strong, readonly, nullable) JMapPosition *coordinates;
/**
 *  The floor collection associated to the building.
 */
@property (nonatomic, strong, readonly, nullable) JMapFloorCollection *floors;
/**
 *  The venue ID that the building belongs to.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *venueId;
/**
 *  The address of the building.
 */
@property (nonatomic, strong, readonly, nullable) NSString *address;
/**
 *  The description of the building.
 */
@property (nonatomic, strong, readonly, nullable) NSString *description;

/**
 *  Initializes a JMapBuilding.
 *
 *  @param dict An NSDictionary parsed from the server.
 *  @return An initialized JMapBuilding instance.
 */
-(nullable instancetype)initWithDictionary:(nonnull NSDictionary *)dict;

@end
