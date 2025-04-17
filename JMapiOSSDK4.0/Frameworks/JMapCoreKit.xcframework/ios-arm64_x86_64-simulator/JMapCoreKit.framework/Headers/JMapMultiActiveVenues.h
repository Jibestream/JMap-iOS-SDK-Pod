//
//  JMapMultiActiveVenues.h
//  JMapCoreKit
//
//  Created by Sonam Sodani on 2021-08-18.
//  Copyright © 2021 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>

@class JMapPathPerFloor;

@protocol JMapMultiActiveVenuesDelegate <NSObject>

@optional

/**
 * Delegate call when multi venue wayfind data has been loaded
 */
- (void)multiVenueWayfindDataLoaded;

/**
 * Delegate call to update the venues shown on the map at the even of any venue deletion
 * @param activeVenues array of JMapActiveVenue after destroying the venues passed in destroyActiveVenue or destroyAllActiveVenues
 */
- (void)updateMapForDeletedVenues:(nonnull NSArray<JMapActiveVenue*> *)activeVenues;

@end

@interface JMapMultiActiveVenues : NSObject

/**
 *  The JMapMultiActiveVenuesDelegate of the JMapMultiActiveVenues.
 */
@property (nonatomic, assign, nullable) id <JMapMultiActiveVenuesDelegate> delegate;

/**
 *  The array of all active venue loaded in JCore.
 */
@property(nonatomic,readonly,strong,nonnull) NSArray<JMapActiveVenue *> *activeVenues;

/**
 *  The dictionary showing the connection between the loaded venues
 */
@property(nonatomic,readonly,strong,nonnull) NSDictionary <NSString *, NSDictionary <NSString *, NSString * > *> *venueConnections;

/**
 *  Initializes a JMapMultiActiveVenues.
 *
 *  @param activeVenues An Array of generated JMapActiveVenue objects
 *  @return An initialized JMapActiveVenue instance.
 */
-(nonnull instancetype)initWithActiveVenues:(nonnull NSArray<JMapActiveVenue *> *)activeVenues;

/**
 *  Destroy the given ActiveVenues from the exsisting list of the ActiveVenues.
 *
 *  @param activeVenues The list of activeVenues to delete.
 */
-(void)destroyActiveVenue:(nonnull NSArray<JMapActiveVenue *> *)activeVenues ;

/**
 * destroy  all activeVenues
 */
-(void)destroyAllActiveVenues;
#pragma mark - Wayfind Helpers
/**
 *  Updates the wayfinding data of all the loaded active venues to enable the wayfinding algorithm.
 *
 *  @param completion The completion handler for when the data has been loaded successfully.
 */
-(void)updateMultiVenueWayfindDataWithCompletion:(nullable void(^)(BOOL success))completion;


/**
 *  Generates a list of wayfinding data with starting waypoint and ending waypoint is or is not on the same venue and the venues are internally connected.
 *
 *  @param waypointStart The starting waypoint to wayfind from.
 *  @param waypointEnd The ending waypoint to wayfind to.
 *  @param accessible The accessibility value of the wayfinding route. 0 - 100 with 100 having full accessibility.
 *  @return an array of JMapPathPerFloor object.
 */
- (nonnull NSArray <JMapPathPerFloor *>*)wayfind:(nonnull JMapWaypoint *)waypointStart to:(nonnull JMapWaypoint *)waypointEnd withAccessibility:(NSInteger)accessible;

/**
 *  Gets JMapActiveVenue object by id.
 *
 *  @param id The activeVenue id to search for.
 *  @return JMapActiveVenue object associated to the id.
 */
-(nullable JMapActiveVenue *)getVenueById:(int)id;

/**
 *  Gets JMapActiveVenue object by mapId.
 *
 *  @param mapId The activeVenue map id to search for.
 *  @return JMapActiveVenue object associated to the map id.
 */
-(nullable JMapActiveVenue *)getVenueByMapId:(int)mapId;

/**
 *  Gets JMapActiveVenue objects by venue name.
 *
 *  @param name The venue name to search for.
 *  @return An array of JMapActiveVenue objects associated to the name.
 */
-(nullable NSArray<JMapActiveVenue *> *)getVenueByName:(nonnull NSString*)name;

/**
 *  Gets JMapWaypoint objects by venue ids.
 *
 *  @param venueIds The array of venue ids to search for.
 *  @return An array of JMapWaypoints which has externalId = Exit. These waypoints include waypoints from venues which are conencted to the venue in rference.
 */
-(nonnull NSArray<JMapWaypoint*>*)getExitWayPoints:(nonnull NSArray*)venueIds;

@end



