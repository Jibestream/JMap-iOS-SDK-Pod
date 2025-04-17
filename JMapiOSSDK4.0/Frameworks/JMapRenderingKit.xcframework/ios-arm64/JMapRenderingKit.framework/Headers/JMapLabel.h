//
//  JMapLabel.h
//  JMapRendering
//
//  Created by Aaron Wong on 2016-11-04.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "JMapItemView.h"
#import <JMapCoreKit/UIFont+withColor.h>
#import "JMapFont.h"
#import <WebKit/WebKit.h>

#define hideAfterSize 17.0

/**
 *  The JMapLabel model.
 */
@interface JMapLabel : JMapItemView

/**
 *  ID Unigue Integer identifier of the label
 */
@property (nonatomic, strong, readonly, nonnull)  NSNumber *id;

/**
 *  Array of map ids
 */
@property (nonatomic, strong, readonly, nonnull)  NSArray <NSNumber *>* mapIds;

/**
 *  Text string for the map label
 */
@property (nonatomic, strong, readonly, nullable) NSString *text;

/**
 *  Image of the map label
 */
@property (nonatomic, strong, readonly, nullable) UIImage *image;

/**
 *  URI link for map labels image
 */
@property (nonatomic, strong, readonly, nullable) NSString *uri;

/**
 *  SVG for map label
 */
@property (nonatomic, strong, readonly, nullable) NSString *svg;

/**
 *  Font of the text map label
 */
@property (nonatomic, strong, readonly, nullable) UIFont *font;

/**
 *  JMapFont of the text map label
 */
@property (nonatomic, strong, readonly, nullable) JMapFont *jmapFont;

/**
 *  Rotaion value
 */
@property (nonatomic, strong, readonly, nullable) NSNumber * rotation;

/**
 *  Map Label text label
 */
@property (nonatomic, strong, readonly, nullable) UILabel *textLabel;

/**
 *  Map Label web label for svg and other web images
 */
@property (nonatomic, strong, readonly, nullable) WKWebView *webLabel;

/**
 *  Map Label image label for any image to be used as labels
 */
@property (nonatomic, strong, readonly, nullable) UIImageView *imageLabel;

/**
 *  Rotated transform value
 */
@property (nonatomic, assign, readonly) CGAffineTransform rotatedTransform;

/**
 *  Boolean value for if a map label is rotated
 */
@property (nonatomic, assign, readonly) BOOL isRotated;

/**
 *  Boolean value to determine if ellipses should be shown or not on a map label
 */
@property (nonatomic, assign, readonly) BOOL showEllipses;

/**
 *  Boolean value to determine if map label is a unit label
 */
@property (nonatomic, assign, readonly) BOOL isUnitLabel;

/**
 *  Init With Frame: Constructor method JMapLabel
 *
 *  @param frame CGRect frame size of the label
 *  @param id Integer unique identifier
 *  @param mapIds Array of map ids
 *  @param text optional String for the text label
 *  @param image optional UIImage for the image label
 *  @param uri optional String for the web label
 *  @param svg optional String for the web label
 *  @param font optional UIFont for the text label
 *  @param rotation optional Integer for the label
 *  @param isUnitLabel Boolean to determine if the lebel is for a unit
 *
 *  @return new JMapLabel object
 */
- (nonnull instancetype)initWithFrame:(CGRect)frame id:(nonnull NSNumber *)id mapIds:(nonnull NSArray <NSNumber *>*)mapIds text:(nullable NSString *)text image:(nullable UIImage *)image uri:(nullable NSString *)uri svg:(nullable NSString *)svg font:(nullable UIFont *)font rotation:(nullable NSNumber *)rotation isUnitLabel:(BOOL)isUnitLabel;

/**
 *  Init With Frame: Constructor method JMapLabel
 *
 *  @param frame CGRect frame size of the label
 *  @param id Integer unique identifier
 *  @param mapIds Array of map ids
 *  @param text optional String for the text label
 *  @param image optional UIImage for the image label
 *  @param uri optional String for the web label
 *  @param svg optional String for the web label
 *  @param jmapFont optional JMapFont for the text label
 *  @param rotation optional Integer for the label
 *  @param isUnitLabel Boolean to determine if the lebel is for a unit
 *
 *  @return new JMapLabel object
 */
- (nonnull instancetype)initWithFrame:(CGRect)frame id:(nonnull NSNumber *)id mapIds:(nonnull NSArray <NSNumber *>*)mapIds text:(nullable NSString *)text image:(nullable UIImage *)image uri:(nullable NSString *)uri svg:(nullable NSString *)svg jmapFont:(nullable JMapFont *)jmapFont rotation:(nullable NSNumber *)rotation isUnitLabel:(BOOL)isUnitLabel;

/**
 *  Init With Map Label: Constructor method JMapLabel
 *
 *  @param mapLabel JMapLabel object
 *
 *  @return new JMapLabel object
 */
- (nonnull instancetype)initWithMapLabel:(nonnull JMapLabel *)mapLabel;

/**
 *  Update Values: Update parameters method
 *
 *  @param text optional String for the text label
 *  @param image optional UIImage for the image label
 *  @param uri optional String for the web label
 *  @param svg optional String for the web label
 *  @param font optional UIFont for the text label
 *  @param rotation optional Integer for the label
 */
- (void)updateValuesWithText:(nullable NSString *)text image:(nullable UIImage *)image uri:(nullable NSString *)uri svg:(nullable NSString *)svg font:(nullable UIFont *)font rotation:(nullable NSNumber *)rotation;

/**
 *  Update Values: Update parameters method
 *
 *  @param text optional String for the text label
 *  @param image optional UIImage for the image label
 *  @param uri optional String for the web label
 *  @param svg optional String for the web label
 *  @param jmapFont optional JMapFont for the text label
 *  @param rotation optional Integer for the label
 */
- (void)updateValuesWithText:(nullable NSString *)text image:(nullable UIImage *)image uri:(nullable NSString *)uri svg:(nullable NSString *)svg jmapFont:(nullable JMapFont *)jmapFont rotation:(nullable NSNumber *)rotation;

/**
 *  Content Scale Factor Changed : Used to change the scale and zoom values
 *  @param newScale Integer of scale
 *  @param maxZoom float of zoom scale
 */
- (void)contentScaleFactorChanged:(nonnull NSNumber *)newScale maxZoom:(float)maxZoom;

/**
 *  Load Text Label : Used to render the text label
 */
- (void)loadTextLabel;

/**
 *  Load Text Label : Used to render the web label
 *  @param completion Bool value for if label has been loaded successfully
 */
- (void)loadWebLabel:(nonnull void(^)(BOOL success))completion;

/**
 *  Load Image Label : Used to render the image label
 */
- (void)loadImageLabel;

/**
 *  Remove Label : Used to remove the rendered label
 */
- (void)remove;

@end
