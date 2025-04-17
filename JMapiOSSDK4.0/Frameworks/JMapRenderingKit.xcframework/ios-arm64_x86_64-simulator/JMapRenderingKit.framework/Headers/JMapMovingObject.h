//
//  JMapMovingObject.h
//  JMapRendering
//
//  Created by Louie Yuen on 2017-01-19.
//  Copyright © 2017 Jibestream. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "JMapItemView.h"

/**
 *  The JMapMovingObject model.
 */
@interface JMapMovingObject : JMapItemView

/**
 *  The unique ID of the moving object
 */
@property (nonatomic) NSInteger id;
/**
 *  The map ID associated with the moving object
 */
@property (nonatomic) NSInteger mapId;
/**
 *  The image of the moving object
 */
@property (nonatomic, nullable) UIImage *image;
/**
 *  The x,y position of the moving object
 */
@property (nonatomic) CGPoint position;
/**
 *  The speed value of the moving object
 */
@property (nonatomic) float speed;
/**
 *  The width value of the moving object
 */
@property (nonatomic) float width;
/**
 *  The height of the moving object
 */
@property (nonatomic) float height;
/**
 *  The layer name associated with the moving object
 */
@property (nonatomic, nullable) NSString *layerName;
/**
 *  Set whether the moving object should snap to the grid/vector of the map
 */
@property (nonatomic, assign) BOOL snapToGrid;
/**
 *  Set whether the moving object should snap to waypoints on the map
 */
@property (nonatomic, assign) BOOL snapToWaypoint;
/**
 *  Returns whether the moving object should snap to wayfinding path on the map
 */
@property (nonatomic, readonly) BOOL shouldSnapToWayfindingPath;
/**
 *  Returns the threshold of when the moving object should snap to wayfinding path on the map, measured in pixels
 */
@property (nonatomic, readonly) float snapToWayfindingPathThreshold;
/**
 *  The custom view of the moving object
 */
@property (nonatomic, nullable) UIView *customView;
/**
 *  The animation timer of the moving object for snapping to grid/waypoint movement
 */
@property (nonatomic, nullable) NSTimer *animateTimer;

//UserLocation Properties
/**
 *  Set whether the moving object should redraw to reload the UI
 */
@property (nonatomic, assign) BOOL shouldRedraw;
/**
 *  The starting alpha of the confidence circle pulse
 */
@property (nonatomic) float startAlpha;
/**
 *  The ending alpha of the confidence circle pulse
 */
@property (nonatomic) float endAlpha;
/**
 *  The alpha of the static confidence circle
 */
@property (nonatomic) float confidenceAlpha;
/**
 *  The radius of the confidence circle
 */
@property (nonatomic) float confidenceRadius;
/**
 *  The duration of the confidence circle pulse
 */
@property (nonatomic) NSTimeInterval pulseAnimationDuration;
/**
 *  The delay between pulses of the confidence circle
 */
@property (nonatomic) NSTimeInterval delayBetweenPulseCycles;
/**
 *  Orientation of the moving object
 */
@property (nonatomic) float orientation;
/**
 *  The color of the moving object's center circle
 */
@property (nonatomic, nullable) UIColor *color;
/**
 *  The color of the confidence circle pulse
 */
@property (nonatomic, nullable) UIColor *pulseColor;
/**
 *  The color of the static confidence circle
 */
@property (nonatomic, nullable) UIColor *confidenceColor;
/**
 *  The transform of the moving object
 */
@property (nonatomic) CGAffineTransform userLocationTransform;

/**
 *  The parent view of the moving object
 */
@property (nonatomic, nonnull) UIView *parentView;

/**
 *  Default pop in animation of the moving object
 */
@property (nonatomic, copy) void (^_Nonnull willMoveToSuperviewAnimationBlock)(JMapMovingObject * _Nonnull view, UIView * _Nonnull superview);

/**
 *  Set behaviour of the moving object to snap to wayfidning path on the map
 */
-(void)snapToWayfindingPathWithThreshold:(float)threshold;

@end
