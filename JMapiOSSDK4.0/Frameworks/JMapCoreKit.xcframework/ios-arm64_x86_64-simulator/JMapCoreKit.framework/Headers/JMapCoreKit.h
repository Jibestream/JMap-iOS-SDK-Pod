//
//  JMapCoreKit.h
//  JMapCore
//
//  Created by Aaron Wong on 2016-08-17.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <JMapCoreKit/JMapJCore.h>

//Data Model Objects
#import <JMapCoreKit/JMapBaseModel.h>
#import <JMapCoreKit/JMapWaypoint.h>
#import <JMapCoreKit/JMapAssociation.h>
#import <JMapCoreKit/JMapVenue.h>
#import <JMapCoreKit/JMapDestination.h>
#import <JMapCoreKit/JMapBuilding.h>
#import <JMapCoreKit/JMapFloor.h>
#import <JMapCoreKit/JMapPathType.h>
#import <JMapCoreKit/JMapPath.h>
#import <JMapCoreKit/JMapAmenity.h>
#import <JMapCoreKit/JMapLocation.h>
#import <JMapCoreKit/JMapMapLabel.h>
#import <JMapCoreKit/JMapMap.h>
#import <JMapCoreKit/JMapUri.h>
#import <JMapCoreKit/JMapPosition.h>
#import <JMapCoreKit/JMapActiveVenue.h>
#import <JMapCoreKit/JMapMapLabelInstance.h>
#import <JMapCoreKit/JMapLocale.h>
#import <JMapCoreKit/JMapVenueDestination.h>
#import <JMapCoreKit/JMapMultiActiveVenues.h>

//Collection Objects
#import <JMapCoreKit/JMapBaseCollection.h>
#import <JMapCoreKit/JMapDestinationCollection.h>
#import <JMapCoreKit/JMapFloorCollection.h>
#import <JMapCoreKit/JMapWaypointCollection.h>
#import <JMapCoreKit/JMapAmenityCollection.h>
#import <JMapCoreKit/JMapPathCollection.h>
#import <JMapCoreKit/JMapMapCollection.h>
#import <JMapCoreKit/JMapUriCollection.h>
#import <JMapCoreKit/JMapPathTypeCollection.h>
#import <JMapCoreKit/JMapBuildingCollection.h>
#import <JMapCoreKit/JMapVenueCollection.h>
#import <JMapCoreKit/JMapMapLabelCollection.h>
#import <JMapCoreKit/JMapMapLabelInstances.h>
#import <JMapCoreKit/JMapLocaleCollection.h>
#import <JMapCoreKit/VenueDestinationCollection.h>

// Utilities
#import <JMapCoreKit/JMapCoreUtils.h>
#import <JMapCoreKit/JMapError.h>
#import <JMapCoreKit/JMapUtils.h>
#import <JMapCoreKit/UIFont+withColor.h>

// Wayfind
#import <JMapCoreKit/JMapASEdge.h>
#import <JMapCoreKit/JMapASGrid.h>
#import <JMapCoreKit/JMapASNode.h>
#import <JMapCoreKit/JMapASSearch.h>
#import <JMapCoreKit/JMapNeighbor.h>
#import <JMapCoreKit/JMapPathPerFloor.h>
#import <JMapCoreKit/JMapPoint.h>

#define JMapSDK_VERSION_STRING @"5.12.3"
#define JMapSDK_DEFAULT_TARGET_SERVER_VERSION @"4.12"
