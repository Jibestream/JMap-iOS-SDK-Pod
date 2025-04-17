//
//  JMapClient.h
//  JMap
//
//  Created by Aaron Wong on 2016-08-04.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <JMapCoreKit/JMapCoreKit.h>

@class JMapVenueCollection;
@class JMapVenue;
@class JMapBuilding;
@class JMapActiveVenue;
@class JMapError;
@class JMapLocaleCollection;
@class JMapLocale;
@class JMapUtils;
@class VenueDestinationCollection;
@class JMapMultiActiveVenues;

/**
 *  The JMapJCoreDelegate model.
 */
@protocol JMapJCoreDelegate <NSObject>

@optional

/**
 * Delegate call when wayfind data has been loaded
 */
- (void)wayfindDataLoaded;

@end

#pragma mark - JMapView
/**
 *  The JMapJCore model.
 */
@interface JMapJCore : NSObject

/**
 *  The JMapJCoreDelegate of the JCore.
 */
@property (nonatomic, assign, nullable) id <JMapJCoreDelegate> delegate;
/**
 *  The name of the JCore.
 */
@property (nonatomic, strong, readonly, nullable) NSString *name;
/**
 *  The venue collection of the JCore.
 */
@property (nonatomic, strong, readonly, nullable) JMapVenueCollection *venues;
/**
 *  The locale collection of the JCore.
 */
@property (nonatomic, strong, readonly, nullable) JMapLocaleCollection *locales;
/**
 *  The active venue of the JCore.
 */
@property (nonatomic, strong, readonly, nullable) JMapActiveVenue *activeVenue;
/**
 *  The locale string used for defining localization. Defaults to en-US
 */
@property (nonatomic, strong, readonly, nullable) NSString *locale;

/**
 *  The Venue and Destination collection of the JCore.
 */
@property(nonatomic, strong, readonly, nullable) VenueDestinationCollection *venueDestinations;

#pragma mark - Versioning

/**
 *  Gets the SDK version.
 *
 *  @return Version string of the current SDK.
 */
-(nonnull NSString *)getSDKVersion;

/**
 *  Gets the server version.
 *
 *  @return Version string of the currently targeted server.
 */
-(nonnull NSString *)getServerVersion;

#pragma mark - Destroy Methods
/**
 *  Destroys and deallocates active venue and all assocated classes from memory.
 */
- (void)destroyActiveVenue;

#pragma mark - init methods

/**
 *  Initializes the JMapJCore.
 *
 *  @param customerId An NSInteger unique customer ID.
 *  @param reload A BOOL to set caching option.
 *  @param host A NSString host name/server endpoint.
 *  @param clientId The clientID for authentication.
 *  @param clientSecret The clientSecret for authentication.
 *  @return An initialized JMapJCore instance.
 */
- (nonnull instancetype)initWithCustomerId:(NSInteger)customerId autoReloadCache:(BOOL)reload host:(nonnull NSString *)host clientId:(nonnull NSString *)clientId clientSecret:(nonnull NSString *)clientSecret;

/**
 *  Initializes the JMapJCore with Options dictionary.
 *
 *  @param options An NSDictionary containing key-value pair configurations
 *  @return An initialized JMapJCore instance.
 *  @code NSDictionary *dict = [NSDictionary dictionaryWithObjectsAndKeys:@(123), @"customerId", @"cId", @"clientId", @"cSecret", @"clientSecret", @"https://example.com", @"host", nil];
 */
- (nonnull instancetype)initCustomerWithDictionary:(nonnull NSDictionary *)options;

#pragma mark - populate methods
/**
 *  Gets all venues with API call to the server.
 *
 *  @param completionHandler A callback that returns an NSArray of JMapVenue objects.
 */
-(void)getVenues:(nonnull void(^)(NSArray <JMapVenue*>* _Nonnull venues, JMapError* _Nullable error))completionHandler;

/**
 *  Gets all venues with matching external Ids API call to the server.
 *
 *  @param externalIds A list of NSString Id's to check
 *  @param completionHandler A callback that returns an NSArray of JMapVenue objects with corresponding external Ids.
 */
-(void)getVenuesWithExternalIds:(nonnull NSArray <NSString *>*)externalIds completionHandler:(nonnull void(^)(NSArray <JMapVenue*>* _Nonnull venues, JMapError* _Nullable error))completionHandler;

/**
 *  Gets all locales with API call to the server.
 *
 *  @param completionHandler A callback that returns an NSArray of JMapLocale objects.
 */
