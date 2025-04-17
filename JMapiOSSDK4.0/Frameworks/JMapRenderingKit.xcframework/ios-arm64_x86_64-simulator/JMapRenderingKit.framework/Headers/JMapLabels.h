//
//  JMapLabels.h
//  JMapRendering
//
//  Created by Aaron Wong on 2016-11-03.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JMapCoreKit/JMapCoreKit.h>
#import <UIKit/UIKit.h>
#import "JMapLabel.h"
#import "JMapCanvas.h"
#import <JMapCoreKit/UIFont+withColor.h>

/**
 *  The JMapLabels model.
 */
@interface JMapLabels : NSObject

/**
 *  Create Label For Unit
 *
 *  @param unitId Integer for the asociated unit of this label
 *  @param content optional UIImage for the image label
 *  @param frame CGRect frame of the label in the unit
 *  @param mapIds optional Array of map ids
 *  @param image optional image for the image label
 *  @param uri optional URI String for the web label
 *  @param font optional customized UIFont for the text label
 *  @param isUnitLabel Boolean value for if the label is for a unit
 *
 *  @return newly created JMapLabel object
 */
- (nonnull JMapLabel *)createLabelForUnitId:(NSInteger)unitId content:(nullable NSString *)content frame:(CGRect)frame mapIds:(nonnull NSArray <NSNumber*>*)mapIds image:(nullable UIImage *)image uri:(nullable NSString *)uri font:(nullable UIFont *)font isUnitLabel:(BOOL)isUnitLabel;

/**
 *  Create Label For Unit
 *
 *  @param unitId Integer for the asociated unit of this label
 *  @param content optional UIImage for the image label
 *  @param frame CGRect frame of the label in the unit
 *  @param mapIds optional Array of map ids
 *  @param image optional image for the image label
 *  @param uri optional URI String for the web label
 *  @param jmapFont optional customized JMap for the text label
 *  @param isUnitLabel Boolean value for if the label is for a unit
 *
 *  @return newly created JMapLabel object
 */
- (nonnull JMapLabel *)createLabelForUnitId:(NSInteger)unitId content:(nullable NSString *)content frame:(CGRect)frame mapIds:(nonnull NSArray <NSNumber*>*)mapIds image:(nullable UIImage *)image uri:(nullable NSString *)uri jmapFont:(nullable JMapFont *)jmapFont isUnitLabel:(BOOL)isUnitLabel;

/**
 *  Create Map Labels
 *
 *  @param mapLabels Array of JMapMapLabels to create
 *  @param mapId Integer MapId to place labels on
 *  @param canvas JMapCanvas
 */
- (void)createMapLabels:(nonnull NSArray <JMapMapLabel *>*)mapLabels forMapWithId:(nonnull NSNumber *)mapId onCanvas:(nonnull JMapCanvas *)canvas;

/**
 *  Create Map Labels with options
 *
 *  @param mapLabels Array of JMapMapLabels to create
 *  @param mapId Integer MapId to place labels on
 *  @param canvas JMapCanvas
 *  @param options The options associated to the map labels. (scaleWithMap, rotateWithMap, flipWithRotation, scale)
 */
- (void)createMapLabels:(nonnull NSArray<JMapMapLabel *> *)mapLabels forMapWithId:(nonnull NSNumber *)mapId onCanvas:(nonnull JMapCanvas *)canvas withOptions:(nullable NSDictionary *)options;

/**
 *  Remove Label With Unit ID : remove label associated with unit ID
 *
 *  @param unitId Integer of the unit
 */
- (void)removeLabelWithUnitId:(NSInteger)unitId;
/**
 *  Remove Map Label With ID : remove label associated with the ID
 *
 *  @param labelId Integer unique ID of the map label
 */
- (void)removeMapLabelWithId:(NSInteger)labelId;
/**
 *  Get Label By ID : get label associated with the unit ID
 *
 *  @param unitId Integer of the unit
 */
- (nullable JMapLabel *)getLabelByUnitId:(NSInteger)unitId;
/**
 *  Get Map Label By ID : get label associated with the ID
 *
 *  @param labelId Integer unique ID of the map label
 */
- (nullable JMapLabel *)getMapLabelById:(NSInteger)labelId;
/**
 *  Get All Unit Labels
 *  @return dicitonary containing key value pairing of unit labels
 */
- (nonnull NSMutableDictionary <NSString *, JMapLabel *>*)getAllUnitLabels;
/**
 *  Get All Unit Labels For Map
 *
 *  @param map JMapMap object to get unit labels from
 *  @return array of unit labels
 */
- (nonnull NSArray <JMapLabel *>*)getAllUnitLabelsForMap:(nonnull JMapMap *)map;
/**
 *  Get All Map Labels
 *  @return dictionary containing key value pairing of map labels
 */
- (nonnull NSMutableDictionary <NSString *, JMapLabel *>*)getAllMapLabels;
/**
 *  Get All Map Labels For Map
 *
 *  @param map JMapMap object to get map labels from
 *  @return array of map labels
 */
- (nonnull NSArray <JMapLabel *>*)getAllMapLabelsForMap:(nonnull JMapMap *)map;
/**
 *  Set All Labels Font
 *
 *  @param font the text font passed in for all labels
 */
- (void)setAllLabelsFont:(nonnull UIFont *)font;
/**
 *  Set All Unit Labels Font
 *
 *  @param font the text font passed in for unit labels
 */
- (void)setUnitLabelsFont:(nonnull UIFont *)font;
/**
 *  Set All Map Labels Font
 *
 *  @param font the text font passed in for map labels
 */
- (void)setMapLabelsFont:(nonnull UIFont *)font;
/**
 *  Set All Labels with JMapFont
 *
 *  @param jmapFont the text font passed in for all labels
 */
- (void)setAllLabelsJMapFont:(nonnull JMapFont *)jmapFont;

/**
 *  Set All Unit Labels with JMapFont
 *
 *  @param jmapFont the text font passed in for unit labels
 */
- (void)setUnitLabelsJMapFont:(nonnull JMapFont *)jmapFont;
/**
 *  Set All Map Labels with JMapFont
 *
 *  @param jmapFont the text font passed in for map labels
 */
- (void)setMapLabelsJMapFont:(nonnull JMapFont *)jmapFont;

@end
