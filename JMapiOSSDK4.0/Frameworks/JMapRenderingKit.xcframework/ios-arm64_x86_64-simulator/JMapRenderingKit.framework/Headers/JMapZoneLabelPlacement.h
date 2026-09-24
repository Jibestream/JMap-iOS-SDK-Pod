//
//  JMapZoneLabelPlacement.h
//  JMapRendering
//
//  Copyright © 2026 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  Where a single zone label goes, and what it says — everything the SDK needs to fit, arbitrate
 *  and render it, and nothing else.
 *
 *  The host owns zone geometry: it decides which waypoints form a label group, where the label is
 *  anchored, and how much room it has. The SDK owns whether and how the label is drawn. This object
 *  is the whole boundary between those two jobs, which keeps the host out of the render path — the
 *  previous arrangement had the host synthesising LBox rectangles and label views and injecting
 *  them into the unit-label layer, so both sides wrote to the same state on different cadences.
 *
 *  Immutable, and safe to hold. Equality and `labelKey` are IDENTITY only: two placements for the
 *  same `(zoneId, labelTag)` are equal even if the map has moved the label, which is what lets the
 *  engine carry a label's visibility state across a rebuild.
 */
@interface JMapZoneLabelPlacement : NSObject <NSCopying>

/**
 *  CMS zone id. With `labelTag`, identifies this label across rebuilds and across app launches.
 */
@property (nonatomic, strong, readonly, nonnull) NSNumber *zoneId;

/**
 *  The CMS label tag (a waypoint `externalId`) whose waypoint group this label was placed from, or
 *  nil for a zone labelled as a whole. An empty tag is treated as nil. A zone may carry several
 *  tagged labels on one map.
 */
@property (nonatomic, copy, readonly, nullable) NSString *labelTag;

/**
 *  Map this placement belongs to. The engine ignores placements for any map other than the one on
 *  screen, so a set delivered late — after a floor change has already started — cannot paint the
 *  previous floor's labels onto the new one.
 */
@property (nonatomic, strong, readonly, nonnull) NSNumber *mapId;

/**
 *  The label's full, untruncated text. The engine truncates from this every frame; it never reads
 *  back a string it previously rendered.
 */
@property (nonatomic, copy, readonly, nonnull) NSString *text;

/**
 *  Where the label is centred, in map units.
 */
@property (nonatomic, assign, readonly) CGPoint anchor;

/**
 *  Room the text has along its own axis, in map units — for a two-waypoint label, the distance
 *  between the waypoints.
 *
 *  This is the single control over when the label appears: it shows once its text physically fits
 *  in `spanMapUnits * zoomScale` points. Pass 0 when there is no meaningful span (a label placed at
 *  one waypoint, or at the mean of several); such labels skip the span gate and are bounded by a
 *  fraction of the viewport instead. Never pass a made-up span to stand in for "no span" — the two
 *  behave very differently.
 */
@property (nonatomic, assign, readonly) CGFloat spanMapUnits;

/**
 *  Angle of the label's axis in map space, degrees clockwise. The engine adds the map's own
 *  rotation and a readability correction, so text is never drawn upside down.
 */
@property (nonatomic, assign, readonly) CGFloat rotationDegrees;

/**
 *  YES when the label's box is taller than it is wide, so its text runs vertically.
 *
 *  Stated rather than inferred: the engine has no box to measure once placement moves out of the
 *  host, and the readability rule needs to know. Almost always NO for two-waypoint labels, and YES
 *  only when the waypoints sit closer together than the label's own height.
 */
@property (nonatomic, assign, readonly) BOOL portrait;

/**
 *  Font family for the label, or nil for the system font. The canvas has no venue-wide font to fall
 *  back to, so a host that wants zone labels in the venue's CMS font passes its family here on
 *  every placement. The size comes from the label options (unit size plus the zone delta) and the
 *  weight is always regular; only the family is taken from here.
 */
@property (nonatomic, copy, readonly, nullable) NSString *fontFamily;

/**
 *  Text colour, or nil for the label options' `zoneTextColor`.
 */
@property (nonatomic, strong, readonly, nullable) UIColor *textColor;

/**
 *  Stable identity key, built once here rather than per lookup — the engine uses it to key
 *  per-label state on every frame.
 */
@property (nonatomic, copy, readonly, nonnull) NSString *labelKey;

/**
 *  Designated initialiser. Returns nil if `zoneId`, `mapId` or `text` is missing, or if `text` is
 *  blank — a label with nothing to say is not a placement.
 */
- (nullable instancetype)initWithZoneId:(nonnull NSNumber *)zoneId
                               labelTag:(nullable NSString *)labelTag
                                  mapId:(nonnull NSNumber *)mapId
                                   text:(nonnull NSString *)text
                                 anchor:(CGPoint)anchor
                           spanMapUnits:(CGFloat)spanMapUnits
                        rotationDegrees:(CGFloat)rotationDegrees
                               portrait:(BOOL)portrait
                             fontFamily:(nullable NSString *)fontFamily
                              textColor:(nullable UIColor *)textColor NS_DESIGNATED_INITIALIZER;

- (instancetype)init NS_UNAVAILABLE;

/**
 *  The identity key for a `(zoneId, labelTag)` pair, without building a placement.
 */
+ (nonnull NSString *)labelKeyForZoneId:(nonnull NSNumber *)zoneId
                               labelTag:(nullable NSString *)labelTag;

@end

NS_ASSUME_NONNULL_END
