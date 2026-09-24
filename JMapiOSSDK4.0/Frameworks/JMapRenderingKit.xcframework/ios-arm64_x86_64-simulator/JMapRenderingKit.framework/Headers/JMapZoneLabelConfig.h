//
//  JMapZoneLabelConfig.h
//  JMapRendering
//
//  Copyright © 2026 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  Zoom tier a label is evaluated in.
 *
 *  Derived from `JMapCanvas.zoomScale`, which is POINTS per map unit and therefore already
 *  density-independent — the same value on every device at the same apparent zoom. It is passed to
 *  the `JMapLabelOptions` tier lookups as-is. (Android divides its raw matrix scale by display density to reach this
 *  same space; web's CSS-pixel scale is already in it. An iOS implementation that divided by
 *  `UIScreen.mainScreen.scale` would move every boundary by 2-3x.)
 */
typedef NS_ENUM(NSInteger, JMapLabelVisibilityTier) {
    /** No tier evaluated yet. Only valid as the `previous` argument to the banded lookup. */
    JMapLabelVisibilityTierNone = -1,
    JMapLabelVisibilityTierOverview = 0,
    JMapLabelVisibilityTierFloor,
    JMapLabelVisibilityTierRoom,
    JMapLabelVisibilityTierDetail
};

/**
 *  Default fewest code points a label may truncate to, excluding the ellipsis ("XXXX…"), for both
 *  `JMapLabelOptions.unitTruncationMinChars` and `zoneTruncationMinChars`. Shorter names are never
 *  truncated. Two characters was considered and rejected as too short (ENG call, 2026-08-05).
 */
extern const NSUInteger JMapZoneLabelTruncationMinChars;

/**
 *  Hysteresis band around the tier boundaries: a tier is entered only above
 *  `boundary * JMapLabelTierBandEnterFactor` and left only below
 *  `boundary * JMapLabelTierBandExitFactor`, so decisions keyed on the tier — placement rank, the
 *  per-tier unit minimums — cannot flicker when the scale settles exactly on a boundary. Applied by
 *  `-[JMapLabelOptions tierForZoomScale:previousTier:]` against the configured boundaries.
 *
 *  Flip points at the default boundaries: 2.4/2.6, 6.62/7.18, 10.75/11.65.
 */
extern const CGFloat JMapLabelTierBandEnterFactor;
extern const CGFloat JMapLabelTierBandExitFactor;

/**
 *  Fraction of a zone label's text footprint a shown unit label may overlap before the zone label
 *  is hidden, and the extra clearance it must regain before coming back.
 *
 *  Hysteresis in the overlap dimension rather than in time: a visible zone label survives up to
 *  `Tolerance` overlap, but once hidden it must fall to `Tolerance - HysteresisMargin` to return,
 *  so a unit label drifting across the boundary during a pan cannot toggle it every frame.
 */
extern const CGFloat JMapZoneLabelCollisionOverlapTolerance;
extern const CGFloat JMapZoneLabelHysteresisOverlapMargin;

/**
 *  Nominal height of a zone label's box, in map units.
 *
 *  A label whose span is narrower than this is PORTRAIT: it has less room across than down, so its
 *  text runs vertically. The value is the two-waypoint box height the other platforms use — Android
 *  builds an L-box this tall, web synthesises a container of the same height — and all three must
 *  agree, or a narrow zone reads horizontally on one platform and vertically on another.
 */
extern const CGFloat JMapZoneLabelContainerHeightMapUnits;

/**
 *  YES when a label with this span runs vertically. A span of 0 (anchor-only) is never portrait:
 *  such labels are bounded by a viewport fraction, which is far wider than the box height.
 */
extern BOOL JMapZoneLabelSpanIsPortrait(CGFloat spanMapUnits);

/**
 *  Largest fraction of the viewport's width (points, current orientation) an anchor-only zone label
 *  may occupy. Anchor-only labels have no waypoint span to fit between, so this is their only
 *  bound; a label whose "XXXX…" floor exceeds it hides.
 */
extern const CGFloat JMapZoneLabelAnchorOnlyViewportFraction;

/**
 *  Rotation a zone label should render at, in degrees, including the correction that keeps it
 *  readable.
 *
 *  A portrait label — one whose box is taller than it is wide — runs a quarter turn from its axis,
 *  whichever way keeps it from reading upside down. A landscape label that would otherwise appear
 *  upside down is flipped.
 *  The landscape bound is INCLUSIVE of 90 and 270, which are exactly the values axis-aligned CMS
 *  data produces most often; this is the case that decides whether a vertical zone label reads the
 *  same way here as it does on Android and web.
 *
 *  @param baseDegrees The placement's own rotation in map space.
 *  @param mapDegrees  The map's current rotation.
 *  @param portrait    Whether the label's box is taller than it is wide.
 */
extern CGFloat JMapZoneLabelRenderRotationDegrees(CGFloat baseDegrees, CGFloat mapDegrees, BOOL portrait);

/**
 *  Degrees wrapped into [0, 360).
 */
extern CGFloat JMapNormalizeDegrees(CGFloat degrees);

NS_ASSUME_NONNULL_END
