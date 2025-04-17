//
//  JMapStyle.h
//  JMapRendering
//
//  Created by Louie Yuen on 2016-10-21.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <QuartzCore/QuartzCore.h>
#import <UIKit/UIKit.h>

/**
 *  The JMapStyle object.
 */
@interface JMapStyle : NSObject

/**
 * Init JMapStyle method
 */
-(nonnull instancetype)init;

/**
 * Init JMapStyle method
 *
 * @param style A JMapStyle object to initialize with
 */
-(nonnull instancetype)initWithStyle:(nonnull JMapStyle *)style;

/**
 * Set Bezier Path
 *
 * @param bezierPath A UIBezierPath object applied to the styling
 */
-(void)setBezPath:(nullable UIBezierPath *)bezierPath;

/**
 * Set Reference Path
 *
 * @param pathRefIn A CGPathRef object reference to path CG level
 */
-(void)setPath:(nonnull CGPathRef)pathRefIn;

/**
 * Get Bezier Path
 *
 * @return UIBezierPath object that was applied
 */
-(nullable UIBezierPath *)getPath;

/**
 * Set Path Closed Boolean
 *
 * @param closed A BOOL to determine if path is closed/opened
 */
-(void)closePath:(BOOL)closed;

/**
 * Get Path Closed
 *
 * @return BOOL indicating if path is closed/opened
 */
-(BOOL)getClosePath;

/**
 * Set Line Width
 *
 * @param thisFloat A float value to define line width
 */
-(void)setLineWidth:(float)thisFloat;

/**
 * Remove Line Width
 */
-(void)removeLineWidth;

/**
 * Has Line Width
 *
 * @return BOOL to indicate if line width exists
 */
-(BOOL)hasLineWidth;

/**
 * Get Line Width
 *
 * @return float value defined for the line width
 */
-(float)getLineWidth;

/**
 * Set Stroke Color
 *
 * @param strokeColor A UIColor object to the stroke styling
 */
-(void)setStrokeColor:(nonnull UIColor *)strokeColor;

/**
 * Get Stroke Color
 *
 * @return UIColor defined for the stroke color
 */
-(nullable UIColor*)getStrokeColor;

/**
 * Remove Stroke Color That Was Previous Applied
 */
-(void)removeStrokeColor;

/**
 * Has Stroke Color
 *
 * @return BOOL indicating if stroke color applied
 */
-(BOOL)hasStrokeColor;

/**
 * Set Fill Color
 *
 * @param fillColor A UIColor object to define Fill Color
 */
-(void)setFillColor:(nonnull UIColor *)fillColor;
/**
 * Get Fill Color
 *
 * @return UIColor associated to the Fill Color
 */
-(nullable UIColor *)getFillColor;
/**
 * Remove Fill Color That Was Previously Applied
 */
-(void)removeFillColor;
/**
 * Has Fill Color
 *
 * @return BOOL indicating if fill color was applied
 */
-(BOOL)hasFillColor;

/**
 * Set Line Join
 *
 * @param joinType An int value to define Line Join
 */
-(void)setLineJoin:(int)joinType;
/**
 * Has Line Join
 *
 * @return BOOL indicating if Line Join was applied
 */
-(BOOL)hasLineJoin;
/**
 * Get Line Join
 *
 * @return int value defined for Line Join
 */
-(int)getLineJoin;

/**
 * Set Miter Limit
 *
 * @param meterLimit A float value to define Miter Limit
 */
-(void)setMiterLimit:(float)meterLimit;
/**
 * Has Miter Limit
 *
 * @return BOOL indicating if Miter Limit was applied
 */
-(BOOL)hasMiterLimit;
/**
 * Has Miter Limit
 *
 * @return float value defined for Miter Limit
 */
-(float)getMiterLimit;

/**
 * Set Stroke Dash Array
 *
 * @param strokeDashArray An NSArray to define Stroke Dash Array
 */
-(void)setStrokeDashArray:(nonnull NSArray *)strokeDashArray;
/**
 * Has Stroke Dash Array
 *
 * @return BOOL indicating if Stroke Dash Array was applied
 */
-(BOOL)hasStrokeDashArray;
/**
 * Get Stroke Dash Array
 *
 * @return NSArray defined for Stroke Dash Array
 */
-(nullable NSArray *)getStrokeDashArray;

/**
 * Set Opacity
 *
 * @param opacityFloat An NSArray to define Opacity
 */
-(void)setOpacity:(float)opacityFloat;
/**
 * Has Opacity
 *
 * @return BOOL indicting if opactiy was applied
 */
-(BOOL)hasOpacity;
/**
 * Get Opacity
 *
 * @return float value defined for Opacity
 */
-(float)getOpacity;

@end
