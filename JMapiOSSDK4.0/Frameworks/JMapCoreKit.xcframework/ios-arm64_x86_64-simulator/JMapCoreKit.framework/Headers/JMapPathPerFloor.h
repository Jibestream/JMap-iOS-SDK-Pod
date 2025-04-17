//
//  JMapPathPerFloor.h
//  JMap
//
//  Created by Bryan Hayes on 2015-08-31.
//  Copyright (c) 2015 jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>

@class JMapASEdge;
@class JMapPathType;
@class JMapPoint;

/**
 *  The JMapPathPerFloor model.
 */
@interface JMapPathPerFloor : NSObject

/**
 *  The map ID associated to the path per floor object.
 */
@property NSNumber *mapId;
/**
 *  The mover/path type associated to the path per floor object.
 */
@property JMapPathType *mover;
/**
 *  A list of JMapASNode objects associated to the path per floor object.
 */
@property NSMutableArray <JMapASNode*> *points;
/**
 *  A list of JMapPoint objects associated to the path per floor object.
 */
@property NSMutableArray <JMapPoint*> *mapPoints;
/**
 *  A list of JMapWaypoint objects associated to the path per floor object.
 */
@property NSMutableArray <JMapWaypoint*> *waypoints;
/**
 *  The cost of the path per floor object.
 */
@property float cost;
/**
 *  Distance of the path in pixel.
 */
@property NSNumber *pixelDistance;
/**
 *  Distance of the path in mm.
 */
@property NSNumber *mmDistance;
/**
 *  accessibility level set for the JMapPathPerFloor. Accessibility is a NSInteger value between 0-100 to indicate accessibility level; 0 - Not accessible, 100 - accessible path
 */
@property NSInteger accessibility;
/**
 *  an array of obstacles set for the JMapPathPerFloor. Obstacles is an NSArray of obstacle layer names used for path generalization
 */
@property NSArray <NSString *>* obstacles;

@end
