//
//  JMap.h
//  JMapCore
//
//  Created by Louie Yuen on 2017-11-22.
//  Copyright © 2017 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JMapOptions.h"
#import "JMapController.h"

/**
 *  The JMapDelegate object.
 */
@protocol JMapDelegate <NSObject>

@optional

/**
 *  Delegate call for when jmap has been initialized
 *
 *  @param error an error may be thrown if there was an issue with the initalization process
 */
- (void)jmapInitialized:(nullable JMapError *)error;

/**
 *  Delegate call for when jmap has parsed all maps
 *
 *  @param error an error may be thrown if there was an issue with parsing maps
 */
- (void)jmapParsedAllMaps:(nullable JMapError *)error;

/**
 * Delegate call when wayfind data has been loaded
 */
- (void)wayfindDataLoaded;

/**
 *  Delegate method for handling tap gesture
 *
 *  @param canvas JMapCanvas object associated to interaction
 *  @param element id tapped shape/icon/view on map
 *  @param point CGPoint x,y coordinate tapped
 */
- (void)canvas:(nonnull JMapCanvas *)canvas detectedTapOnElement:(nullable id)element atPoint:(CGPoint)point;

/**
 *  Delegate method for handling double tap gesture
 *
 *  @param canvas JMapCanvas object associated to interaction
 *  @param element id double tapped shape/icon/view on map
 *  @param point CGPoint x,y coordinate tapped
 */
- (void)canvas:(nonnull JMapCanvas *)canvas detectedDoubleTapOnElement:(nullable id)element atPoint:(CGPoint)point;

/**
 *  Delegate method for handling long press gesture
 *
 *  @param canvas JMapCanvas object associated to interaction
 *  @param element id long pressed shape/icon/view on map
 *  @param point CGPoint x,y coordinate tapped
 */
- (void)canvas:(nonnull JMapCanvas *)canvas detectedLongPressOnElement:(nullable id)element atPoint:(CGPoint)point;

/**
 *  Delegate method for handling zoom changes
 *  @param canvas JMapCanvas object associated to interaction
 *  @param zoomScale float value of changed zoom scale
 */
- (void)canvas:(nonnull JMapCanvas *)canvas scrollViewDidZoom:(float)zoomScale;

/**
 *  Delegate method for handling scrolling of the map
 *  @param canvas JMapCanvas object associated to interaction
 *  @param scrollView the UIScrollView object being interacted with
 */
- (void)canvas:(nonnull JMapCanvas *)canvas scrollViewDidScroll:(nonnull UIScrollView *)scrollView;

/**
 *  Delegate method for handling panning of the map
 *  @param canvas JMapCanvas object associated to interaction
 *  @param anchorPoint CGPoint on where the panning began on map
 */
- (void)canvas:(nonnull JMapCanvas *)canvas scrollViewDidPan:(CGPoint)anchorPoint;

/**
 *  Delegate method for reading rotation of the map
 *  @param canvas JMapCanvas object associated to interaction
 *  @param degrees float value for the rotation of the canvas
 */
- (void)canvas:(nonnull JMapCanvas *)canvas scrollViewDidRotateByDegrees:(float)degrees;

/**
 *  Listener for when a moving object finish animating
 *  @param movable A JMapMovingObject that has animation completed
 */
- (void)movingObjectAnimationComplete:(nonnull JMapMovingObject *)movable;

@end

/**
 *  The JMap Class.
 */
@interface JMap : NSObject

/**
 *  The delegate to subscribe to
 */
@property (nonatomic, weak, nullable) id <JMapDelegate> delegate;

/**
 *  JMapCore property that can be accessed externally, after being populated
 */
@property (nonatomic, strong, nonnull) JMapJCore * core;

/**
 *  ActiveVenue property that can be accessed externally, after being populated
 */
@property (nonatomic, strong, nonnull) JMapActiveVenue * activeVenue;

/**
 *  JMapController property that can be accessed externally, after being populated
 */
@property (nonatomic, strong, nonnull) JMapController * controller;

/**
 *  The options object for configuring map loading properties
 */
- (nonnull instancetype)initWithOptions:(nonnull JMapOptions *)options;

@end
