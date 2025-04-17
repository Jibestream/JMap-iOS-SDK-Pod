//
//  Ellipse.h
//  JMap
//
//  Created by Aaron Wong on 2016-08-04.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import "Shape.h"

/**
 *  The Ellipse shape object.
 */
@interface Ellipse : Shape

/**
 *  The x coordinate of the ellipse.
 */
@property (nonatomic, copy) NSNumber * x;
/**
 *  The y coordinate of the circle.
 */
@property (nonatomic, copy) NSNumber * y;
/**
 *  The width of the ellipse.
 */
@property (nonatomic, copy) NSNumber * width;
/**
 *  The height of the ellipse.
 */
@property (nonatomic, copy) NSNumber * height;

/**
 *  Init method for creating a ellipse shape object.
 *
 *  @param id The unique ID of the ellipse.
 *  @param name The name associated to the ellipse.
 *  @param elementName The element name parsed from the SVG.
 *  @param meta The meta data associated to the ellipse.
 *  @param style The JMapStyle associated to the ellipse.
 *  @param x The x coordinate of the ellipse.
 *  @param y The y coordinate of the ellipse.
 *  @param width The width of the ellipse.
 *  @param height The height of the ellipse.
 *  @param interactive Bool value whether the ellipse should be interactive.
 *
 *  @return An instance of the ellipse with the passed in parameters.
 */
- (instancetype) initWithId:(NSNumber *)id name:(NSString *)name elementClass:(NSString *)elementName meta:(NSDictionary *)meta style:(JMapStyle *)style x:(NSNumber *)x y:(NSNumber *)y width:(NSNumber *)width height:(NSNumber *)height isInteractive:(BOOL)interactive;

/**
 *  The method to create the shape on the map.
 *
 *  @return The shape object on the map.
 */
- (Shape *)createShape;

@end
