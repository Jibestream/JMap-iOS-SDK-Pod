//
//  JMapController.h
//  JMapController
//
//  Created by Aaron Wong on 2016-10-21.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JMapCoreKit/JMapCoreKit.h>
#import <JMapRenderingKit/JMapRenderingKit.h>
#import <JMapCoreKit/UIFont+withColor.h>

/**
 *  The Controller class of the iOS SDK.
 */
@interface JMapController : NSObject

/**
 *  The venue that is currently active and used.
 */
@property(nonatomic, strong, readonly) JMapActiveVenue *_Nullable activeVenue;
/**
 *  The current viewing floor.
 */
@property(nonatomic, strong, readonly) JMapFloor *_Nullable currentFloor;
/**
 *  The current viewing map.
 */
@property(nonatomic, strong, readonly) JMapMap *_Nullable currentMap;
/**
 *  The current loaded building.
 */
@property(nonatomic, strong, readonly) JMapBuilding *_Nullable currentBuilding;
/**
 *  The instance of the RenderingKit class.
 */
@property(nonatomic, nullable, strong, readonly) JMapRendering *renderer;
/**
 *  The rendering kit delegate.
 */
@property (nonatomic, weak, nullable) id<JMapRenderingKitDelegate> delegate;

/**
 *  The singleton instance of the user location class.
 */
@property (nonatomic, nonnull) JMapUserLocation *userLocation;

/**
 *  Stage reference
 */
@property(nonatomic, nullable, strong, readonly) JMapCanvas *stage;

/**
 *  Default Styles of Map, Amenities and PathType
 */

@property(nonatomic, nullable, strong, readonly) NSDictionary *defaultMapStyle;

#pragma mark - Initializer Methods

/**
 *  Type definition of the JMapError.
 */
typedef void(^_Nullable ErrorCompletion)(JMapError * _Nullable error);

/**
 *  Initializes a JMapJCore object along with canvas and activeVenue.
 *
 *  @param canvas A JMapCanvas object that will be used to display the map
 *  @param activeVenue A JMapActiveVenue object to be loaded
 */
-(nonnull instancetype)initWithCanvas:(nonnull JMapCanvas *)canvas activeVenue:(nonnull JMapActiveVenue *)activeVenue;


#pragma mark - Deallocation Methods

/**
 * Destroys Active Venue and all associated objects.
 */
- (void)destroyActiveVenue;

/**
 * Destroys Building and all associated objects.
 */
- (void)destroyBuilding;

/**
 * Destroys Floor and all associated objects.
 */
- (void)destroyFloor;

/**
 * Destroys Map and all associated objects.
 */
- (void)destroyMap;

#pragma mark - Map View Helpers

/**
 *  Renders and displays map. This method will also parse the map if needed.
 *
 *  @param map The JMapMap object to be rendered and displayed.
 *  @param completion The completion handler for the API call.
 */
- (void)showMap:(nonnull JMapMap *)map completionHandler:(ErrorCompletion)completion;

/**
 *  Renders and displays map with given bounds. This method will also parse the map if needed.
 *
 *  @param map The JMapMap object to be rendered and displayed.
 *  @param bound CGRect bound of the map to be shown
 *  @param completion The completion handler for the API call.
 */
- (void)showMap:(nonnull JMapMap *)map withBounds:(CGRect)bound completionHandler:(ErrorCompletion)completion;

/**
 *  Renders and displays map with given options. This method will also parse the map if needed.
 *
 *  @param map The JMapMap object to be rendered and displayed.
 *  @param options An NSDictionary options to be passed in for showing the map.
 *  @param completion The completion handler for the API call.
 */
- (void)showMap:(nonnull JMapMap *)map withOptions:(nonnull NSDictionary *)options completionHandler:(ErrorCompletion)completion;

/**
 *  Displays the default map.
 *
 *  @param completion The completion handler for the API call.
 */
- (void)showDefaultMapWithCompletionHandler:(ErrorCompletion)completion;

/**
 *  Parses a map so it is ready to be rendered.
 *
 *  @param map The JMapMap object to parse.
 *  @param completion The completion handler for the API call.
 */
- (void)parseMap:(nonnull JMapMap *)map completionHandler:(ErrorCompletion)completion;

/**
 * Parses all maps. Can be used to parse all maps in the active venue before rendering.
 *
 *  @param completion The completion handler for the API call.
 */
- (void)parseAllMapsWithCompletionHandler:(ErrorCompletion)completion;

/**
 *  Sets the transform of the map canvas displaying the map.
 *
 *  @param transform The transform that will be set on the map canvas.
 */
- (void)setMapTransform:(nonnull JMapTransform *)transform;

/**
 *  Resets the transform of the map canvas displaying the map.
 */
- (void)resetMapTransform;

/**
 *  Adjusts the map canvas so it displays the section of the map confined by the provided bounding rectangle.
 *
 *  @param bounds A CGRect object describing the bounds that the canvas will display.
 */
- (void)fitBoundsInView:(CGRect)bounds;

/**
 *  Sets the minimum and maximum scale limits for zooming the map.
 *
 *  @param min The minimum allowed map scale.
 *  @param max The maximum allowed map scale.
 */
- (void)setMinScale:(CGFloat)min andMaxScale:(CGFloat)max;

/**
 *  Scales the map by a given percentage (0 - 1)
 *
 *  @param percent The percentage to increase the current zoom scale by.
 *  @param duration The animation duration for the zoom scaling UI.
 */
- (void)scaleMapByPercent:(CGFloat)percent withAnimationDuration:(CGFloat)duration;


#pragma mark - Amenity Icon Helpers

/**
 *  Shows all amenities of a given type.
 *
 *  @param amenity A JMapAmenity which will be used to determine which type of amenities to show.
 */
- (void)showAmenity:(nonnull JMapAmenity *)amenity;

