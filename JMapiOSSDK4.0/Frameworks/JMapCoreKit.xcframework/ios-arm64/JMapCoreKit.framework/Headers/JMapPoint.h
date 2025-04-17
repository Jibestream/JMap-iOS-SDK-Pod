//
//  JMapPoint.h
//  JMapCore
//
//  Created by Louie Yuen on 2016-11-03.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  The JMapPathPerFloor model.
 */
@interface JMapPoint : NSObject
/**
 *  The x coordinate of the JMapPoint.
 */
@property (nonatomic) float x;
/**
 *  The y coordinate of the JMapPoint.
 */
@property (nonatomic) float y;
/**
 *  The map ID of the JMapPoint.
 */
@property (nonatomic) float z;
/**
 *  Initializes a JMapPoint.
 *
 *  @param x The x coordinate of the point.
 *  @param y The y coordinate of the point.
 *  @param z The map ID of the point.
 *  @return An initialized JMapPoint instance.
 */
-(id)initWithX:(float)x Y:(float)y Z:(float)z;

@end
