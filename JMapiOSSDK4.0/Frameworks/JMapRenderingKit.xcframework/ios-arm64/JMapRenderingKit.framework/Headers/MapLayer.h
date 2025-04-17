//
//  MapLayer.h
//  JMapRendering
//
//  Created by Aaron Wong on 2016-08-30.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <UIKit/UIKit.h>

@class JMapBaseLayer;

/**
 *  The MapLayer base UIView
 */
@interface MapLayer : UIView

/**
 *  Optional dictionary key value pairs for the map layer
 */
@property (nullable, nonatomic, strong) NSDictionary * options;
/**
 *  The ID of the map layer
 */
@property (nullable, nonatomic, strong) NSNumber * id;
/**
 *  The name of the map layer
 */
@property (nullable, nonatomic, strong) NSString * name;
/**
 *  The sequence of the map layer
 */
@property (nullable, nonatomic, strong) NSDictionary * sequence;
/**
 *  The sub maps associated to the map layer
 */
@property (nullable, nonatomic, strong) NSMutableArray * subMaps;
/**
 *  The map layer's interactivity
 */
@property (nonatomic, assign) BOOL interactive;
/**
 *  The parent reference of the map layer
 */
@property (nullable, nonatomic, weak) JMapBaseLayer * parentMap;

/**
 *  Init With ID : Constructor method MapLayer
 *
 *  @param layerId Integer unique identifier of the layer
 *  @param options NSDictionary options for passing into layer creation
 *  @param name of the layer
 *  @param sequence NSDictionary sequence to define the layer
 *
 *  @return newly created MapLayer object
 */
- (nonnull instancetype)initWithId:(nullable NSNumber *)layerId options:(nullable NSDictionary *)options name:(nullable NSString *)name sequence:(nullable NSDictionary *)sequence;

/**
 *  Add Shape Layer : used to add a shape layer to this map layer
 *
 *  @param shapeLayer shape to add to this layer
 */
- (void)addShapeLayer:(nonnull CALayer *)shapeLayer;

- (BOOL)isLayerWithName:(nonnull NSString *)layerName;

@end
