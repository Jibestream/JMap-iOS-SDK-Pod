//
//  Shape.h
//  JMap
//
//  Created by Aaron Wong on 2016-08-03.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "Shape.h"
#import "JMapStyle.h"
#import "JMapIconStyle.h"
#import "MapLayer.h"

@class JMapIconStyle;
@class JMapStyle;
@class MapLayer;

/**
 *  The Shape base class
 */
@interface Shape : CAShapeLayer

/**
 *  Unique indetifier of the Shape
 */
@property (nonatomic, strong, nullable) NSNumber * id;

/**
 *  Meta Data of the Shape
 */
@property (nonatomic, strong, nullable) NSDictionary * meta;

/**
 *  Stroke Width of the Shape
 */
@property (nonatomic, strong, nullable) NSNumber * strokeWidth;

/**
 *  Stroke Opacity of the Shape
 */
@property (nonatomic, strong, nullable) NSNumber * strokeOpacity;

/**
 *  Init With Frame And Map ID : Constructor method
 */
@property (nonatomic, strong, nullable) NSString *className;

/**
 *  Init With Frame And Map ID : Constructor method
 */
@property (nonatomic, strong, nullable) UIColor * fill;

/**
 *  Init With Frame And Map ID : Constructor method
 */
@property (nonatomic, strong, nullable) JMapStyle * initialStyle;

/**
 *  Init With Frame And Map ID : Constructor method
 */
@property (nonatomic, weak, nullable) MapLayer * parentLayer;

/**
 *  Init With Frame And Map ID : Constructor method
 */
@property (nonatomic, assign) BOOL isInteractive;

/**
 *  Init With Frame And Map ID : Constructor method
 */
@property (nonatomic) CGRect pathFrame;

/**
 *  Init With Frame And Map ID : Constructor method
 */
@property (nonatomic, assign) CGAffineTransform transformationMatrix;

/**
 *  Init With Frame And Map ID : Constructor method
 */
@property (nonatomic, nullable) NSString *transformShapeStr;

/**
 *  Init With ID : Constructor method for Shape
 *
 *  @param id optional integer identifier of the shape
 *  @param name optional String identifier for the shape
 *  @param className optional element class of the shape
 *  @param meta optional Dictionary of all meta data associated to the shape
 *  @param style optional JMapStyle of the shape
 *  @param interactive Boolean value to identify if shape is interactive
 *
 *  @return newly created Shape object
 */
- (nullable instancetype) initWithId:(nullable NSNumber *)id name:(nullable NSString *)name elementClass:(nullable NSString *)className meta:(nullable NSDictionary *)meta style:(nullable JMapStyle *)style isInteractive:(BOOL)interactive;

/**
 *  Set Meta With Dictionary : Method to apply meta data to shape
 *
 *  @param dictionary Dictionary object with all meta data to apply to the shape
 */
- (void)setMetaWithDictionary:(nonnull NSDictionary *)dictionary;

/**
 *  Create Arc Path : Method to apply meta data to shape
 *
 *  @param point CGPoint as center point
 *  @param radius Integer value of the radius
 *  @param startAngle Integer value of the startAngle
 *  @param endAngle Integer value of the endAngle
 *  @param clockWise Boolean to either draw the arc clockwise or counter clockwise
 *
 *  @return UIBezierPath
 */
- (nullable UIBezierPath *)createArcPathWithPoint:(CGPoint)point radius:(NSInteger)radius startAngle:(NSInteger)startAngle endAngle:(NSInteger)endAngle clockWise:(BOOL)clockWise;

/**
 *  Create Multi Shape With Path : Method to create multiple shapes
 *
 *  @param path UIBezierPath
 *  @param holePaths an array of all path that are within the drawn shape
 *
 *  @return Shape
 */
- (nullable Shape *)createMultiShapeWithPath:(nonnull UIBezierPath *)path andHolePaths:(nullable NSArray <UIBezierPath *>*)holePaths;

/**
 *  Create Shape With Path : Method to create shape object with path
 *
 *  @param path UIBezierPath to render into a shape
 *
 *  @return Shape
 */
- (nullable Shape *)createShapeWithPath:(nonnull UIBezierPath *)path;

/**
 *  Parse Path With Points : Method to create UIBezierPath with points
 *
 *  @param points array of points to parse
 *
 *  @return UIBezierPath
 */
- (nullable UIBezierPath *)parsePathWithPoints:(nonnull NSArray <NSArray <NSString *>*> *)points;

/**
 *  SVGStyle shapes SVG style
 */
@property (nonatomic, strong, readonly, nullable) JMapStyle *SVGstyle;

/**
 *  bezier path of the shape
 */
@property (nonatomic, strong, readonly, nullable) UIBezierPath *bezierPath;

/**
 *  Reset Shape Style : Returns all styles of the shape back to default
 */
-(void)resetShapeStyle;

/**
 *  Create SVG Style From Style Sheet : Method to render the shape style from a style sheet
 *
 *  @param styleSheet Dictionary object of a style parameters
 */
-(void)createSVGStyleFrom:(nonnull NSDictionary *)styleSheet;

/**
 *  Make Style From Style Sheet : Method to create a JMapStyle object from a style sheet
 *
 *  @param styleSheet dictionary of styles to apply to create a JMapStyle
 *  @param isIcon Boolean value to determine if style is for icon
 *
 *  @return JMapStyle object parsed from the styleSheet
 */
-(nonnull JMapStyle *)makeStyleFrom:(nonnull NSDictionary *)styleSheet isIcon:(BOOL)isIcon;

/**
 *  Check to see if shape has transform matrix association
 *
 *  @return Boolean to determine whether the shape has a transform matrix
 */
-(BOOL)hasTransformationMatrix;

/**
 *  Set the transform matrix for the shape
 *
 *  @param transformationMatrix the transform matrix from the SVG
 */
-(void)setTransformationMatrix:(CGAffineTransform)transformationMatrix;

/**
 *  Parse Path With Points : Method to create UIBezierPath with points
 *
 *  @param thisPathRef The path reference of the shape
 */
-(void)setBezPath:(nonnull CGPathRef)thisPathRef;

/**
 *  Parse Path With Points : Method to create UIBezierPath with points
 *
 *  @param thisSVGStyle The JMapStyle object to set on the shape
 */
-(void)setSVGStyle:(nonnull JMapStyle *)thisSVGStyle;

/**
 *  Sets the meta data from the SVG to the shape
 *
 *  @param data An NSDictionary containing the meta data of the shape
 *
 *  @param key The key string association to the data
 */
- (void)updateMetaWithData:(nonnull NSDictionary *)data forKey:(nonnull NSString *)key;

#pragma mark - Path Generalization

/**
 *  Get the segments associated to the shape
 *
 *  @return An NSArray of NSArray of NSValues
 */
- (nonnull NSArray <NSArray <NSValue *>*>*)getSegmentsFromShape;

/**
 *  Check to see if shape is within given bounds
 *
 *  @param bounds The bound to check if shape is contained in
 *
 *  @return Boolean for indicating whether the shape is within the bounds
 */
- (BOOL)isWithinBounds:(CGRect)bounds;

@end
