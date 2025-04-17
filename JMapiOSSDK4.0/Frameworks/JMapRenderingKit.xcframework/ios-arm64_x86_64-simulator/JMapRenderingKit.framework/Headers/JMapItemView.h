//
//  JMapItemView.h
//  JMapRendering
//
//  Created by Louie Yuen on 2016-11-07.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class JMapMap;

/**
 *  The JMapItemView model.
 */
@interface JMapItemView : UIView
/**
 *  The name of the item view
 */
@property (nonatomic, nullable) NSString *name;
/**
 *  The map associated with the item view
 */
@property (nonatomic, nullable) JMapMap *map;
/**
 *  The point in (x,y) on the map of the item view
 */
@property (nonatomic) CGPoint point;
/**
 *  Set whether the item view should rotate with the map
 */
@property (nonatomic, assign) BOOL rotateWithMap;
/**
 *  Set whether the item view should scale with the map
 */
@property (nonatomic, assign) BOOL scaleWithMap;
/**
 *  Set whether the item view should always be heads up with the map
 */
@property (nonatomic, assign) BOOL headsUp;
/**
 *  Set the scale of the item
 */
@property (nonatomic, nullable) NSNumber* scale;
/**
 *  Default original transform
 */
@property (nonatomic, assign) CGAffineTransform originalTransform;

@end
