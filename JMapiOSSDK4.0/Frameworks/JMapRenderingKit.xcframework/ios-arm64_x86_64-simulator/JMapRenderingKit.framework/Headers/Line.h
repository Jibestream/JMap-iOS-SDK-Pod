//
//  Line.h
//  JMap
//
//  Created by Aaron Wong on 2016-08-04.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import "Shape.h"

/**
 *  The Line shape model.
 */
@interface Line : Shape
/**
 *  The array containing an array of strings represented as points
 */
@property (nonatomic, copy, nonnull) NSArray <NSArray <NSString *>*>* points;
/**
 *  Initializes Line
 *  @param id the ID of the line
 *  @param name the name of the line
 *  @param elementName the element name associated with the line
 *  @param meta the meta data passed into the line
 *  @param style the style associated with the line
 *  @param points the array of points assoicated with the line
 *  @param interactive the interactivity of the line
 *
 *  @return an instance of the line
 */
- (nonnull instancetype) initWithId:(nullable NSNumber *)id name:(nullable NSString *)name elementClass:(nullable NSString *)elementName meta:(nullable NSDictionary *)meta style:(nullable JMapStyle *)style points:(nullable NSArray *)points isInteractive:(BOOL)interactive;
/**
 *  Method to create the line shape
 *  @return a line object
 */
- (nonnull Shape *)createShape;
/**
 *  Get segments from the shape
 *  @return an array containing an array of NSValue objects as segments
 */
- (nonnull NSArray <NSArray <NSValue *>*>*)getSegmentsFromShape;

@end
