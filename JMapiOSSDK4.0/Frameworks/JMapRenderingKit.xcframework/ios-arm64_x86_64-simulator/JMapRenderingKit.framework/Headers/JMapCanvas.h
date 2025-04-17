//
//  JMapCanvas.h
//  JMapRendering
//
//  Created by Aaron Wong on 2016-08-30.
//  Copyright © 2016 Jibestream. All rights reserved.
//

@class JMapIconView;

/**
 *  The JMapRenderingKitDelegate protocol.
 */
@protocol JMapRenderingKitDelegate;

/**
 *  The JMapCanvas model.
 */
@interface JMapCanvas : UIScrollView

/**
 *  JMapRenderingKitDelegate for rendering engine communication to the delegate class
 */
@property (nonatomic, weak, nullable) id <JMapRenderingKitDelegate> mapDelegate;

/**
 *  Rotation Gesture Recgonizer for all pannings, zoomings and rotations
 */
@property (nonatomic, strong, nonnull) UIRotationGestureRecognizer * rotationGestureRecognizer;

@end
