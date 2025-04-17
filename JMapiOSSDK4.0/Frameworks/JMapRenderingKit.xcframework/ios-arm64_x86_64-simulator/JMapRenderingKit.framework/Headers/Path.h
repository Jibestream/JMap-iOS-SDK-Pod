//
//  Path.h
//  JMapRendering
//
//  Created by Louie Yuen on 2016-10-24.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import "Shape.h"
#import "JMapKPointsAndPathsParser.h"

@class JMapKPointsAndPathsParser;

/**
 *  The Path shape model.
 */
@interface Path : Shape

/**
 *  The path to point parser.
 */
@property (nonatomic, nullable, readonly) JMapKPointsAndPathsParser *pathParser;

/**
 *  The Path data string.
 */
@property (nonatomic, strong, nullable) NSString *pathData;

/**
 *  Initializes Path
 *  @param id the ID of the path
 *  @param name the name of the path
 *  @param elementName the element name associated with the path
 *  @param meta the meta data passed into the path
 *  @param style the style associated with the path
 *  @param points the array of points assoicated with the path
 *  @param interactive the interactivity of the path
 *
 *  @return an instance of the path
 */
- (nonnull instancetype) initWithId:(nullable NSNumber *)id name:(nullable NSString *)name elementClass:(nullable NSString *)elementName meta:(nullable NSDictionary *)meta style:(nullable JMapStyle *)style points:(nullable NSString *)points isInteractive:(BOOL)interactive;

/**
 *  Method to create the path shape
 *  @return a shape object
 */
-(nonnull Shape *)createShape;

/**
 *  Method to get the path line segments
 *
 *  @return An array of line segments that forms the path
 */
- (nonnull NSArray <NSArray <NSValue *>*>*)getSegmentsFromShape;

@end
