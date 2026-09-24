//
//  JMapCanvas.h
//  JMapRendering
//
//  Created by Aaron Wong on 2016-08-30.
//  Copyright © 2016 Jibestream. All rights reserved.
//

@class JMapIconView;
@class JMapLabel;
#import "JMapLabelOptions.h"

@class JMapZoneLabelPlacement;

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

/**
 *  Supplies the zone labels for the venue, replacing any previously supplied set.
 *
 *  The host owns zone geometry — which waypoints form a label, where it is anchored, and how much
 *  room its text has. This canvas owns the rest: fitting the text to that room, truncating it,
 *  arbitrating it against unit labels, and drawing it. Hosts should not create labels for zones
 *  themselves; a zone label drawn by the host is invisible to the arbitration that keeps zone and
 *  unit labels from colliding.
 *
 *  Placements are held for the whole venue and filtered per floor by their `mapId`, so this is
 *  called once when the venue's zones are known, not on every floor change. Calling it triggers an
 *  immediate re-evaluation, so new labels appear without waiting for a gesture.
 *
 *  Only used by venues whose labels are positioned by L-box (`labelType` 0); venues using raw
 *  waypoint positioning keep their host's own zone-label behaviour.
 *
 *  Must be called on the main thread.
 *
 *  Placements are retained until replaced, and are NOT cleared by a floor or venue change —
 *  pass nil when tearing a venue down, or the previous venue's labels can be matched against
 *  the new venue's map ids.
 *
 *  @param placements Zone label placements, or nil/empty to remove all zone labels.
 */
- (void)setZoneLabelPlacements:(nullable NSArray<JMapZoneLabelPlacement *> *)placements;

/**
 *  Sets the label configuration. Passing nil restores `JMapLabelOptions.defaultOptions`.
 *
 *  The defaults are complete and valid, so a host that never calls this still renders correctly.
 */
- (void)setLabelOptions:(nullable JMapLabelOptions *)options;

/** The label configuration in force; never nil. */
- (nonnull JMapLabelOptions *)labelOptions;

@end