/**
 *  Shows all amenities of a given type that are placed on a certain waypoint.
 *
 *  @param amenity A JMapAmenity which will be used to determine which type of amenities to show.
 *  @param waypoint The waypoint that is associated with the amenities to be shown.
 */
- (void)showAmenity:(nonnull JMapAmenity *)amenity atWaypoint:(nonnull JMapWaypoint*)waypoint;

/**
 *  Shows all amenities of a given type.
 *
 *  @param amenity A JMapAmenity which will be used to determine which type of amenities to show.
 *  @param options An NSDictionary containing options on the amenity's behaviour on the map.
 *  scaleWithMap - [NSNumber numberWithBool:true/false], default false
 *  rotateWithMap - [NSNumber numberWithBool:true/false], default false, when false has precedence over flipWithRotation
 *  flipWithRotation - [NSNumber numberWithBool:true/false], default false
 *  scale - NSNumber, default to 1
 */
- (void)showAmenity:(nonnull JMapAmenity *)amenity withOptions:(nonnull NSDictionary *)options;

/**
 *  Shows all amenities of a given type that are placed on a certain waypoint.
 *
 *  @param amenity A JMapAmenity which will be used to determine which type of amenities to show.
 *  @param waypoint The waypoint that is associated with the amenities to be shown.
 *  @param options An NSDictionary containing options on the amenity's behaviour on the map.
 *  scaleWithMap - [NSNumber numberWithBool:true/false], default false
 *  rotateWithMap - [NSNumber numberWithBool:true/false], default false, when false has precedence over flipWithRotation
 *  flipWithRotation - [NSNumber numberWithBool:true/false], default false
 *  scale - NSNumber, default to 1
 */
- (void)showAmenity:(nonnull JMapAmenity *)amenity atWaypoint:(nonnull JMapWaypoint*)waypoint withOptions:(nonnull NSDictionary *)options;

/**
 *  Hides all amenities of a given type.
 *
 *  @param amenity A JMapAmenity which will be used to determine which type of amenities to hide.
 */
- (void)hideAmenity:(nonnull JMapAmenity *)amenity;

/**
 *  Hides all amenities of a given type that are placed on a certain waypoint.
 *
 *  @param amenity A JMapAmenity which will be used to determine which type of amenities to hide.
 *  @param waypoint The waypoint that is associated with the amenities to be hidden.
 */
- (void)hideAmenity:(nonnull JMapAmenity *)amenity atWaypoint:(nonnull JMapWaypoint*)waypoint;

/**
 *  Shows all amenities.
 */
- (void)showAllAmenities;

/**
 *  Shows amenities with options.
 *
 *  @param options An NSDictionary containing options on the amenity's behaviour on the map.
 *  scaleWithMap - [NSNumber numberWithBool:true/false], default false
 *  rotateWithMap - [NSNumber numberWithBool:true/false], default false, when false has precedence over flipWithRotation
 *  flipWithRotation - [NSNumber numberWithBool:true/false], default false
 *  scale - NSNumber, default to 1
 */
- (void)showAllAmenitiesWithOptions:(nonnull NSDictionary *)options;

/**
 *  Hides all amenities.
 */
- (void)hideAllAmenities;

/**
 *  Applies a style to all amenities.
 *
 *  @param style A JMapIconStyle object that defines the style to be used for all amenities.
 */
- (void)styleAmenities:(nullable JMapIconStyle*)style;

/**
 *  Applies a style to all amenities that are of the provided type.
 *
 *  @param amenity A JMapAmenity which will determine which type of amenities to style.
 *  @param style A JMapIconStyle object that defines the style that will be applied to the amenities.
 */
- (void)styleAmenity:(nullable JMapAmenity*)amenity withStyling:(nonnull JMapIconStyle*)style;

/**
 *  Applies a style to all amenities that are of the provided type and placed at a given waypoint.
 *
 *  @param amenity A JMapAmenity which will determine which type of amenities to style.
 *  @param waypoint The JMapWaypoint that is associated with the amenities to be styled.
 *  @param style A JMapIconStyle object that defines the style that will be applied to the amenities.
 */
- (void)styleAmenity:(nonnull JMapAmenity*)amenity atWaypoint:(nonnull JMapWaypoint*)waypoint withStyling:(nonnull JMapIconStyle*)style;

/**
 *  Resets the style of all amenities to their defaults.
 */
- (void)resetAmenityStyle;

/**
 *  Resets the style of all amenities that are of the provided type.
 *
 *  @param amenity A JMapAmenity which will determine which type of amenities will have their styling reset.
 */
- (void)resetAmenityStyle:(nullable JMapAmenity*)amenity;

/**
 *  Resets the style of all amenities that are of the provided type and placed at a given waypoint.
 *
 *  @param amenity A JMapAmenity which will determine which type of amenities will have their styling reset.
 *  @param waypoint The JMapWaypoint that is associated with the amenities that will have their styling reset.
 */
- (void)resetAmenityStyle:(nullable JMapAmenity*)amenity atWaypoint:(nullable JMapWaypoint*)waypoint;

/**
 *  Retrieves all icons, amenity and path type, on given map
 *
 *  @param map A JMapMap object to look for the icons.
 *  @param layerName The layer name to search for on the map, nil value will return all icons on the map.
 *  @return An array of JMapIconView objects that belong on the map.
 */
- (nonnull NSArray <JMapIconView*>*)getIconsOnMap:(nonnull JMapMap *)map withLayerName:(nullable NSString *)layerName;

#pragma mark - Path Type Icon Helpers

/**
 *  Shows all path types of a given type.
 *
 *  @param pathType A JMapAmenity which will be used to determine which type of amenities to show.
 */
- (void)showPathType:(nonnull JMapPathType*)pathType;

/**
 *  Shows all path types of a given type that are placed on a certain waypoint.
 *
 *  @param pathType A JMapPathType which will be used to determine which type of path types to show.
 *  @param waypoint The waypoint that is associated with the path types to be shown.
 */
