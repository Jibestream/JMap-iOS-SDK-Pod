//
//  JMapMapLabel.h
//  JMapCore
//
//  Created by Louie Yuen on 2016-09-23.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>

@class JMapMapLabelInstances;
@class JMapUriCollection;
/**
 *  The JMapLabel model.
 */
@interface JMapMapLabel : JMapBaseModel
/**
 *  The name of the map label.
 */
@property (nonatomic, strong, readonly, nullable) NSString *name;
/**
 *  The JMapMapLabelInstances object associated with the map label.
 */
@property (nonatomic, strong, readonly, nullable) JMapMapLabelInstances *mapLabelInstances;
/**
 *  The JMapUriCollection object associated with the map label.
 */
@property (nonatomic, strong, readonly, nullable) JMapUriCollection *uris;
/**
 *  The svg string of the map label.
 */
@property (nonatomic, strong, readonly, nullable) NSString * svg;
/**
 *  Initializes a JMapMapLabel.
 *
 *  @param dict An NSDictionary parsed from the server.
 *  @return An initialized JMapMapLabel instance.
 */
-(nullable instancetype)initWithDictionary:(nonnull NSDictionary *)dict;

@end
