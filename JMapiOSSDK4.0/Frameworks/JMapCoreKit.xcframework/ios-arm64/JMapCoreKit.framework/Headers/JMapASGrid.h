//
//  JMapASGrid.h
//  JMap
//
//  Created by Bryan Hayes on 2015-09-01.
//  Copyright (c) 2015 jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>

@class JMapWaypoint;
@class JMapPathPerFloor;
@class JMapASNode;
@class JMapASEdge;
@class JMapPath;
@class JMapNeighbor;

/**
 *  The JMapASGrid model.
 */
@interface JMapASGrid : NSObject
/**
 *  The vertical scale of the grid. Default to 100 of type float.
 */
@property NSNumber *verticalScale;
/**
 *  The list of JMapWaypoint objects on the grid.
 */
@property NSArray *waypoints;
/**
 *  The list of JMapPath objects on the grid.
 */
@property NSArray *paths;
/**
 *  The list of JMapPathType objects on the grid.
 */
@property NSArray *pathTypes;
/**
 *  The list of JMapMap objects on the grid.
 */
@property NSArray *mapFulls;
/**
 *  The list of JMapASNode objects on the grid.
 */
@property NSMutableArray *nodes;
/**
 *  The list of JMapASEdge objects on the grid.
 */
@property NSMutableArray *edges;
/**
 *  The list of JMapBuilding objects on the grid.
 */
@property NSArray *buildings;
/**
 *  The list of JMapFloor objects on the grid.
 */
@property NSMutableArray *floors;
/**
 *  Initializes a JMapASGrid.
 *
 *  @param waypointsIn The list of JMapWaypoint objects.
 *  @param pathsIn The list of JMapPath objects.
 *  @param pathTypesIn The list of JMapPathType objects.
 *  @param mapFullsIn The list of JMapMap objects.
 *  @param buildings The list of JMapBuilding objects.
 *  @param isMultiVenueLoaded True if generating grid for multiple venues
 *  @return An initialized JMapASGrid instance.
 */
-(id)initASGrid:(NSArray *)waypointsIn pathsIn:(NSArray *)pathsIn pathTypesIn:(NSArray *)pathTypesIn mapFullsIn:(NSArray *)mapFullsIn buildings:(NSArray *)buildings isForMultiVenue:(BOOL)isMultiVenueLoaded;

/**
 *  Gets the Z value of the map with the map ID.
 *
 *  @param mapId The map ID.
 *  @return The map's Z value of type float.
 */
-(float) getMapZValue:(int)mapId;
/**
 *  Gets the path type with the path type ID.
 *
 *  @param pathTypeId The path type ID.
 *  @return A JMapPathType object associated to the path type ID.
 */
-(JMapPathType *)getPathTypeById:(int)pathTypeId;
/**
 *  Resets the grid and sets all JMapASNode objects to their default values.
 */
-(void)reset;
/**
 *  Gets the node with the node ID.
 *
 *  @param idIn The node ID.
 *  @return A JMapASNode object associated to the node ID.
 */
-(JMapASNode *) getNodeById:(int)idIn;
/**
 *  Gets the nodes with the waypoint ids.
 *
 *  @param wps The waypoints to get corresponding node with ids as waypoint ids
 *  @return A JMapASNode object associated to the node ID.
 */
-(NSArray<JMapASNode*>*) getNodesForIds:(NSArray<JMapWaypoint*>*)wps;
/**
 *  Gets the neighbor node with the node ID.
 *
 *  @param idIn The node ID.
 *  @return A JMapASNode object neighbor node associated to the node ID.
 */
-(JMapASNode *) getNeighborNodeObject:(int)idIn;
/**
*  Method to block/unblock the edge between 2 nodes
*
*  @param fromNode The first node for blocking the edge
*  @param toNode The second node for blocking the edge
*  @param block Boolean to block/unblock the edge connecting the nodes
*/
-(void)shouldBlockEdgeBetweenNode:(JMapASNode *)fromNode andNode:(JMapASNode *)toNode block:(BOOL)block;
/**
*  Method to check if the edge between 2 nodes are blocked
*
*  @param fromNode The first node for checking the edge
*  @param toNode The second node for checking the edge
*  @return A Boolean indicating whether the edge is blocked
*/
-(Boolean)isEdgeBlockedBetweenNode:(JMapASNode *)fromNode andNode:(JMapASNode *)toNode;
/**
*  Method to block/unblock the edges entering a node
*
*  @param toNode The node for blocking inbound edges
*  @param block Boolean to block/unblock the edges entering the node
*/
- (void)shouldBlockEntryToNode:(JMapASNode *)toNode block:(BOOL)block;

/**
*  Method to block/unblock the edges exiting a node
*
*  @param fromNode The node for blocking outbound edges
*  @param block Boolean to block/unblock the edges exiting the node
*/
- (void)shouldBlockExitFromNode:(JMapASNode *)fromNode block:(BOOL)block;



@end
