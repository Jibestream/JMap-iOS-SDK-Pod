//
//  JMapIconStyle.h
//  JMapRendering
//
//  Created by Louie Yuen on 2016-10-21.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JMapStyle.h"

/**
 *  The JMapIconStyle model.
 */
@interface JMapIconStyle : NSObject

/**
 * Foreground styling for JMapAmenity objects
 */
@property (nonatomic, strong, readonly) JMapStyle *foregroundStyle;
/**
 * Background styling for JMapAmenity objects
 */
@property (nonatomic, strong, readonly) JMapStyle *backgroundStyle;
/**
 * Middleground styling for JMapAmenity objects
 */
@property (nonatomic, strong, readonly) JMapStyle *middlegroundStyle;
/**
 * Set width of the JMapAmenity object
 */
@property (nonatomic, strong) NSNumber *width;
/**
 * Set height of the JMapAmenity object
 */
@property (nonatomic, strong) NSNumber *height;
/**
 * Visibility of JMapAmenity object
 */
@property (nonatomic, strong) NSNumber *hidden;

/**
 * Initialization method for JMapAmenity
 * @param foreground styling, JMapStyle object
 * @param middleground styling, JMapStyle object
 * @param background styling, JMapStyle object
 * @return JMapIconStyle object
 */
-(instancetype)initWithStyleForeground:(JMapStyle *)foreground middleground:(JMapStyle *)middleground background:(JMapStyle *)background;
/**
 * Setter method for styling JMapAmenity foreground
 */
-(void)setStyleForeground:(JMapStyle *)foreground;
/**
 * Setter method for styling JMapAmenity middleground
 */
-(void)setStyleMiddleground:(JMapStyle *)middleground;
/**
 * Setter method for styling JMapAmenity background
 */
-(void)setStyleBackground:(JMapStyle *)background;

@end
