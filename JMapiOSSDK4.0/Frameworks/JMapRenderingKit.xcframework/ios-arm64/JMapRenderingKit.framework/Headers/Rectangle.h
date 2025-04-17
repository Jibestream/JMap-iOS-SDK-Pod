//
//  Rectangle.h
//  JMapRendering
//
//  Created by Louie Yuen on 2016-10-26.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import "Shape.h"

/**
 *  The Rectangle shape model.
 */
@interface Rectangle : Shape

/**
 *  The x coordinate of the rectangle.
 */
@property (nonatomic, nonnull, copy) NSNumber * x;
/**
 *  The y coordinate of the rectangle.
 */
@property (nonatomic, nonnull, copy) NSNumber * y;
/**
 *  The width of the rectangle.
 */
@property (nonatomic, nonnull, copy) NSNumber * width;
/**
 *  The height of the rectangle.
 */
@property (nonatomic, nonnull, copy) NSNumber * height;

/**
 *  Initializes Rectangle
 *  @param id the ID of the rectangle
 *  @param name the name of the rectangle
 *  @param elementName the element name associated with the rectangle
 *  @param meta the meta data passed into the rectangle
 *  @param style the style associated with the rectangle
 *  @param x the x coordinate of the rectangle
 *  @param y the x coordinate of the rectangle
 *  @param width the width of the rectangle
 *  @param height the height of the rectangle
 *  @param interactive the interactivity of the rectangle
 *
 *  @return an instance of the rectangle
 */
- (nullable instancetype) initWithId:(nullable NSNumber *)id name:(nullable NSString *)name elementClass:(nullable NSString *)elementName meta:(nullable NSDictionary *)meta style:(nullable JMapStyle *)style x:(nullable NSNumber *)x y:(nullable NSNumber *)y width:(nullable NSNumber *)width height:(nullable NSNumber *)height isInteractive:(BOOL)interactive;

/**
 *  Method to create the rectangle shape
 *  @return a shape object
 */
- (nonnull Shape *)createShape;

/**
 *  Method to get the path line segments
 *
 *  @return An array of line segments that forms the path
 */
- (nonnull NSArray <NSArray <NSValue *>*>*)getSegmentsFromShape;

@end
