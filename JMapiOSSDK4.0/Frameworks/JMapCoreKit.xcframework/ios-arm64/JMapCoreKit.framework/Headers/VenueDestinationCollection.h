//
//  VenueDestinationCollection.h
//  JMapCoreKit
//
//  Created by Sonam Sodani on 2021-07-15.
//  Copyright © 2021 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>


@class JMapVenueDestination;
@class JMapDestination;

@interface VenueDestinationCollection : NSObject

/**
 *  Initializes a VenueDestinationCollection.
 *
 *  @param items An NSDictionary parsed from the server.
 *  @return An initialized VenueDestinationCollection instance.
 */
-(instancetype _Nonnull )initWithItems:(nonnull NSArray<JMapVenueDestination *>*)items;

/**
 *  Gets all JMapVenueDestination objects in collection.
 *
 *  @return An NSArray of JMapVenueDestination objects.
 */
- (nullable NSArray <JMapVenueDestination *>*)getAll;

/**
 *  Gets JMapVenueDestination object for venueId
 *
 *  @param venueId NSInteger venue ID to search for.
 *  @return JMapVenueDestination object for the venueId
 */
- (nullable JMapVenueDestination *)getByVenueId:(NSInteger)venueId;

/**
 *  Gets JMapVenueDestination object containing destinationId
 *
 *  @param destinationId NSInteger destination ID to search for.
 *  @return JMapVenueDestination object containing destinationId
 */
- (nullable JMapVenueDestination *)getByDestinationId:(NSInteger)destinationId ;

/**
 *  Gets list of JMapVenueDestination objects containing destinations with name
 *
 *  @param name NSString name to search for.
 *  @return An NSArray of JMapVenueDestination objects containing destinations associated to the name.
 */
- (nullable NSArray <JMapVenueDestination *>*)getByDestinationName:(nonnull NSString *)name;

/**
 *  Gets list of JMapVenueDestination objects containing destinations with external ID
 *
 *  @param externalId NSString ID to search for.
 *  @return An NSArray of JMapVenueDestination objects containing destinations associated to the external ID.
 */
- (nullable NSArray <JMapVenueDestination *>*)getByDestinationExternalId:(nonnull NSString *)externalId;

/**
 *  Gets list of JMapVenueDestination objects containing destinations with tag
 *
 *  @param tag NSString to search for.
 *  @return An NSArray of JMapVenueDestination objects containing destinations associated to the tag.
 */
- (nullable NSArray <JMapVenueDestination *>*)getByDestinationTag:(nonnull NSString *)tag;

/**
 *  Gets list of JMapVenueDestination objects containing destinations with keyword
 *
 *  @param keyword NSString to search for.
 *  @return An NSArray of JMapVenueDestination objects containing destinations associated to the keyword.
 */
- (nullable NSArray <JMapVenueDestination *>*)getByDestinationKeyword:(nonnull NSString *)keyword;

/**
 *  Gets JMapVenueDestination object by map ID.
 *
 *  @param mapId NSInteger ID to search for.
 *  @return JMapVenueDestination object containing destinations associated to the mapId.
 */
-(nullable JMapVenueDestination *)getByDestinationMapId:(NSInteger)mapId;

/**
 *  Gets JMapVenueDestination object by waypoint ID.
 *
 *  @param waypointId NSInteger ID to search for.
 *  @return JMapVenueDestination object containing destinations associated to the waypointId.
 */
-(nullable JMapVenueDestination *)getByDestinationWaypointId:(NSInteger)waypointId;

/**
 *  Gets a list of JMapVenueDestination objects by unit number.
 *
 *  @param unitNumber An NSString unit number to search for.
 *  @return An NSArray of JMapVenueDestination objects containing destinations associated to the unit number.
 */
-(nullable JMapVenueDestination *)getByDestinationUnitNumber:(nonnull NSString *)unitNumber;


@end