- (void)showPathType:(nonnull JMapPathType*)pathType atWaypoint:(nullable JMapWaypoint*)waypoint;

/**
 *  Shows all path types of a given type.
 *
 *  @param pathType A JMapAmenity which will be used to determine which type of amenities to show.
 *  @param options An NSDictionary containing options on the amenity's behaviour on the map.
 *  scaleWithMap - [NSNumber numberWithBool:true/false], default false
 *  rotateWithMap - [NSNumber numberWithBool:true/false], default false, when false has precedence over flipWithRotation
 *  flipWithRotation - [NSNumber numberWithBool:true/false], default false
 *  scale - NSNumber, default to 1
 */
- (void)showPathType:(nonnull JMapPathType*)pathType withOptions:(nonnull NSDictionary *)options;

/**
 *  Shows all path types of a given type that are placed on a certain waypoint.
 *
 *  @param pathType A JMapPathType which will be used to determine which type of path types to show.
 *  @param waypoint The waypoint that is associated with the path types to be shown.
 *  @param options An NSDictionary containing options on the amenity's behaviour on the map.
 *  scaleWithMap - [NSNumber numberWithBool:true/false], default false
 *  rotateWithMap - [NSNumber numberWithBool:true/false], default false, when false has precedence over flipWithRotation
 *  flipWithRotation - [NSNumber numberWithBool:true/false], default false
 *  scale - NSNumber, default to 1
 */
- (void)showPathType:(nonnull JMapPathType*)pathType atWaypoint:(nullable JMapWaypoint*)waypoint withOptions:(nonnull NSDictionary *)options;


/**
 *  Shows all path types on map.
 */
- (void)showAllPathTypes;

/**
 *  Shows all path types with options.
 *
 *  @param options An NSDictionary containing options on the path type's behaviour on the map.
 *  scaleWithMap - [NSNumber numberWithBool:true/false], default false
 *  rotateWithMap - [NSNumber numberWithBool:true/false], default false, when false has precedence over flipWithRotation
 *  flipWithRotation - [NSNumber numberWithBool:true/false], default false
 *  scale - NSNumber, default to 1
 */
- (void)showAllPathTypesWithOptions:(nonnull NSDictionary *)options;

/**
 *  Hides all path types on map.
 */
- (void)hideAllPathTypes;

/**
 *  Hides all path types of a given type.
 *
 *  @param pathType A JMapPathType which will be used to determine which type of path types to hide.
 */
- (void)hidePathType:(nonnull JMapPathType*)pathType;

/**
 *  Hides all path types of a given type that are placed on a certain waypoint.
 *
 *  @param pathType A JMapPathType which will be used to determine which type of path types to hide.
 *  @param waypoint The waypoint that is associated with the path types to be hidden.
 */
- (void)hidePathType:(nonnull JMapPathType*)pathType atWaypoint:(nullable JMapWaypoint*)waypoint;

/**
 *  Applies a style to all path types.
 *
 *  @param style A JMapPathType object that defines the style to be used for all path types.
 */
- (void)stylePathTypes:(nullable JMapIconStyle*)style;

/**
 *  Applies a style to all path types that are of the provided type.
 *
 *  @param pathType A JMapPathType which will determine which type of path types to style.
 *  @param style A JMapIconStyle object that defines the style that will be applied to the path types.
 */
- (void)stylePathType:(nullable JMapPathType*)pathType withStyling:(nonnull JMapIconStyle*)style;

/**
 *  Applies a style to all path types that are of the provided type and placed at a given waypoint.
 *
 *  @param pathType A JMapPathType which will determine which type of path types to style.
 *  @param waypoint The JMapWaypoint that is associated with the path types to be styled.
 *  @param style A JMapIconStyle object that defines the style that will be applied to the path types.
 */
- (void)stylePathType:(nonnull JMapPathType*)pathType atWaypoint:(nonnull JMapWaypoint*)waypoint withStyling:(nonnull JMapIconStyle*)style;

/**
 *  Resets the style of all path types to their defaults.
 */
- (void)resetPathTypeStyle;

/**
 *  Resets the style of all path types that are of the provided type.
 *
 *  @param pathType A JMapPathType which will determine which type of path types will have their styling reset.
 */
- (void)resetPathTypeStyle:(nullable JMapPathType*)pathType;

/**
 *  Resets the style of all path types that are of the provided type and placed at a given waypoint.
 *
 *  @param pathType A JMapPathType which will determine which type of path types will have their styling reset.
 *  @param waypoint The JMapWaypoint that is associated with the path types that will have their styling reset.
 */
- (void)resetPathTypeStyle:(nullable JMapPathType*)pathType atWaypoint:(nullable JMapWaypoint*)waypoint;

#pragma mark - Image Map Label Helpers

/**
 *  Shows all map labels with images.
 */
- (void)showAllImageMapLabels;

/**
 *  Shows all map image labels with options.
 *
 *  @param options An NSDictionary containing options on the label's behaviour on the map.
 *  scaleWithMap - [NSNumber numberWithBool:true/false], default false
 *  rotateWithMap - [NSNumber numberWithBool:true/false], default false, when false has precedence over flipWithRotation
 *  flipWithRotation - [NSNumber numberWithBool:true/false], default false
 *  scale - NSNumber, default to 1
 */
- (void)showAllImageMapLabelsWithOptions:(nonnull NSDictionary *)options;

/**
 *  Hides all image map labels.
 */
- (void)hideAllImageMapLabels;

#pragma mark - Text Map Label Helpers

/**
 *  Shows all text map labels.
 */
- (void)showAllTextMapLabels;

/**
 *  Shows all text map labels with options.
 *
 *  @param options An NSDictionary containing options on the label's behaviour on the map.
 *  scaleWithMap - [NSNumber numberWithBool:true/false], default false
 *  rotateWithMap - [NSNumber numberWithBool:true/false], default false, when false has precedence over flipWithRotation
 *  flipWithRotation - [NSNumber numberWithBool:true/false], default true
 *  scale - NSNumber, default to 1
 */
