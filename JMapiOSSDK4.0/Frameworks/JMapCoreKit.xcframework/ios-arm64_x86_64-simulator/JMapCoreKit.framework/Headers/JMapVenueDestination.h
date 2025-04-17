//
//  JMapVenueDestination.h
//  JMapCoreKit
//
//  Created by Sonam Sodani on 2021-07-16.
//  Copyright © 2021 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>


@class JMapDestinationCollection;

@interface JMapVenueDestination : NSObject

@property (nonatomic, strong, readonly) NSNumber * _Nullable venueId;
@property (nonatomic, strong, readonly) JMapDestinationCollection * _Nullable destinations;

-(nullable instancetype)initWithDictionary:(nonnull NSDictionary *)dict;

@end
