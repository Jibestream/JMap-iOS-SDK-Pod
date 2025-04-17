//
//  JMapActiveVenue.h
//  JMapCore
//
//  Created by Louie Yuen on 2016-10-17.
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
@class JMapMapLabelCollection;
@class JMapPathPerFloor;
@class JMapPosition;
@class JMapNearestElement;
@class JMapPoint;
@class JMapDestination;

/**
 *  The JMapActiveVenue model.
 */
@interface JMapActiveVenue : JMapBaseModel
/**
 *  The name of the active venue.
 */
@property (nonatomic, strong, readonly, nullable) NSString *name;
/**
 *  The map associated with the active venue
 */
@property (nonatomic, strong, readonly, nullable) JMapMap * map;
/**
 *  The venue status
 */
@property (nonatomic, assign, readonly) BOOL status;
/**
 *  The JMapPosition object associated with the active venue.
 */
@property (nonatomic, strong, readonly, nullable) JMapPosition *coordinates;
/**
 *  The JMapBuildingCollection object associated with the active venue.
 */
@property (nonatomic, strong, readonly, nullable) JMapBuildingCollection * buildings;
/**
 *  The JMapDestinationCollection object associated with the active venue.
 */
@property (nonatomic, strong, readonly, nullable) JMapDestinationCollection * destinations;
/**
 *  The JMapAmenityCollection object associated with the active venue.
 */
@property (nonatomic, strong, readonly, nullable) JMapAmenityCollection * amenities;
/**
 *  The JMapMapCollection object associated with the active venue.
 */
@property (nonatomic, strong, readonly, nullable) JMapMapCollection * maps;
/**
 *  The JMapPathTypeCollection object associated with the active venue.
 */
@property (nonatomic, strong, readonly, nullable) JMapPathTypeCollection * pathTypes;
/**
 *  The JMapMapLabelCollection object associated with the active venue.
 */
@property (nonatomic, strong, readonly, nullable) JMapMapLabelCollection * mapLabels;
/**
 *  An NSString associated to the map template id selected for the venue, defaults to nil if none are chosen.
 */
@property (nonatomic, strong, readonly, nullable) NSString * defaultMapTemplateId;
/**
 *  An NSDictionary associated to the map template data for the venue, default to nil if none are chosen.
 */
@property (nonatomic, strong, readonly, nullable) NSDictionary * mapTemplateData;
/**
 *  An NSNumber associated to how labels are displayed on the map.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *labelType;
/**
 *  An NSNumber associated to whether labels should be displayed as clusters on the map.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *clustering;
/**
 *  An NSDictionary associated to the venue for providing extensors data.
 */
@property (nonatomic, strong, readonly, nullable) NSDictionary *extensors;

/**
 *  Initializes a JMapActiveVenue.
 *
 *  @param dict An NSDictionary parsed from the server.
 *  @return An initialized JMapActiveVenue instance.
 */
-(nullable instancetype)initWithDictionary:(nonnull NSDictionary *)dict;

#pragma mark - Wayfind Helpers
/**
 *  Updates the wayfinding data to enable the wayfinding algorithm.
 *  @param completion The completion handler for when the data has been loaded successfully.
 */
- (void)updateWayfindDataWithCompletion:(nullable void(^)(BOOL success))completion;
/**
 *  Generates a list of wayfinding data with starting and ending waypoints with accessibility.
 *  @param waypointStart The starting waypoint to wayfind from.
 *  @param waypointEnd The ending waypoint to wayfind to.
 *  @param accessible The accessibility value of the wayfinding route. 0 - 100 with 100 having full accessibility.
 */
- (nonnull NSArray <JMapPathPerFloor *>*)wayfind:(nonnull JMapWaypoint *)waypointStart to:(nonnull JMapWaypoint *)waypointEnd  withAccessibility:(NSInteger)accessible;

