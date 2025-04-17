//
//  JMapASSearch.h
//  JMap
//
//  Created by Bryan Hayes on 2015-09-01.
//  Copyright (c) 2015 jibestream. All rights reserved.
//

#import <CoreFoundation/CoreFoundation.h>
#import <Foundation/Foundation.h>

@class JMapASGrid;
@class JMapASNode;

/**
 *  The A* search model used for wayfinding.
 */
@interface JMapASSearch : NSObject
{
    /**
     *  Binary heap reference variable.
     */
    CFBinaryHeapRef openStartHeap;
}
/**
 *  The tag of the search of type NSString.
 */
@property NSString *TAG;
/**
 *  The generated grid to run the search algorithm on.
 */
@property JMapASGrid *grid;
/**
 *  The JMapMapCollection object associated with the active venue.
 */
@property JMapMapCollection * maps;
/**
 *  The search algorithm for wayfinding.
 *
 *  @param from An integer value of the waypoint/node ID.
 *  @param to An integer value of the waypoint/node ID.
 *  @param accessLevel The accessibility value for generating the wayfinding route.
 *  @return An NSMutableArray of JMapPathPerFloor objects.
 */
- (NSMutableArray<JMapPathPerFloor*>*)search:(int)from to:(int)to accessLevel:(int)accessLevel;

- (NSMutableArray<JMapPathPerFloor*>*)searchInArray:(int)from to:(NSArray<JMapWaypoint*>*)arrayto accessLevel:(int)accessLevel;

@end
