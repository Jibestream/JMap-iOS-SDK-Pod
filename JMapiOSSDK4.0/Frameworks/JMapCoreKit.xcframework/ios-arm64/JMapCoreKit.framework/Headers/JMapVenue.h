//
//  JMapVenue.h
//  JMapCore
//
//  Created by Louie Yuen on 2016-09-21.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>

@class JMapWaypoint;
@class JMapMap;
@class JMapBuildingCollection;
@class JMapDestinationCollection;
@class JMapAmenityCollection;
@class JMapMapCollection;
@class JMapPathTypeCollection;
@class JMapPosition;

/**
 *  The JMapVenue model.
 */
@interface JMapVenue : JMapBaseModel
/**
 *  The name of the venue.
 */
@property (nonatomic, strong, readonly, nullable) NSString *name;
/**
 *  The map id associated with the venue.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *mapId;
/**
 *  The JMapPosition object associated with the venue.
 */
@property (nonatomic, strong, readonly, nullable) JMapPosition *coordinates;

@end
