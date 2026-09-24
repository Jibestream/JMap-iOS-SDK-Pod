//
//  JMapLabelOptions.h
//  JMapRendering
//
//  Copyright © 2026 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "JMapZoneLabelConfig.h"

NS_ASSUME_NONNULL_BEGIN

/** Which family wins contested space, per tier. */
typedef NS_ENUM(NSInteger, JMapLabelPriorityMode) {
    /** Zones place first at OVERVIEW and FLOOR, units first at ROOM and DETAIL. The agreed default. */
    JMapLabelPriorityModeByTier = 0,
    /** Zones place first at every tier. */
    JMapLabelPriorityModeZonesFirst,
    /** Units place first at every tier. */
    JMapLabelPriorityModeUnitsFirst
};

/**
 *  The label behaviour an application may configure, and the defaults it gets if it configures
 *  nothing.
 *
 *  The SDK owns these defaults so that a host which never calls `-setLabelOptions:` still renders
 *  correctly. An application that does call it becomes authoritative for the values it overrides;
 *  everything else keeps the SDK default, and changing a value is an application release rather
 *  than an SDK one. That is the point of the split — the values here are product policy, and
 *  product policy should not require a new SDK to change.
 *
 *  Deliberately NOT everything is configurable. Values that exist to stop the map flickering, or
 *  that must match across iOS, Android and web for the cross-platform acceptance to mean anything,
 *  stay fixed in the SDK: the tier hysteresis band, the collision tolerances and the zone label
 *  line height. Exposing them would let one customer's configuration silently break the guarantee
 *  that the same venue looks the same everywhere.
 *
 *  Two fields present on Android and web are deliberately absent here, because iOS has no consumer
 *  for them and a knob that changes nothing is worse than no knob: `sizeQuantizeMm` (iOS does not
 *  implement size quantization) and `verticalPaddingPerSide` (iOS pads symmetrically from a single
 *  value). Both should be added here at the same time as their implementations, not before.
 *
 *  Immutable. Invalid values are dropped with a logged warning and fall back to the default rather
 *  than raising, because a typo in one customer's configuration should cost that one setting, not
 *  the map.
 */
@interface JMapLabelOptions : NSObject <NSCopying>

/** The shipped defaults. Every property is present and valid. */
@property (class, nonatomic, readonly) JMapLabelOptions *defaultOptions;

/** Unit label text size, in points. Default 14. */
@property (nonatomic, readonly) CGFloat unitFontSize;

/**
 *  How much larger a zone label is than a unit label, in points. Default 2.
 *
 *  Expressed as a delta rather than an absolute size on purpose: whatever a customer sets the unit
 *  size to, a zone label cannot end up smaller than the rooms inside it — the inversion this
 *  feature was raised for.
 */
@property (nonatomic, readonly) CGFloat zoneFontDelta;

/** Derived as `unitFontSize + zoneFontDelta`. Never supplied directly. */
@property (nonatomic, readonly) CGFloat zoneFontSize;

/** Breathing room each side of the text, in points. Default 4. */
@property (nonatomic, readonly) CGFloat paddingPerSide;

/**
 *  Smallest container a unit label may render in, as a multiple of the font size. Lower renders
 *  sooner: it lowers the bar a container must clear before any text is drawn in it.
 *
 *  Default 1.3. Note this is iOS's shipped value from SCPB-2159; Android and web ship 1.8, so the
 *  same venue currently shows labels earlier here than on the other two platforms.
 */
@property (nonatomic, readonly) CGFloat minReadableWidthFactor;

/**
 *  Fewest code points a truncated UNIT label keeps, excluding the ellipsis. Default 4.
 *
 *  Separate from the zone floor because the two are different problems: a unit label sits inside
 *  one room and a short stub is often still identifiable from its position, while a zone label
 *  spans a neighbourhood and has to carry the name on its own.
 */
@property (nonatomic, readonly) NSUInteger unitTruncationMinChars;

/** Fewest code points a truncated ZONE label keeps, excluding the ellipsis. Default 4. */
@property (nonatomic, readonly) NSUInteger zoneTruncationMinChars;

/**
 *  The three zoom scales at which the map changes tier, ascending, separating
 *  OVERVIEW / FLOOR / ROOM / DETAIL. Default 2.5 / 6.9 / 11.2.
 */
