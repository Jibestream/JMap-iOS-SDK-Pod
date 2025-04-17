//
//  JMapMapLabelInstances.h
//  JMapCore
//
//  Created by Louie Yuen on 2016-10-20.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>

@class JMapMapLabelInstance;

/**
 *  The JMapMapLabelInstances model.
 */
@interface JMapMapLabelInstances : JMapBaseCollection

/**
 *  Gets a list of JMapMapLabelInstance objects by map ID.
 *
 *  @param mapId An NSInteger to search for.
 *  @return An NSArray of JMapMapLabelInstance objects associated to mapId or an empty array if none exists.
 */
-(nonnull NSArray <JMapMapLabelInstance*>*)getByMapId:(NSInteger)mapId;
/**
 *  Gets a list of JMapMapLabelInstance objects that is on all levels.
 *
 *  @return An NSArray of JMapMapLabelInstance objects that is located on all levels.
 */
-(nonnull NSArray <JMapMapLabelInstance*>*)getLocationOnAllLevels;

@end