- (void)showAllTextMapLabelsWithOptions:(nonnull NSDictionary *)options;

/**
 *  Hides all textual map labels.
 */
- (void)hideAllTextMapLabels;

/**
 *  Sets the font for textual map labels.
 *
 *  @param font The font to be used for the text in labels.
 */
- (void)setMapLabelFont:(nonnull UIFont*)font;

/**
 *  Sets the font for textual map labels.
 *
 *  @param jmapFont The font to be used for the text in labels.
 */
- (void)setMapLabelJMapFont:(nonnull JMapFont*)jmapFont;

#pragma mark - Unit Helpers

/**
 *  Retrieves all units from a map.
 *
 *  @param map The JMapMap that the units will be retrieved from.
 *  @param completion A callback with array of Shapes from the map's unit layer and JMapError.
 */
-(void)getUnitsFromMap:(nonnull JMapMap*)map completionHandler:(void(^ _Nonnull)(NSArray <Shape*>* _Nonnull shapes, JMapError * _Nullable error))completion;

/**
 *  Adds text to a unit on the map.
 *
 *  @param text A string with the text to be added to the unit.
 *  @param unit A shape representing the unit on the map that the text will be added to.
 *  @param font A UIFont object to edit the text font for unit labels.
 */
- (void)addText:(nonnull NSString*)text toUnit:(nonnull Shape*)unit withFont:(nullable UIFont *)font;

/**
 *  Adds text to a unit on the map.
 *
 *  @param text A string with the text to be added to the unit.
 *  @param unit A shape representing the unit on the map that the text will be added to.
 *  @param jmapFont A JMapFont object to edit the text font for unit labels.
 */
- (void)addText:(nonnull NSString*)text toUnit:(nonnull Shape*)unit withJMapFont:(nullable JMapFont *)jmapFont;

/**
 *  Adds an image to a unit on the map.
 *
 *  @param uri A NSString with the uri to be added to the unit.
 *  @param unit A shape representing the unit on the map that the image will be added to.
 */
-(void)addImage:(nonnull NSString*)uri toUnit:(nonnull Shape*)unit;

/**
 *  Hides the contents of a unit.
 *
 *  @param unit A shape representing the unit on the map which will have its text and image contents hidden.
 */
-(void)hideUnitContents:(nonnull Shape*)unit;

/**
 *  Shows the contents of a unit.
 *
 *  @param unit A shape representing the unit on the map which will have its text and image contents shown.
 */
-(void)showUnitContents:(nonnull Shape*)unit;

/**
 *  Gets a unit from a waypoint.
 *
 *  @param waypoint A JMapWaypoint object used to search for unit
 *  @param completion A callback that returns the shape and any errors or nil if shape association doesn't exist.
 */
- (void)getUnitFromWaypoint:(nonnull JMapWaypoint *)waypoint completionHandler:(void(^ _Nonnull)(Shape* _Nullable shape, JMapError * _Nullable error))completion;

/**
 *  Gets a units from a destination.
 *
 *  @param destination A JMapDestination object used to search for unit
 *  @param completion A callback that returns an array of shapes and any errors.
 */
- (void)getUnitsFromDestination:(nonnull JMapDestination *)destination completionHandler:(void(^ _Nonnull)(NSArray <Shape*>* _Nonnull shapes, JMapError * _Nullable error))completion;

/**
 *  Applies display mode to all units.
 */
- (void)applyDisplayModeToAllUnits;

/**
 *  Applies display mode to units on all maps with defined font
 *
 *  @param font A UIFont object to be applied to units which display text
 */
- (void)applyDisplayModeToAllUnitsWithFont:(nullable UIFont *)font;

/**
 *  Applies display mode to units on all maps with defined JMapFont
 *
 *  @param jmapFont A JMapFont object to be applied to units which display text
 */
- (void)applyDisplayModeToAllUnitsWithJMapFont:(nullable JMapFont *)jmapFont;

/**
 *  Applies display mode to units.
 *
 *  @param units An NSArray of Shape objects
 */
- (void)applyDisplayModeToUnits:(nonnull NSArray<Shape *>*)units;

/**
 *  Applies display mode to units with defined font
 *
 *  @param units An NSArray of Shape objects
 *  @param font A UIFont object to be applied to units which display text
 */
- (void)applyDisplayModeToUnits:(nonnull NSArray<Shape *>*)units withFont:(nullable UIFont *)font;

/**
 *  Applies display mode to units with defined JMapFont
 *
 *  @param units An NSArray of Shape objects
 *  @param jmapFont A JMapFont object to be applied to units which display text
 */
- (void)applyDisplayModeToUnits:(nonnull NSArray<Shape *>*)units withJMapFont:(nullable JMapFont *)jmapFont;

/**
 *  Restricts how many labels are visible at all times when point label is active
 *
 *  @param limit An NSNumber to indicate the number of labels to be shown
 */
- (void)setVisiblePointLabelLimit:(nonnull NSNumber *)limit;

/**
 *  Set the zoom level at where clustering should happen for labels
 *  Default value set to 5
 *
 *  @param zoomScale The zoom scale to set for clustering labels
 */
- (void)setZoomScaleForLabelClustering:(nonnull NSNumber *)zoomScale;

#pragma mark - Component/Popup Helpers

/**
 *  Adds a JMapMovingObject object onto the map.
 *
 *  @param movingObject A JMapMovingObject object to be added to the map
 *  @param map A JMapMap for the item to be added
 *  @param point CGPoint to indicate X,Y coordinates of the item
 *  @param layerName A NSString layer name on the map
 */
- (void)addMovingObject:(nonnull JMapMovingObject *)movingObject toMap:(nonnull JMapMap *)map atPoint:(CGPoint)point onLayer:(nonnull NSString *)layerName;