-(void)getLocales:(nonnull void(^)(NSArray <JMapLocale*>* _Nonnull locales, JMapError* _Nullable error))completionHandler;

/**
 *  Populates venue by venue object.
 *
 *  @param venue A JMapVenue object for data to be populated.
 *  @param completionHandler A callback that returns a JMapActiveVenue object and JMapError for debugging.
 */
-(void)populateVenue:(nonnull JMapVenue *)venue completionHandler:(nonnull void(^)(JMapActiveVenue * _Nullable activeVenue, JMapError* _Nullable error))completionHandler;

/**
 *  Populates venue by venue ID.
 *
 *  @param venueId An NSInteger associated to the venue for data to be populated.
 *  @param completionHandler A callback that returns a JMapActiveVenue object and JMapError for debugging.
 */
-(void)populateVenueByVenueId:(NSInteger)venueId completionHandler:(nonnull void(^)(JMapActiveVenue * _Nullable activeVenue, JMapError* _Nullable error))completionHandler;

/**
 *  Populates venue by venue ID and also populates default building.
 *
 *  @param venueId An NSInteger associated to the venue for data to be populated.
 *  @param completionHandler A callback that returns a JMapActiveVenue object and JMapError for debugging.
 */
-(void)populateVenueWithDefaultBuildingByVenueId:(NSInteger)venueId completionHandler:(nonnull void(^)(JMapActiveVenue * _Nullable activeVenue, JMapError* _Nullable error))completionHandler;

/**
 *  Populates building in venue and building ID.
 *
 *  @param venue A JMapActiveVenue object associated to the building.
 *  @param buildingId An NSInteger ID associated to the building.
 *  @param completionHandler A callback that returns a JMapActiveVenue object and JMapError debugging.
 */
-(void)populateBuildingInVenue:(nonnull JMapActiveVenue *)venue withBuildingId:(NSInteger)buildingId completionHandler:(nonnull void(^)(JMapActiveVenue * _Nullable activeVenue, JMapError* _Nullable error))completionHandler;

/**
 *  Populates venue by venue ID and building ID.
 *
 *  @param venueId An NSInteger ID associated to the venue.
 *  @param buildingId An NSInteger ID associated to the building in the venue.
 *  @param completionHandler A callback that returns a JMapActiveVenue object and JMapError debugging.
 */
-(void)populateVenueWithBuildingByVenueId:(NSInteger)venueId withBuildingId:(NSInteger)buildingId completionHandler:(nonnull void(^)(JMapActiveVenue * _Nullable activeVenue, JMapError* _Nullable error))completionHandler;

/**
 *  Get Request : method used to make additional GET requests to the JACS server using JCore
 *  @param url - the request to make. Each request is prepended with the host/customer id
 *  and example of this argument would be: `/venue/123/zone/full` where 123 is the venue Id.
 *  @param completionHandler - callback method.
 */
- (void)getRequest:(nonnull NSString *)url completionHandler:(nonnull void(^)(NSDictionary * _Nullable data, JMapError* _Nullable error))completionHandler;

#pragma mark - Multiple ActiveVenue
/**
 *  Populates multiple venues by venue ID and also populates corresponding default building.
 *
 *  @param venueIds An array NSInteger ID associated to the venues.
 *  @param completionHandler A callback that returns a JMapMultiActiveVenues object and JMapError debugging.
 */
-(void)populateVenuesWithDefaultBuilding:(nonnull NSArray <NSNumber*>*)venueIds completionHandler:(nonnull void(^)(JMapMultiActiveVenues* _Nullable multiActiveVenues, JMapError* _Nullable error))completionHandler;

#pragma mark - Load destinations for venues
/**
 *  Populates destinations by venue IDs
 *
 *  @param venueIds An array of venue IDs
 *  @param completionHandler A callback that returns a VenueDestinationCollection object and JMapError debugging.
 */
-(void)populateDestinationsForVenues:(NSArray <NSNumber*>*_Nullable)venueIds completionHandler:(nonnull void(^)(VenueDestinationCollection * _Nullable venueDestinations, JMapError* _Nullable error))completionHandler;

#pragma mark - Cache
/**
 *  Clears all cache that was previously store on the device.
 */
- (void)clearAllCache;

/**
 *  Clears cache by venue ID
 *
 *  @param venueId The venue ID to purge cache data.
 */
- (void)clearCacheByVenueId:(NSInteger)venueId;

@end
