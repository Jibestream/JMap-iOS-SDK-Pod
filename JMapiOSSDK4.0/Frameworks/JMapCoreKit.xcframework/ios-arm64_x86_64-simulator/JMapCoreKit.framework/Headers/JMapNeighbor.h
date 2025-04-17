//
//  JMapNeighbor.h
//  JMap
//
//  Created by Bryan Hayes on 2015-08-31.
//  Copyright (c) 2015 jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>

@class JMapWaypoint;
@class JMapASEdge;

/**
 *  The JMapNeighbor model.
 */
@interface JMapNeighbor : NSObject
/**
 *  The ID of the neighbor node.
 */
@property NSNumber *neighborId;
/**
 *  The cost of the neighbor node.
 */
@property NSNumber *cost;
/**
 *  The accessibility value of the neighbor node.
 */
@property NSNumber *acc;
/**
 *  The edge ID of the neighbor node.
 */
@property NSNumber *edgeId;
/**
 *  The edge's path type ID of the neighbor node.
 */
@property NSNumber *edgeTypeId;
/**
 *  The distance of the neighbor node.
 */
@property NSNumber *distance;
/**
 *  The x coordinate of the neighbor node.
 */
@property NSNumber *x;
/**
 *  The y coordinate of the neighbor node.
 */
@property NSNumber *y;
/**
 *  The z value of the map of the neighbor node.
 *  @see getMapZValue: in JMapASGrid
 */
@property NSNumber *z;
/**
 *  Initializes a JMapNeighbor.
 *
 *  @param currentWP The current waypoint used for generating the neighbor.
 *  @param currentEdge The current edge used for generating the neighbor.
 *  @param totalCost The total cost of the neighbor.
 *  @param zIn The z value of the map of the neighbor node.
 *  @return An initialized JMapNeighbor instance.
 */
-(id)initNeighbor:(JMapWaypoint *)currentWP currentEdge:(JMapASEdge *)currentEdge totalCost:(NSNumber *)totalCost distanceIn:(NSNumber *)distanceIn zIn:(NSNumber *)zIn;

@end