/**
 *  Removes a JMapMovingObject object from the map.
 *
 *  @param movingObject A JMapMovingObject object to be removed from the map
 */
- (void)removeMovingObject:(nonnull JMapMovingObject *)movingObject;

/**
 *  Updates a JMapMovingObject on the map.
 *
 *  @param movingObject A JMapMovingObject object to be update on the map
 *  @param map A JMapMap for the item to be updated on
 *  @param point CGPoint to indicate X,Y coordinates for updating the item
 *  @param duration A nullable NSNumber to determine the animation duration, pass 0 for no animation, nil to use default movingObject speed
 */
- (void)updateMovingObject:(nonnull JMapMovingObject *)movingObject onMap:(nonnull JMapMap *)map toPoint:(CGPoint)point duration:(nullable NSNumber *)duration;

/**
 *  Gets all JMapMovingObject on the map, gets all moving object instance if map is nil.
 *
 *  @param map A JMapMap to look for moving objects
 *  @return An array of moving objects
 */
- (nonnull NSArray <JMapMovingObject *>*)getAllMovingObjectsOnMap:(nullable JMapMap *)map;

/**
 *  Hides all JMapMovingObjects on specified layer.
 *
 *  @param layerName A NSString layer name to have items hidden
 */
- (void)hideAllMovingObjectsOnLayer:(nonnull NSString *)layerName;

/**
 *  Shows all JMapMovingObjects on specified layer.
 *
 *  @param layerName A NSString layer name to have items shown
 */
- (void)showAllMovingObjectsOnLayer:(nonnull NSString *)layerName;

/**
 *  Hides a JMapMovingObject.
 *
 *  @param movingObject A JMapMovingObject object to be hidden
 */
- (void)hideMovingObject:(nonnull JMapMovingObject *)movingObject;

/**
 *  Shows a JMapMovingObject.
 *
 *  @param movingObject A JMapMovingObject object to be shown
 */
- (void)showMovingObject:(nonnull JMapMovingObject *)movingObject;

/**
 *  Adds a UIView to the map at a specified position.
 *
 *  @param component The UIView that will be added to the map.
 *  @param map The JMapMap object that the UIView will be added to.
 *  @param point The point on the map that the UIView will be placed at.
 *  @param shouldRotate BOOL value to allow counter rotation
 *  @param shouldScale BOOL value to allow counter scale
 */
-(void)addComponent:(nonnull UIView*)component toMap:(nonnull JMapMap*)map atPoint:(CGPoint)point rotateWithMap:(BOOL)shouldRotate scaleWithMap:(BOOL)shouldScale;

/**
 *  Removes a UIView that has been added to the map.
 *
 *  @param component The UIView which was provided when it was initially added to the map.
 *  @param map The map on which the component exists;
 */
- (void)removeComponent:(nonnull UIView *)component onMap:(nonnull JMapMap*)map;

#pragma mark - Map Styling Helpers

/**
 *  Resets the styling for the map to its default state.
 */
-(void)resetMapStyle;

/**
 *  Applies default styling using a json config file, resetting map style will persist the styling
 *
 *  @param stylesheet NSString containing styles info
 */
- (void)useCustomStyleSheet:(nonnull NSString *)stylesheet __attribute__((deprecated("useCustomStyleSheet has been deprecated, please use loadJsonStyleConfiguration:(nonnull NSString *)stylesheet instead")));

/**
 *  Applies styling using a json config file after map has loaded, resetting map style will persist the styling
 *
 *  @param stylesheet NSString containing styles info
 */
- (void)loadJsonStyleConfiguration:(nonnull NSString *)stylesheet;

/**
 *  Define a sequence for map layers to be loaded using a json config file
 *
 *  @param sequence NSString containing sequence info
 */
- (void)loadMapWithSequence:(nonnull NSString *)sequence;

#pragma mark - Shape/Layer Helpers

/**
 *  Retrieves the shape objects in a map layer.
 *
 *  @param name The name of the layer that the shapes should be retrieved from.
 *  @param map The map that the layer is associated with.
 *  @param completion Callback for getting shapes in layer with name
 */
-(void)getShapesInLayerWithName:(nonnull NSString*)name fromMap:(nonnull JMapMap*)map completionHandler:(void(^ _Nonnull)(NSArray <Shape*>* _Nonnull shapes, JMapError * _Nullable error))completion;

/**
 *  Retrieves the bounds of a rectangle containing all the provided shapes.
 *
 *  @param shapes An array of Shape objects.
 *  @return A CGRect which is large enough to contain all the provided shapes.
 */
-(CGRect)getBoundsFromShapes:(nonnull NSArray<Shape*>*)shapes;

/**
 *  Applies styling to a shape.
 *
 *  @param shapes An array of Shape objects that styling will be applied to.
 *  @param style A JMapStyle
 */
-(void)styleShapes:(nonnull NSArray <Shape*>*)shapes withStyling:(nonnull JMapStyle*)style;

/**
 *  Resets the styling for all shapes.
 */
-(void)resetShapeStyles:(nonnull NSArray <Shape*>*)shapes;

/**
 *  Hides the layer with the specified name.
 *
 *  @param name The name of the layer to be hidden.
 */
-(void)hideLayer:(nonnull NSString*)name;

/**
 *  Shows the layer with the specified name.
 *
 *  @param name The name of the layer to be shown.
 */
-(void)showLayer:(nonnull NSString*)name;

/**
 *  Sets the layer interactivity by layer name. Sets all elements within a layer to be interactive.
 *
 *  @param layerName string of the desired layer to be set interactive.
 */
- (void)enableLayerInteractivityForLayerName:(nonnull NSString *)layerName;

/**
 *  Removes the layer interactivity by layer name. Sets all elements within a layer to be non-interactive.
 *
 *  @param layerName string of the desired layer to be set non-interactive.
 */
- (void)disableLayerInteractivityForLayerName:(nonnull NSString *)layerName;

