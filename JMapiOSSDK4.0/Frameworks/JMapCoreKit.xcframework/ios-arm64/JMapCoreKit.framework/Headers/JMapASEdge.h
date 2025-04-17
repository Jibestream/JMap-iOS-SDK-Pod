//
//  JMapASEdge.h
//  JMap
//
//  Created by Bryan Hayes on 2015-08-31.
//  Copyright (c) 2015 jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  The JMapASEdge model.
 */
@interface JMapASEdge : NSObject
/**
 *  The ID of the edge.
 */
@property NSNumber *edgeId;
/**
 *  The ID's of the nodes associated to the edge of type int.
 */
@property NSMutableArray *nodes;
/**
 *  The type of the edge.
 *  1 - Normal Path
 *  2 - Elevator
 *  3 - Escalator
 *  4 - Stair Case
 *  5 - Moving Walkway
 */
@property NSNumber *type;
/**
 *  The cost of the edge of type float.
 */
@property NSNumber *cost;
/**
 *  The accessibility value of the edge.
 */
@property NSNumber *acc;
/**
 *  The speed of the edge of type float.
 */
@property NSNumber *speed;
/**
 *  The direction of the edge.
 */
@property NSNumber *direction;
/**
 *  The blocked status of the edge for whether wayfinding should use this edge.
 */
@property BOOL blocked;
/**
 *  Initializes a JMapASEdge.
 *
 *  @param edgeIdIn The edge ID.
 *  @param nodesIn The list of waypoint/node ID's.
 *  @param typeIn The path type of the edge.
 *  @param costIn The cost of the edge.
 *  @param accIn The accessibility value of the edge.
 *  @param speedIn The speed of the edge.
 *  @param directionIn The direction of the edge.
 *  @return An initialized JMapASEdge instance.
 */
-(id)initASEdge:(NSNumber *)edgeIdIn nodesIn:(NSMutableArray *)nodesIn typeIn:(NSNumber *)typeIn costIn:(NSNumber *)costIn accIn:(NSNumber *)accIn speedIn:(NSNumber *)speedIn directionIn:(NSNumber *)directionIn;

@end