/**
 *  Generates a list of wayfinding data and alternative wayfinding data with starting and ending waypoints with accessibility.
 *  @param waypointStart The starting waypoint to wayfind from.
 *  @param waypointEnd The ending waypoint to wayfind to.
 *  @param accessible The accessibility value of the wayfinding route. 0 - 100 with 100 having full accessibility.
 *  @param options For defining properties to set qualifying criteria for alternative path. If passed nil, default values are set
 *  @code
 *  NSDictionary *dict = @{
 *      @"optimalPathMatchRatio": NSNumber - 0~1, default 0.6 (alternativePaths path should not overlap optimal path more than 60 %)
 *      @"optimalPathDistanceRatio": NSNumber, default 2 (alternativePaths path at max can be 2 times in distance with respect to optimal path)
 *  }
 *  @param completion A callback with shortest/optimal path and alternativePaths path
 */
- (void)wayfind:(JMapWaypoint *_Nullable)waypointStart to:(JMapWaypoint *_Nullable)waypointEnd withOptions:(NSDictionary*_Nullable)options withAccessibility:(NSInteger)accessible completionHandler:(nonnull void(^)(NSArray <JMapPathPerFloor *>* _Nullable optimalPath, NSArray<NSArray <JMapPathPerFloor *>*>* _Nullable alternativePaths))completion;

/**
 *  Generates a list of ordered array of JMapPathPerFloor to show the shortest path with visiting each destination exactly once. Aslo set the order of visit to achieve the shortest route for the given list of destination
 *  @param destinations The array of destinations require to visit
 *  @param startWayPoint The JMapWaypoint indicating the start position of the user
 *  @param accessible The accessibility value of the wayfinding route. 0 - 100 with 100 having full accessibility.
 *  @param completion A callback with ordered array of JMapPathPerFloor and ordered list of destinations array provided. The order for array of JMapPathPerFloor and destination is the order of visit each destination exactly once to achieve the shortest route for the given list of destination
 */
-(void)wayfindToMultipleDestinations:(nonnull NSArray<JMapDestination *> *)destinations fromStartWayPoint:(nonnull JMapWaypoint *)startWayPoint withAccessibility:(NSInteger)accessible completionHandler:(nonnull void(^)(NSArray<NSArray <JMapPathPerFloor *>*>* _Nullable destinationPathPerFloor, NSArray<JMapDestination*>* _Nullable orderedDestinations))completion;

/**
 *  Gets the nearest waypoint in an array from a reference waypoint.
 *  @param waypointArray An NSArray of JMapWaypoint objects to search in.
 *  @param waypoint The waypoint reference to search with.
 *  @param accessible The accessibility value of the wayfinding route used for calculating distance.
 */
- (nullable JMapWaypoint *)getClosestWaypointInArray:(nonnull NSArray <JMapWaypoint *>*)waypointArray toWaypoint:(nonnull JMapWaypoint *)waypoint withAccessibility:(NSInteger)accessible;
/**
 *  Gets the closest waypoint on the map from a given coordinate.
 *  @param map The JMapMap object to search in.
 *  @param coordinate The x,y coordinate reference to search with.
 */
- (nullable JMapWaypoint *)getClosestWaypointToCoordinateOnMap:(nonnull JMapMap *)map withCoordinate:(CGPoint)coordinate;
/**
 *  Gets the nearest waypoint in an array from a reference point.
 *  @param waypointArray An NSArray of JMapWaypoint objects to search in.
 *  @param point The point reference to search with.
 */
- (nullable JMapWaypoint *)getClosestWaypointInArray:(nonnull NSArray <JMapWaypoint *>*)waypointArray toCoordinate:(CGPoint)point;
/**
 *  Gets the nearest waypoint of the searched element on the map from a given coordinate.
 *  @param element An element to search of type: JMapDestination/JMapAmenity/JMapPathType
 *  @param point The point reference to search with.
 *  @param map The JMapMap object to search in.
 *  @param completion A callback with JMapWaypoint of the nearest searched element to the point in search, searched element and JMapError.
 */
-(void)searchNearestElement:(nonnull id)element toCoordinate:(CGPoint)point forMap:(nonnull JMapMap *)map completionHandler:(nonnull void(^)(JMapWaypoint* _Nullable waypoint, id _Nullable element, JMapError* _Nullable error))completion;

#pragma mark - JMapMap Helpers

/**
 *  Gets the center latitude and longitude of the map.
 *  @return point with latitude and longitude.
 */
- (CGPoint)getCenterCoordinates;

@end