/**
 *  Gets all the layer names in the map. Used to retrieve all layer names for a particular map.
 *
 *  @param map desired map to retrieve all layer names
 *  @return Array of layer name strings
 */
- (nonnull NSArray <NSString *>*)getAllLayerNamesInMap:(nonnull JMapMap *)map;

/**
 *  Gets all visible layer names in the map. Used to retrieve all layer names for layers that are currently visible on a particular map.
 *
 *  @param map desired map to retrieve all currently visible layer's names
 *  @return Array of layer name strings
 */
- (nonnull NSArray <NSString *>*)getAllVisibleLayerNamesInMap:(nonnull JMapMap *)map;

/**
 *  Returns a list of layer names that are hidden on the map.
 *
 *  @param map JMapMap object for retrieving layer names
 *  @return Array of layer names that are hidden
 */
- (nonnull NSArray <NSString *>*)getAllHiddenLayerNamesInMap:(nonnull JMapMap *)map;

/**
 *  Get a list of waypoints from a shape.
 *
 *  @param shape A Shape object to search JMapWaypoints with
 *  @return Array of JMapWaypoint objects associated with the provided Shape object
 */
- (nonnull NSArray <JMapWaypoint *>*)getWaypointsFromShape:(nonnull Shape *)shape;

/**
 *  Gets a list of destinations from a shape.
 *
 *  @param shape A Shape object to search JMapDestinations with
 *  @return Array of JMapDestination objects associated with the provided Shape object
 */
- (nonnull NSArray <JMapDestination *>*)getDestinationsFromShape:(nonnull Shape *)shape;

/**
 *  Gets a shape in the specified layer name from a waypoint.
 *
 *  @param layerName A NSString layerName to search on the specific layer
 *  @param waypoint A JMapWaypoint association to the Shape object
 *  @param completion Callback for getting a shape object in layer with waypoint
 */
- (void)getShapeInLayer:(nonnull NSString *)layerName fromWaypoint:(nonnull JMapWaypoint *)waypoint completionHandler:(void(^ _Nonnull)(Shape* _Nullable shape, JMapError * _Nullable error))completion;

/**
 *  Draws a shape on the map with optional style and layer name.
 *
 *  @param shape The shape to be drawn on the map
 *  @param map The map for the shape to be drawn on
 *  @param style Optional style associated to the Shape, defaults to black fill
 *  @param layerName A NSString layerName to add the shape on, defaults to "shapesLayer"
 */
- (void)drawShape:(nonnull Shape *)shape onMap:(nonnull JMapMap *)map withStyle:(nullable JMapStyle *)style withLayerName:(nullable NSString *)layerName;

/**
 *  Removes a shape on the map.
 *
 *  @param shape The shape to be removed on the map
 */
- (void)removeShape:(nonnull Shape *)shape;

#pragma mark - Gesture Helpers

/**
 *  Enables rotation gestures on the map.
 */
-(void)enableRotationGestures;

/**
 *  Disables rotation gestures on the map.
 */
-(void)disableRotationGestures;

/**
 *  Enables pan (swipe) gestures on the map.
 */
-(void)enablePanGestures;

/**
 *  Disables pan (swipe) gestures on the map.
 */
-(void)disablePanGestures;

/**
 *  Enables scale (pinch zoom) gestures on the map.
 */
-(void)enableScaleGestures;

/**
 *  Disables scale (pinch zoom) gestures on the map.
 */
-(void)disableScaleGestures;

/**
 *  Enables double tap gestures on the map with options.
 *
 *  @param options An NSDictionary of options. i.e. Key:layerName Value:Units
 */
-(void)enableDoubleTapGesturesWithOptions:(nullable NSDictionary *)options;

/**
 *  Disables double tap gestures on the map with options.
 */
-(void)disableDoubleTapGestures;

#pragma mark - Wayfinding Helpers

/**
 *  Generates a list of ordered array of JMapPathPerFloor to show the shortest path with visiting each destination exactly once. Aslo set the order of visit to achieve the shortest route for the given list of destination
 *  @param destinations The array of destinations require to visit
 *  @param startWayPoint The JMapWaypoint indicating the start position of the user
 *  @param accessible The accessibility value of the wayfinding route. 0 - 100 with 100 having full accessibility.
 *  @param completion A callback with ordered array of JMapPathPerFloor and ordered list of destinations array provided. The order for array of JMapPathPerFloor and destination is the order of visit each destination exactly once to achieve the shortest route for the given list of destination
 */
-(void)wayfindToMultipleDestinations:(NSArray<JMapDestination *> *_Nonnull) destinations fromStartWayPoint:(nonnull JMapWaypoint *)startWayPoint withAccessibility:(NSInteger)accessible completionHandler:( void(^_Nullable)(NSArray<NSArray <JMapPathPerFloor *>*>* _Nullable destinationPathPerFloor, NSArray<JMapDestination*>* _Nullable orderedDestinations))completion;

/**
 *  Generates an NSArray containing JMapPathPerFloor data.
 *
 *  @param waypointStart A JMapWaypoint object as starting point
 *  @param waypointEnd A JMapWaypoint object as ending point
 *  @param accessibility A NSInteger value between 0-100 to indicate accessibility level; 0 - Not accessible, 100 - accessible path
 *  @param obstacles An NSArray of obstacle layer names used for path generalization
 *  @return An NSArray of JMapPathPerFloor objects
 */
- (nonnull NSArray<JMapPathPerFloor*> *)wayfindBetweenWaypoint:(nonnull JMapWaypoint *)waypointStart andWaypoint:(nonnull JMapWaypoint *)waypointEnd withAccessibility:(NSInteger)accessibility withObstacle:(nullable NSArray <NSString *>*)obstacles;

