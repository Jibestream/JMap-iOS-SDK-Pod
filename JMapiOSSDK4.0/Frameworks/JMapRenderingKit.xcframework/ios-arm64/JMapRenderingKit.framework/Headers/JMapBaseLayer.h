//
//  JMapBaseLayer.h
//  JMapRendering
//
//  Created by Aaron Wong on 2016-10-28.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MapLayer.h"

/**
 *  The JMapBaseLayer model.
 */
@interface JMapBaseLayer : UIView

/**
 *  JMapRenderingKitDelegate for rendering engine communication to the delegate class
 */
@property (nonatomic, readonly, nonnull) NSNumber *mapId;

/**
 *  Init : Constructor method
 *  @return JMapBaseLayer object
 */
- (nonnull instancetype)init;

/**
 *  Init With Frame And Map ID : Constructor method
 *  @param frame CGRect frame size of the map
 *  @param mapId NSNumber unique identifier of the map
 *  @return JMapBaseLayer object
 */
- (nonnull instancetype)initWithFrame:(CGRect)frame andMapId:(NSNumber * _Nonnull)mapId;

/**
 *  Generate New Map Layer With Name : method for creating new Map Layers on the map
 *  @param name String required as identifier for the map layer
 *  @return MapLayer newly created object
 */
- (nullable MapLayer *)generateNewMapLayerWithName:(nonnull NSString *)name;

/**
 *  Add New MapLayer : method for adding a new map layer to the map
 *  @param newMapLayer MapLayer
 */
- (void)addNewMapLayer:(nonnull MapLayer *)newMapLayer;

/**
 *  Apply Array Of Shapes : method for adding an array of shapes to the map
 *  @param shapes NSArray
 *  @param completion returns error if occured
 */
- (void)applyArrayOfShapes:(nonnull NSArray*)shapes completionHandler:(nullable void (^)(NSError * _Nullable error))completion;

/**
 *  Get All Layers
 *  @return an array of MapLayers
 */
- (nonnull NSArray <MapLayer *>*)getAllLayers;

/**
 *  Get Layer With Name
 *  @param layerName String identifier of desired layer
 *  @return MapLayer if layer exists
 */
- (nullable MapLayer *)getLayerWithName:(nonnull NSString *)layerName;

@end
