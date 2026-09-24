//
//  JMapZoneLabelFitMath.h
//  JMapRendering
//
//  Copyright © 2026 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  Measures a candidate string, in points, at the zone label's font.
 *
 *  Supplied by the caller so this class stays free of UIKit and every rule in it is unit-testable
 *  and portable — the iOS, Android and web implementations of SCPB-3877 must agree glyph for glyph.
 */
typedef CGFloat (^JMapZoneLabelTextMeasurer)(NSString *text);

/**
 *  Pure fit and truncation math for zone labels (SCPB-3877).
 *
 *  ## The fit gate
 *
 *      show iff measuredPoints(resolvedText) <= spanMapUnits * zoomScale
 *
 *  The rendered text must physically fit between the zone's two CMS waypoints — no overhang, ever.
 *  `JMapCanvas.zoomScale` is points per map unit (its `contentSize` is the map's own dimensions and
 *  `baseView` is 1:1 with it at scale 1; every transform applied to `baseView` is a pure rotation),
 *  so this is the same apparent-zoom-uniform gate Android expresses in physical pixels as
 *  `measuredPx <= span * rawMatrixScale` and web expresses in CSS pixels. There is deliberately
 *  NO height gate and NO per-tier minimum size: the waypoint span is the single CMS control over
 *  when a label appears, and it is owned by the mapping team.
 *
 *  ## Truncation
 *
 *  Unicode CODE POINTS (a surrogate pair counts as one, a combining mark counts as its own — this
 *  matches Java's `codePointCount` and JavaScript's `Array.from`, and is NOT the same as a grapheme
 *  cluster, so a truncation can split an emoji sequence or a flag). Cut after at least `minChars`
 *  code points (at least one), right-trim whitespace from the cut, append U+2026, and never
 *  truncate a name that is already that short — it is shown whole or not at all, never as a bare
 *  ellipsis.
 */
@interface JMapZoneLabelFitMath : NSObject

/**
 *  Points available along the label's span axis at the current zoom.
 *
 *  @param spanMapUnits Distance between the label's waypoints, in map units.
 *  @param zoomScale    Points per map unit (`JMapCanvas.zoomScale`).
 */
+ (CGFloat)availablePointsForSpan:(CGFloat)spanMapUnits zoomScale:(CGFloat)zoomScale;

/**
 *  The authoritative fit gate: rendered points against span points. A non-positive span never fits
 *  — anchor-only placements must be bounded by a viewport fraction instead, not by this.
 */
+ (BOOL)fitsMeasuredPoints:(CGFloat)measuredPoints
                      span:(CGFloat)spanMapUnits
                 zoomScale:(CGFloat)zoomScale;

/**
 *  The longest renderable string for `baseText` within `availablePoints`.
 *
 *  Returns the full text when it fits, else the longest `>= minChars`-code-point prefix (right
 *  trimmed) plus an ellipsis, else nil meaning hide.
 *
 *  Found by binary search rather than the descending linear scan Android uses: on the longest real
 *  zone names that is about eight measurements instead of forty-five, and this runs for every zone
 *  label on every frame. The two agree exactly for a monotonic
 *  measurer and stay within the agreed one-character cross-platform tolerance for a proportional
 *  font whose kerning is locally non-monotonic.
 *
 *  @param availablePoints Width budget in points: `availablePointsForSpan:zoomScale:` for
 *                         span-fitted labels, or a viewport fraction for anchor-only ones.
 */
+ (nullable NSString *)resolveText:(nullable NSString *)baseText
                   availablePoints:(CGFloat)availablePoints
                          minChars:(NSUInteger)minChars
                          measurer:(JMapZoneLabelTextMeasurer)measurer;

/**
 *  The first `count` code points of `text`, right-trimmed of whitespace, with U+2026 appended.
 */
+ (NSString *)truncateText:(NSString *)text toCodePoints:(NSUInteger)count;

/**
 *  The shortest string this label may ever render as — the "XXXX…" floor. Used to decide first
 *  visibility, and as the unit-label feasibility floor. Leading whitespace is skipped; names of
 *  `minChars` or fewer visible code points are returned without it, and a name that is all
 *  whitespace returns nil.
 */
+ (nullable NSString *)minStringForText:(nullable NSString *)text minChars:(NSUInteger)minChars;

/**
 *  Number of Unicode code points in `text` (surrogate pairs count as one).
 */
+ (NSUInteger)codePointCountOfText:(NSString *)text;

@end

NS_ASSUME_NONNULL_END