/**
 *  Generates JMapPathPerFloor data for shortest path and alternative path.
 *
 *  @param waypointStart A JMapWaypoint object as starting point
 *  @param waypointEnd A JMapWaypoint object as ending point
 *  @param options For defining properties to set qualifying criteria for alternative path. If passed nil, default values are set
 *  @code
 *  NSDictionary *dict = @{
 *      @"optimalPathMatchRatio": NSNumber - 0~1, default 0.6 (alternative path should not overlap optimal path more than 60 %)
 *      @"optimalPathDistanceRatio": NSNumber, default 2 (alternative path at max can be 2 times in distance with respect to optimal path)
 *  }
 *  @param accessibility A NSInteger value between 0-100 to indicate accessibility level; 0 - Not accessible, 100 - accessible path
 *  @param obstacles An NSArray of obstacle layer names used for path generalization
 *  @param completion A callback with shortest/optimal path and array of alternative paths
 */
- (void)wayfindWithAlternativePathsBetweenWaypoint:(JMapWaypoint *_Nullable)waypointStart andWaypoint:(JMapWaypoint *_Nullable)waypointEnd withOptions:(NSDictionary*_Nullable)options withAccessibility:(NSInteger)accessibility withObstacle:(NSArray <NSString *>*_Nullable)obstacles completionHandler:(nonnull void(^)(NSArray <JMapPathPerFloor *>* _Nullable optimalPath, NSArray<NSArray <JMapPathPerFloor *>*>* _Nullable alternativePaths))completion;

/**
 *  Finds the waypoint with shortest path from the start waypoint, with the path adhering to the given accessibility and obstacles
 *  Generates an NSArray containing JMapPathPerFloor data.
 *
 *  @param waypointsArray An array of waypoints used to find the closest waypoint (waypoint with the shortest path) from the start way point
 *  @param waypointStart A JMapWaypoint object as starting point
 *  @param accessibility A NSInteger value between 0-100 to indicate accessibility level; 0 - Not accessible, 100 - accessible path
 *  @param obstacles An NSArray of obstacle layer names used for path generalization
 *
 *  @return An NSArray of JMapPathPerFloor objects
 */
- (nonnull NSArray<JMapPathPerFloor*> *) wayfindToClosestWaypointInArray:(nonnull NSArray<JMapWaypoint *>*)waypointsArray fromWaypoint:(nonnull JMapWaypoint*)waypointStart withAccessibility:(NSInteger)accessibility withObstacle:(nullable NSArray<NSString *> *)obstacles;

/**
 *  Draws the wayfind path on the map.
 *
 *  @param wayfindPath A JMapPathPerFloor object returned in the method wayfindBetweenWaypoint:andWaypoint:withAccessibility
 */
-(void)drawWayfindingPath:(nonnull JMapPathPerFloor*)wayfindPath __attribute__((deprecated("drawWayfindingPath has been deprecated, please use drawWayfindingPaths instead")));

/**
 *  Draws the wayfind path on the map.
 *
 *  @param wayfindPaths An array of JMapPathPerFloor objects returned in the method wayfindBetweenWaypoint:andWaypoint:withAccessibility
 */
-(void)drawWayfindingPaths:(nonnull NSArray<JMapPathPerFloor*>*)wayfindPaths;

/**
 *  Draws the wayfind path on the map with custom styling.
 *
 *  @param wayfindPath A JMapPathPerFloor object returned in the of method wayfindBetweenWaypoint:andWaypoint:withAccessibility
 *  @param style A JMapSVGStyle object containing styling information
 */
-(void)drawWayfindingPath:(nonnull JMapPathPerFloor*)wayfindPath withStyle:(nonnull JMapStyle*)style  __attribute__((deprecated("drawWayfindingPath: withStyle: has been deprecated, please use drawWayfindingPaths: withStyle: instead")));

/**
 *  Draws the wayfind path on the map with custom styling.
 *
 *  @param wayfindPaths  An array of JMapPathPerFloor objects returned in the of method wayfindBetweenWaypoint:andWaypoint:withAccessibility
 *  @param style A JMapSVGStyle object containing styling information
 */
-(void)drawWayfindingPaths:(nonnull NSArray<JMapPathPerFloor*>*)wayfindPaths withStyle:(nullable JMapStyle*)style;

/**
 *  Draws the wayfind optimal and alternative path on the map with custom styling.
 *
 *  @param wayfindPaths An array of JMapPathPerFloor objects returned in the method wayfindWithAlternativePathsBetweenWaypoint:andWaypoint:withOptions:withAccessibility
 *  @param style A JMapSVGStyle object containing styling information (default is red)
 *  @param alternativePaths An array of JMapPathPerFloor objects array returned in the method wayfindWithAlternativePathsBetweenWaypoint:andWaypoint:withOptions:withAccessibility
 *  @param alternativePathStyle A JMapSVGStyle object containing styling information for alternative paths (default is gray)
 */
-(void)drawWayfindingPaths:(NSArray<JMapPathPerFloor *>*_Nonnull)wayfindPaths withStyle:(JMapStyle*_Nullable)style  withAlternativePaths:(NSArray<NSArray<JMapPathPerFloor *>*>*_Nullable)alternativePaths withAlternativePathStyle:(JMapStyle*_Nullable)alternativePathStyle;

/**
 *  Get Bézier Path From Path Per Floor
 *
 *  @param pathPerFloor a JMapPathPerFloor object to render
 *
 *  @return UIBezierPath from the provided JMapPathPerFloor object
 */
- (nullable UIBezierPath *)getBezierPathFromPathPerFloor:(nonnull JMapPathPerFloor *)pathPerFloor;

/**
 *  Add Custom Wayfind PathLayer
 *
 *  @param wayfindLayer A custom CAShapeLayer for creating a waypath
 *  @param mapId of the map to place the layer on
 */
- (void)addCustomWayfindPathLayer:(nonnull CAShapeLayer *)wayfindLayer toMapID:(NSInteger)mapId;

/**
 *  Zoom to focus to wayfind path on the map with padding.
 *
 *  @param map The map of the wayfind path
 *  @param padding The surrounding padding around the path
 *  @param duration The animation duration for the zooming
 */
