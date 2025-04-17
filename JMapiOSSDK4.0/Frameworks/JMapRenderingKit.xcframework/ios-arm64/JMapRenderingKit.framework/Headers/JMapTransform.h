//
//  JMapTransform.h
//  JMapRendering
//
//  Created by Aaron Wong on 2016-10-26.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>

/**
 *  The JMapTransform object.
 */
@interface JMapTransform : NSObject

/**
 *  The x translation of the transform
 */
@property (nonatomic, readonly, nullable) NSNumber *x;
/**
 *  The y translation of the transform
 */
@property (nonatomic, readonly, nullable) NSNumber *y;
/**
 *  The scale of the transform
 */
@property (nonatomic, readonly, nullable) NSNumber *scale;
/**
 *  The rotation of the transform
 */
@property (nonatomic, readonly, nullable) NSNumber *rotation;
/**
 *  The anchor point of the rotation
 */
@property (nonatomic, readonly, nullable) NSValue *centerPoint;
/**
 *  The animation duration of the transform
 */
@property (nonatomic, assign, readonly) NSTimeInterval duration;

/**
 *  Init method for creating a JMapTransform instance
 *
 *  @param x The x translation of the transform
 *  @param y The y translation of the transform
 *  @param scale The scale of the transform
 *  @param rotation The rotation of the transform
 *  @param center The anchor point of the rotation, defaults to canvas view center if not set
 *  @param duration The animation duration of the transform, defaults to 0
 */
- (nonnull instancetype)initWithX:(nullable NSNumber *)x y:(nullable NSNumber *)y scale:(nullable NSNumber *)scale rotation:(nullable NSNumber *)rotation atCenter:(nullable NSValue *)center duration:(NSTimeInterval)duration;

@end
