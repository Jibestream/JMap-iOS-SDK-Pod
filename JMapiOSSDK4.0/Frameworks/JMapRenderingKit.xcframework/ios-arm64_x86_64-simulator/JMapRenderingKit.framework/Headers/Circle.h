//
//  Circle.h
//  JMap
//
//  Created by Aaron Wong on 2016-08-03.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import "Shape.h"

/**
 *  The Circle shape model.
 */
@interface Circle : Shape

/**
 *  The x coordinate of the circle.
 */
@property (nonatomic, copy) NSNumber * x;
/**
 *  The y coordinate of the circle.
 */
@property (nonatomic, copy) NSNumber * y;
/**
 *  The radius of the circle.
 */
@property (nonatomic, copy) NSNumber * radius;

/**
 *  Init method for creating a circle shape object.
 *
 *  @param id The unique ID of the circle.
 *  @param name The name associated to the circle.
 *  @param elementName The element name parsed from the SVG.
 *  @param meta The meta data associated to the circle.
 *  @param style The JMapStyle associated to the circle.
 *  @param x The x coordinate of the circle.
 *  @param y The y coordinate of the circle.
 *  @param radius The radius of the circle.
 *  @param interactive Bool value whether the circle should be interactive.
 *
 *  @return An instance of the circle with the passed in parameters.
 */
- (instancetype) initWithId:(NSNumber *)id name:(NSString *)name elementClass:(NSString *)elementName meta:(NSDictionary *)meta style:(JMapStyle *)style x:(NSNumber *)x y:(NSNumber *)y radius:(NSNumber *)radius isInteractive:(BOOL)interactive;

/**
 *  The method to create the shape on the map.
 *
 *  @return The shape object on the map.
 */
- (Shape *)createShape;

@end
