//
//  JMapRendering.h
//  JMapRendering
//
//  Created by Aaron Wong on 2016-08-18.
//  Copyright © 2016 Jibestream. All rights reserved.
//

@class JMapCanvas;
@class JMapBaseLayer;
@class Shape;
@class JMapMovingObject;

/**
 *  The JMapRenderingKitDelegate model.
 */
@protocol JMapRenderingKitDelegate <NSObject>

@optional
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
*  Delegate method for handling zooming end
*  @param canvas JMapCanvas object associated to interaction
*  @param zoomScale float value of zoom scale at zoom gesture end
*/
- (void)canvas:(nonnull JMapCanvas *)canvas scrollViewDidEndZoom:(float)zoomScale;

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
*  Delegate method for handling the end of panning of the map
*  @param canvas JMapCanvas object associated to interaction
*  @param centerPoint CGPoint on the center where the panning ends on the map
*/
- (void)canvas:(nonnull JMapCanvas *)canvas scrollViewDidEndPanning:(CGPoint)centerPoint;

/**
 *  Delegate method for reading rotation of the map
 *  @param canvas JMapCanvas object associated to interaction
 *  @param degrees float value for the roation of the canvas
 */
- (void)canvas:(nonnull JMapCanvas *)canvas scrollViewDidRotateByDegrees:(float)degrees;

/**
 *  Listener for when a moving object finish animating
 *  @param movable A JMapMovingObject that has animation completed
 */
- (void)movingObjectAnimationComplete:(nonnull JMapMovingObject *)movable;

@end

/**
 *  The Rendering engine class of the iOS SDK.
 */
@interface JMapRendering : NSObject

/**
 *  Dictionary of pre-rendered maps sorted map ID keys
 */
@property (nonatomic, strong, readonly, nonnull) NSMutableDictionary <NSString *, JMapBaseLayer *>* maps;

/**
 *  JMapRenderingKitDelegate for rendering engine communication to the delegate class
 */
@property (nonatomic, assign, nullable) id<JMapRenderingKitDelegate> delegate;

/**
 *  Init Render Kit For Map View : Constructor method JMapRenderingEngine
 *
 *  @param canvas JMapCanvas object to use as the main canvas to displaying all renderings
 *
 *  @return newly created JMapRenderingKit object
 */
- (nonnull instancetype)initRenderKitForMapView:(nonnull JMapCanvas *)canvas;

/**
 *  Show Map With ID : Display map on the canvas. If map has not been parse yet it will parse the map as well
 *  @param mapId unique Integer identifier for the map
 *  @param svg String that will be parsed
 *  @param completion handler to return a preRendered value, map style or an error
 */
- (void)showMapWithId:(NSInteger)mapId svgString:(nonnull NSString *)svg completionHandler:(nonnull void (^)(BOOL preRendered,NSDictionary* _Nullable styles, NSError * _Nullable error))completion;

/**
 *  Parse Map With Id : Pre parses that map but does not display the map on the canvas.
 *  @param mapId unique Integer identifier for the map
 *  @param svg String that will be parsed
 *  @param completion handler to return a preRendered value or an error
 */
- (void)parseMapWithId:(NSInteger)mapId svgString:(nonnull NSString *)svg completionHandler:(nonnull void (^)(NSError * _Nullable error))completion;

/**
 *  Get Parsed Maps
 *  @return An array of parsed maps
 */
- (nonnull NSArray <JMapBaseLayer*>*)getParsedMaps;

#pragma mark - Map Searching

/**
 *  Search For Map With Map ID : Used to query for a map with the provided mapId
 *  @param mapId to search for
 *  @return JMapBaseLayer object with the provided mapId if exists
 */
- (nullable JMapBaseLayer *)searchForMapWithMapId:(NSInteger)mapId;


#pragma mark Cluster Update

/**
 *  Call to enable clustering behaviour for labels
*/
- (void)enableLabelsClustering;

/**
 *  Call to disable clustering behaviour for labels
*/
- (void)disableLabelsClustering;

/**
 *  Call to update the cluster calculation
 *  @param animated parameter for adding animation to the cluster updates
*/
- (void)updateClusterWithAnimation:(BOOL)animated;

/**
 *  Method to hide or show all unit contents
 *  @param shouldHide BOOL to determine whether the unit contents should be hidden or shown
*/
- (void)shouldHideAllUnits:(BOOL)shouldHide;

@end
