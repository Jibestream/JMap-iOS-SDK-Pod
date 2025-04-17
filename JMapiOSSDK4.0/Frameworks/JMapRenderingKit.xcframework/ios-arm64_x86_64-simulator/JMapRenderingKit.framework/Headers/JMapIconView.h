//
//  JMapIconView.h
//  JMap
//
//  Created by Louie Yuen on 2016-11-15.
//  Copyright (c) 2015 jibestream. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "JMapItemView.h"

@class JMapIconStyle;

/**
 *  The JMapIconView model.
 */
@interface JMapIconView : JMapItemView

/**
 *  Unique Identifier of Amenity Icons
 */
@property (nonatomic, strong) NSString *amenityTypeId;

/**
 *  Unique Identifier of Path Type Icons
 */
@property (nonatomic, strong) NSString *pathTypeId;

/**
 *  Unique Waypoint ID associated to the icon
 */
@property (nonatomic, strong) NSString *waypointId;

/**
 *  Unique Map ID associated to the icon
 */
@property (nonatomic, strong) NSString *mapId;

/**
 *  Custom Icon Style of the icon
 */
@property (nonatomic, strong) JMapIconStyle *customStyle;

/**
 *  Set Is Animated And Scale : method used to set animation and scale
 *
 *  @param isAnimated Boolean to set if is able to be animated
 *  @param scale float for scaling the icon
 */
- (void)setIsAnimated:(BOOL)isAnimated scale:(float)scale;

/**
 *  Init With Frame : Constructor method JMapIconView
 *
 *  @param aRect CGRect frame size of the Icon
 *  @param parentId Integer unique identifier for parent object
 *  @param shapes Array of shapes to apply the icon style
 *
 *  @return new JMapIconView object
 */
-(id)initWithFrame:(CGRect)aRect parentId:(id)parentId arrayOfShapes:(NSArray *)shapes;

/**
 *  Get Parent : Method to retrieve parent object of the icon
 *
 *  @return new Any Object
 */
-(id)getParent;

/**
 *  Get Is Animated : Method to check if JMapIconView is animated
 *
 *  @return Boolean
 */
-(BOOL)getIsAnimated;

/**
 *  Clean Up : Method to clean up all customization in icon view
 */
-(void)cleanUp;

/**
 *  Set Shapes : Method to set an array of shaped to this icon view
 */
-(void)setShapes:(NSArray *)shapes;

/**
 *  Reset Icon Style : Method to reset back to default style
 */
-(void)resetIconStyle;

/**
 *  Daw Icon With Style : Method to set style with the provided JMapIconStyle object
 *
 *  @param style JMapIconStyle object with desired customized styling
 */
-(void)drawIconWithStyle:(JMapIconStyle*)style;

@end
