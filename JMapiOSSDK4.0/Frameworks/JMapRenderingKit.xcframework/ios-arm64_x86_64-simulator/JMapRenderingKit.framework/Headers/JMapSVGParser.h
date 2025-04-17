//
//  JMapSVGParser.h
//  JMapRendering
//
//  Created by Louie Yuen on 2016-10-21.
//  Copyright © 2016 Jibestream. All rights reserved.
//

@class JMapAmenityStyle;
@class JMapCanvas;
@class JMapIconStyle;
@class JMapIconView;

/**
 *  The JMapSVGParser class
 */
@interface JMapSVGParser : NSObject <NSXMLParserDelegate>

/**
 *  Dictionary of svgs.
 */
@property (nonatomic, retain, nullable) NSMutableDictionary *svgs;
/**
 *  Array of elements.
 */
@property (nonatomic, retain, nullable) NSMutableArray *elements;
/**
 *  Dictionary of use tags
 */
@property (nonatomic, retain, nullable) NSMutableDictionary *uses;
/**
 *  Array of transformations.
 */
@property (nonatomic, retain, nullable) NSMutableArray *transformationArray;
/**
 *  Array of styles
 */
@property (nonatomic, retain, nullable) NSMutableDictionary *styles;
/**
 *  Dictionary of symbol tags
 */
@property (nonatomic, retain, nullable) NSMutableDictionary *symbols;
/**
 *  Dictionary of g tags
 */
@property (nonatomic, retain, nullable) NSMutableDictionary *gs;
/**
 *  The transform matrix for orientating shapes on the map
 */
@property (nonatomic) CGAffineTransform transformationMatrix;
/**
 *  The current element parsed
 */
@property (nonatomic, retain, nullable) NSMutableString *currentElementValue;
/**
 *  Array of shapes associated to the parsed object
 */
@property (nonatomic, retain, nullable) NSMutableArray *arrayOfShapes;
/**
 *  The default styles associated to the parsed object
 */
@property (nonatomic, strong, nullable) JMapIconStyle *defaultStyles;
/**
 *  Dictionary of all the styles associated to the parsed object
 */
@property (nonatomic, strong, readonly, nullable) NSDictionary *allStyles;
/**
 *  The JMapSVGParser delegate
 */
@property (nonatomic, weak, nullable) id delegate;
/**
 *  Dictionary of custom styles passed for parsing the object
 */
@property (nonatomic, strong, nullable) NSDictionary *customStyles;

/**
 *  Object's viewbox width
 */
@property (nonatomic) float width;
/**
 *  Object's viewbox height
 */
@property (nonatomic) float height;

/**
 *  Method to parse the map with SVG file input
 *  @param svg The SVG string passed to the parser
 *  @param completion The completion handler to indicate parsing complete, returns bounds of the map, shapes on the map, stylesheet or error if parsing fails
 */
-(void)parseMapWithSVG:(NSString * _Nonnull)svg completionHandler:(nonnull void (^)(CGRect rect, NSArray * _Nullable shapes, NSDictionary * _Nullable styles, NSError * _Nullable error))completion;

/**
 *  Method to parse amenity and path type icons
 *  @param svg The SVG string passed to the parser
 *  @param type The type indication of whether it is an amenity or a path type icon
 */
-(nullable JMapIconView *)parseIconWithSVG:(nonnull NSString *)svg type:(nonnull NSString *)type;

@end
