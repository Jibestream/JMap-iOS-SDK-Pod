//
//  JMapRenderingKitUtils.h
//  JMapRendering
//
//  Created by Aaron Wong on 2016-11-15.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define DEGREES_TO_RADIANS(x) (M_PI * (x) / 180.0)

/**
 *  The JMapRenderingKitUtils class.
 */
@interface JMapRenderingKitUtils : NSObject

#pragma mark - Stylings helper methods
/**
 *  Color With Hex String
 *  @discussion Retrieve UIColor object with hex string
 *
 *  @params stringToConvert NSString color string
 *  @return UIColor object from Hexidecimal color string
 */
+ (nonnull UIColor *)colorWithHexString:(nonnull NSString *)stringToConvert;

#pragma mark Transforms
/**
 *  Apply Angle Transfrom From View
 *  @discussion Apply angle transform for provided view with center point and target view
 *
 *  @params thisView view passed in
 *  @params pt CGPoint center of view
 *
 *  @return CGAffineTransform object
 */
+ (CGAffineTransform)applyAngleTransFromUIView:(nonnull UIView *)thisView withCenter:(CGPoint)pt;

/**
 *  Bounds To Points
 *  @discussion Turn bounds to array of points
 *
 *  @params bounds a CGRect of the bounds to convert
 *
 *  @return An array of CGPoints
 */
+ (nonnull NSArray<NSValue *>*)boundsToPoints:(CGRect)bounds;

/**
 *  Point in polygon
 *  @discussion Check to for if point is within a polygon
 *
 *  @params point CGPoint value of the point to check
 *  @params polygon NSArray of polygon CGPoints
 *
 *  @return BOOL true if point is within the polygon, false if it is not
 */
+ (BOOL)point:(CGPoint)point inPolygon:(nonnull NSArray <NSValue *>*)polygon;

/**
 *  Get Bounding Box From Points
 *  @discussion get bounding box from array of points provided
 *
 *  @params points An array of CGPoints
 *
 *  @return CGRect constructed by points provided
 */
+ (CGRect)getBoundingBoxFromPoints:(nonnull NSArray <NSValue *>*)points;

@end
