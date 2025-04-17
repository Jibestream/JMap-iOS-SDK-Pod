//
//  JMapASNode.h
//  JMap
//
//  Created by Bryan Hayes on 2015-08-31.
//  Copyright (c) 2015 jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>

@class JMapASNode;

/**
 *  The JMapASNode model.
 */
@interface JMapASNode : NSObject
/**
 *  The ID of the node.
 */
@property NSNumber *nodeId;
/**
 *  The x coordinate of the node of type float.
 */
@property NSNumber *x;
/**
 *  The y coordinate of the node of type float.
 */
@property NSNumber *y;
/**
 *  The z value of the map of the node of type float.
 *  @see getMapZValue: in JMapASGrid
 */
@property NSNumber *z;
/**
 *  The map ID associated to the node.
 */
@property NSNumber *mapId;
/**
 *  The list of JMapASEdge objects associated to the node.
 */
@property NSMutableArray *edges;
/**
 *  The list of JMapNode objects of neighboring nodes associated to the node.
 */
@property NSMutableArray *neighbors;
/**
 *  The visited state of the node of type boolean.
 */
@property NSNumber *visited;
/**
 *  The closed state of the node of type boolean.
 */
@property NSNumber *closed;

/**
 *  f variable used in heuristic calculation.
 */
@property NSNumber *f;
/**
 *  g variable used in heuristic calculation.
 */
@property NSNumber *g;
/**
 *  h variable used in heuristic calculation.
 */
@property NSNumber *h;
/**
 *  distance from parent node.
 */
@property NSNumber *distance;
/**
 *  The parent associated to the node of type JMapASNode.
 */
@property JMapASNode *parent;
/**
 *  The path type ID of the edge being used.
 */
@property NSNumber *usedEdgeTypeId;
/**
 *  Initializes a JMapASNode.
 *
 *  @param edgeIdIn The edge ID.
 *  @param xIn The x coordinate of the node.
 *  @param yIn The y coordinate of the node.
 *  @param zIn The z value of the node on the map.
 *  @param mapIdIn The map ID associated to the node.
 *  @param edgesIn The list of the edges associated to the node.
 *  @param neighborsIn The list of neighboring JMapNeighbor objects associated to the node.
 *  @return An initialized JMapASNode instance.
 */
-(id)initASNode:(NSNumber *)edgeIdIn xIn:(NSNumber *)xIn yIn:(NSNumber *)yIn zIn:(NSNumber *)zIn mapIdIn:(NSNumber *)mapIdIn edgesIn:(NSMutableArray *)edgesIn neighborsIn:(NSMutableArray *)neighborsIn;
/**
 *  Resets the JMapASNode object to its default values.
 */
-(void)reset;

@end
