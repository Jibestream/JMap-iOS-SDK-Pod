//
//  JMapUserLocation.h
//  JMapRendering
//
//  Created by Louie Yuen on 2016-11-08.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "JMapMovingObject.h"

/**
 *  The JMapUserLocation object.
 */
@interface JMapUserLocation : JMapMovingObject
/**
 *  Set whether the item view be centered on the view port
 */
@property (nonatomic, assign) BOOL tracking;
/**
 *  Set whether the wayfinding path auto reroute based on the user locaton
 */
@property (nonatomic, readonly) BOOL shouldAutoRerouteWayfindingPath;
/**
 *  Returns the threshold of when the the wayfindng path should auto reroute on the map, measured in pixels
 */
@property (nonatomic, readonly) float autoRerouteWayfindingPathThreshold;

/**
 *  A singleton JMapUserLocation instance
 */
+ (instancetype)sharedInstance;

/**
 *  Set behaviour of the blue dot to reroute the wayfidning path on the map
 */
-(void)autoRerouteWayfindingPathWithThreshold:(float)threshold;

@end
