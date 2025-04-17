//
//  Polyline.h
//  JMapRendering
//
//  Created by Louie Yuen on 2016-10-26.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import "Shape.h"

/**
 *  The Polyline shape model.
 */
@interface Polyline : Shape
/**
 *  Initializes Polyline
 *  @param id the ID of the polyline
 *  @param name the name of the polyline
 *  @param elementName the element name associated with the polyline
 *  @param meta the meta data passed into the polyline
 *  @param style the style associated with the polyline
 *  @param points the array of points assoicated with the polyline
 *  @param interactive the interactivity of the polyline
 *
 *  @return an instance of the polyline
 */
- (nonnull instancetype) initWithId:(nullable NSNumber *)id name:(nullable NSString *)name elementClass:(nullable NSString *)elementName meta:(nullable NSDictionary *)meta style:(nullable JMapStyle *)style points:(nullable NSArray *)points isInteractive:(BOOL)interactive;

/**
 *  Method to create the polyline shape
 *  @return a shape object
 */
- (nonnull Shape *)createShape;

@end