@property (nonatomic, readonly) NSArray<NSNumber *> *tierBoundaries;

/**
 *  Smallest on-screen container, in points, a unit label may render in — one per tier, in tier
 *  order. Default 32 / 28 / 24 / 20.
 *
 *  These are iOS's SCPB-2159 values, lower than Android's and web's 40/36/33/30 so desk-sized units
 *  render. Changing them here changes iOS only, so a change made for one customer will read as a
 *  cross-platform defect unless it is mirrored.
 */
@property (nonatomic, readonly) NSArray<NSNumber *> *tierMinimums;

/** Which family places first, per tier. Default `ByTier`. */
@property (nonatomic, readonly) JMapLabelPriorityMode priorityMode;

/**
 *  Largest fraction of the viewport width an anchor-only zone label may occupy. Those labels have
 *  no waypoint span to fit between, so this is their only bound. Default 0.40.
 */
@property (nonatomic, readonly) CGFloat singleWaypointViewportFraction;

/**
 *  Unit label text colour, used when a label carries no colour of its own.
 *
 *  A label with a CMS font fill, or whose `textLabel.textColor` is anything other than the default
 *  black, wins over this; it is only the fallback. A colour explicitly set to `UIColor.blackColor`
 *  cannot be told apart from the default, so it takes this colour. Defaults to black, which is what the SDK used before this
 *  was configurable. Web's equivalent default is `#1f2937`; the two are deliberately left as they
 *  shipped rather than silently aligned, because changing either is a visible change to every
 *  venue that has not configured a colour.
 *
 *  The venue's CMS label style should drive this once that plumbing exists; until then a host that
 *  needs a specific colour sets it here.
 */
@property (nonatomic, readonly) UIColor *unitTextColor;

/**
 *  Zone label text colour, used when a placement carries no colour of its own.
 *
 *  Black, not the unit default, and deliberately so. Zone labels are new to the SDK — the base
 *  branch has no zone-label code at all — so there is no SDK behaviour to preserve. The only
 *  continuity that exists is with the app-drawn zone labels shipping today, which are black on
 *  iOS (`CXCFG.zoneLabelTheme` → `#000000`) and on Android (`ZoneLabelHelper` → `Color.BLACK`).
 *  Matching them is what keeps zone labels looking the same as they do now.
 *
 *  A zone spans many units with many fills, so there is no single background to reason about;
 *  this is the colour, not a starting point for one.
 */
@property (nonatomic, readonly) UIColor *zoneTextColor;

/**
 *  A copy with the supplied overrides applied over the defaults.
 *
 *  Keys are the property names above. An unknown key, or a value of the wrong type or out of range,
 *  is ignored with a logged warning and keeps its default. `zoneFontSize` is derived and is ignored
 *  if supplied.
 */
+ (instancetype)optionsWithOverrides:(nullable NSDictionary<NSString *, id> *)overrides;

/** Tier for a zoom scale, with no hysteresis, using the configured boundaries. */
- (JMapLabelVisibilityTier)tierForZoomScale:(CGFloat)zoomScale;

/**
 *  Tier with the hysteresis band applied against the previously reported tier.
 *
 *  The band itself is not configurable: it exists only to stop the tier flipping when a scale
 *  settles on a boundary, and a plausible-looking wrong value reintroduces flicker that reads as a
 *  rendering bug.
 */
- (JMapLabelVisibilityTier)tierForZoomScale:(CGFloat)zoomScale
                               previousTier:(JMapLabelVisibilityTier)previous;

/**
 *  Smallest container, in points, a unit label may render in at this tier. An out-of-range tier,
 *  including `JMapLabelVisibilityTierNone`, clamps to the last tier's value.
 */
- (CGFloat)minThresholdForTier:(JMapLabelVisibilityTier)tier;

/** Smallest container width, in points, any unit label may render in. */
- (CGFloat)minReadableWidth;

/** YES when zone labels place before unit labels in this tier, under the configured mode. */
- (BOOL)zoneLabelsPlaceFirstInTier:(JMapLabelVisibilityTier)tier;

@end

NS_ASSUME_NONNULL_END
