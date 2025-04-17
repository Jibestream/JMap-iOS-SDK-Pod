//
//  JMapControllerKitUtils.h
//  JMapController
//
//  Created by Louie Yuen on 2017-03-21.
//  Copyright © 2017 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <JMapRenderingKit/JMapRenderingKit.h>

@class Polygon;
@class JMapStyle;

/**
 *  The JMapControllerKitUtils Interface.
 */
@interface JMapControllerKitUtils : NSObject

#pragma mark - Helpers

/**
 *  Get the bounds from an array of points.
 *
 *  @param points The array of points on the map.
 *  @return The bounding box CGRect of the points.
 */
+ (CGRect)getBoundsFromPoints:(nonnull NSArray <NSValue *>*)points;

/**
 *  Generates a polygon with an array of points.
 *
 *  @param points The polygon points.
 *  @return A polygon created with the given points.
 */
+ (nullable Polygon *)getPolygonFromPoints:(nonnull NSArray <NSValue *>*)points;

/**
 *  Gets the centroid of a polygon.
 *
 *  @param polygon The polygon on the map.
 *  @return A CGPoint that is at the center of the polygon.
 */
+ (CGPoint)getCentroidOfPolygon:(nonnull Polygon *)polygon;

@end
