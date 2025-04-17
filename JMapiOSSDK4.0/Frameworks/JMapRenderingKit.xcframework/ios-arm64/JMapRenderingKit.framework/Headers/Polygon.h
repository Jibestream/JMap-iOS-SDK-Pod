//
//  Polygon.h
//  JMap
//
//  Created by Aaron Wong on 2016-08-04.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import "Shape.h"

/**
 *  The Polygon shape model.
 */
@interface Polygon : Shape

/**
 *  Polygon points
 */
@property (nonatomic, copy, nonnull) NSArray <NSValue *>* coordinates;

/**
 *  Initializes Polygon
 *  @param id the ID of the polygon
 *  @param name the name of the polygon
 *  @param elementName the element name associated with the polygon
 *  @param meta the meta data passed into the polygon
 *  @param style the style associated with the polygon
 *  @param points the array of points assoicated with the polygon
 *  @param interactive the interactivity of the polygon
 *
 *  @return an instance of the polygon
 */
- (nonnull instancetype) initWithId:(nullable NSNumber *)id name:(nullable NSString *)name elementClass:(nullable NSString *)elementName meta:(nullable NSDictionary *)meta style:(nullable JMapStyle *)style points:(nullable NSArray *)points isInteractive:(BOOL)interactive;

/**
 *  Method to create the polygon shape
 *  @return a shape object
 */
- (nonnull Shape *)createShape;

/**
 *  Method to get the polygon line segments
 *
 *  @return An array of line segments that forms the polgyon
 */
- (nonnull NSArray <NSArray <NSValue *>*>*)getSegmentsFromShape;

@end
