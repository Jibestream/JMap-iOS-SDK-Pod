//
//  JMapAmenity.h
//  JMapCore
//
//  Created by Louie Yuen on 2016-09-22.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>

@class JMapLocation;
@class JMapUriCollection;
@class JMapWaypoint;

/**
 *  The JMapAmenity model.
 */
@interface JMapAmenity : JMapBaseModel

/**
 *  The customer ID of the amenity.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *customerId;
/**
 *  The name of the amenity.
 */
@property (nonatomic, strong, readonly, nullable) NSString *name;
/**
 *  The description of the amenity.
 */
@property (nonatomic, strong, readonly, nullable) NSString *description;
/**
 *  The display order of the amenity.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *displayOrder;
/**
 *  The primary Uri ID of the amenity.
 */
@property (nonatomic, strong, readonly, nullable) NSNumber *primaryUriId;
/**
 *  List of extensor objects of type NSDictionary associated with the amenity.
 */
@property (nonatomic, strong, readonly, nullable) NSDictionary *extensors;
/**
 *  The list of JMapLocation objects associated to the amenity.
 */
@property (nonatomic, strong, readonly, nullable) NSArray<JMapLocation*> *locations;
/**
 *  The Uri collection of the amenity.
 */
@property (nonatomic, strong, readonly, nullable) JMapUriCollection *uris;
/**
 *  The keywords associated to the amenity.
 */
@property (nonatomic, strong, readonly, nullable) NSArray<NSString*> *keywords;
/**
 *  The SVG string of the amenity.
 */
@property (nonatomic, strong, readonly, nullable) NSString *svg;
/**
 *  The list of JMapWaypoint objects associated to the amenity.
 */
@property (nonatomic, strong, readonly, nullable) NSArray<JMapWaypoint *>*waypoints;
/**
 *  Initializes a JMapAmenity.
 *
 *  @param dict An NSDictionary parsed from the server.
 *  @return An initialized JMapAmenity instance.
 */
-(nullable instancetype)initWithDictionary:(nonnull NSDictionary *)dict;

@end