- (void)zoomToPathOnMap:(nonnull JMapMap *)map withPadding:(float)padding withAnimationDuration:(CGFloat)duration;

/**
 *  Gets the bound of a wayfinding path on the map.
 *
 *  @param map The map of the wayfind path
 */
- (CGRect)getBoundsOfPathOnMap:(nonnull JMapMap *)map;

/**
 *  Removes all wayfind paths on all floors.
 */
-(void)clearWayfindingPath;

/**
 *  Blocks the edge connecting from fromWaypoint to toWaypoint
 *
 *  @param fromWaypoint The starting waypoint to block the edge
 *  @param toWaypoint The ending waypoint to block the edge
 */
- (void)blockPathBetweenWaypoint:(nonnull JMapWaypoint *)fromWaypoint andWaypoint:(nonnull JMapWaypoint *)toWaypoint;

/**
 *  Unblocks the edges connecting from fromWaypoint to toWaypoint
 *
 *  @param fromWaypoint The starting waypoint to unblock the edge
 *  @param toWaypoint The ending waypoint to unblock the edge
 */
- (void)unblockPathBetweenWaypoint:(nonnull JMapWaypoint *)fromWaypoint andWaypoint:(nonnull JMapWaypoint *)toWaypoint;

/**
 *  Blocks the edges entering a waypoint
 *
 *  @param toWaypoint The waypoint to restrict entry to
 */
- (void)blockEntryToWaypoint:(nonnull JMapWaypoint *)toWaypoint;

/**
 *  Unblocks the edges entering a waypoint
 *
 *  @param toWaypoint The waypoint to remove restriction of entry to
 */
- (void)unblockEntryToWaypoint:(nonnull JMapWaypoint *)toWaypoint;

/**
 *  Blocks the edges exiting a waypoint
 *
 *  @param fromWaypoint The waypoint to restrict exit from
 */
- (void)blockExitFromWaypoint:(nonnull JMapWaypoint *)fromWaypoint;

/**
 *  Unblocks the edges exiting a waypoint
 *
 *  @param fromWaypoint The waypoint to remove restriction of exit from
 */
- (void)unblockExitFromWaypoint:(nonnull JMapWaypoint *)fromWaypoint;

#pragma mark - User Location

/**
 *  Updates the user's location with a new position on the map.
 *
 *  @param position A CGPoint indicating user's location in x,y coordinates
 *  @param map A JMapMap object that the location is currently on
 *  @param orientation A NSInteger float value to determine the icon's angle relative to the map's true north (degrees)
 *  @param confidence A NSInteger integer value indicating the radius of confidence measured in pixels
 */
- (void)updateUserLocation:(CGPoint)position floorMap:(nonnull JMapMap *)map orientation:(nullable NSNumber *)orientation confidenceRadius:(nullable NSNumber *)confidence;

/**
 *  Gets the nearest JMapWaypoint to JMapPoint.
 *
 *  @param point A JMapPoint object consisting of x,y,z where x,y are the coordinates and z is the mapId
 *  @return A JMapWaypoint object
 */
- (nullable JMapWaypoint *)getNearestWaypointWithJMapPoint:(nonnull JMapPoint *)point;

/**
 *  Applies a style to all empty units and will override the initial style of all UnitswithDestinations
 *  Note: Overrides the initial style of the unit with the one provided meaning that calling `resetShapeStyles` to `resetMapStyle` will default to the style set here.
 *
 *  @param style A JMapStyle object that defines the style to be used for all units with Destinations.
 */
- (void)styleEmptyUnits:(nonnull JMapStyle*)style;

/**
 *  Applies a style to all empty units
 *  Note: Overrides the initial style of the unit with the one provided meaning that calling `resetShapeStyles` to `resetMapStyle` will default to the style set here.
 *
 *  @param style A JMapStyle object that defines the style to be used for all empty units.
 *  @param overrideStyle A Boolean value that determines if the initial style of a unit should be overridden.
 */
- (void)styleEmptyUnits:(nonnull JMapStyle*)style  overrideInitialStyle:(Boolean)overrideStyle;

/**
 *  Applies a style to all units with Destinations and will override the initial style of all UnitswithDestinations
 *  Note: Overrides the initial style of the unit with the one provided meaning that calling `resetShapeStyles` to `resetMapStyle` will default to the style set here.
 *
 *  @param style A JMapStyle object that defines the style to be used for all units with Destinations.
 */
- (void)styleUnitsWithDestinations:(nonnull JMapStyle*)style;

/**
 *  Applies a style to all units with Destinations
 *  Note: Overrides the initial style of the unit with the one provided meaning that calling `resetShapeStyles` to `resetMapStyle` will default to the style set here.
 *
 *  @param style A JMapStyle object that defines the style to be used for all units with Destinations.
 *  @param overrideStyle A Boolean value that determines if the initial style of a unit should be overridden.
 */
- (void)styleUnitsWithDestinations:(nonnull JMapStyle*)style overrideInitialStyle:(Boolean)overrideStyle;

/**
 * Looks through an array of objects, using the properties of each object and the given query,
 * determines which Objects in the array have properties the most relevant to what the query is.
 * Allows for the inclusion of `highRankProperties` giving certain properties a more importance
 * then others. Finally, returning an array of objects which is <= to the maxResults limit set.
 *
 * @param array the array of objects to query
 * @param query the regex / keywords you want to find in an objects properties
 * @param rankedProperties an array of property names that should hold additional value when compared to others
 * @param maxResults the maximum number of results that you want the return array to have, defaults to 3
 * @return an array of objects, in order of most to least relevant based on your, Query and Ranked Properties.
 */
+ (nonnull NSArray*) getObjectsInArray:(nonnull NSArray*)array byString:(nonnull NSString *)query highRankProperties:(nullable NSArray<NSString *>*)rankedProperties maxResults:(nullable NSNumber*)maxResults;


@end

