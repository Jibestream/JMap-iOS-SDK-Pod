//
//  JMapCanvas.h
//  JMapRendering
//
//  Created by Aaron Wong on 2016-08-30.
//  Copyright © 2016 Jibestream. All rights reserved.
//

@class JMapIconView;
@class JMapLabel;

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

/**
 *  Unit labels on the current floor whose text is currently rendered on screen.
 *
 *  Unit label text is drawn by a screen-space overlay rather than by the JMapLabel container, so
 *  inspecting a label's own view state is not a reliable way to tell whether its text is showing.
 *  Use this method instead when host code needs to react to which unit labels are visible — for
 *  example to lay out zone or category labels around them.
 *
 *  @return An array of visible unit labels. Empty when the overlay is inactive or nothing is shown.
 */
- (nonnull NSArray<JMapLabel *> *)getVisibleUnitLabelsOnFloor;

@end
