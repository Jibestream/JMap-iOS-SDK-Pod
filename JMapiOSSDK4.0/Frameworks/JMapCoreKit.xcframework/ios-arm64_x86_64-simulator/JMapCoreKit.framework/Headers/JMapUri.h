//
//  JMapUri.h
//  JMapCore
//
//  Created by Louie Yuen on 2016-09-23.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>
/**
 *  The JMapUri model.
 */
@interface JMapUri : JMapBaseModel
/**
 *  The resource type of the uri.
 */
@property (nonatomic, strong, readonly, nullable) NSString *resourceType;
/**
 *  The mime type of the uri.
 */
@property (nonatomic, strong, readonly, nullable) NSString *mimeType;
/**
 *  The path string of the uri.
 */
@property (nonatomic, strong, readonly, nullable) NSString *path;
/**
 *  Initializes a JMapUri.
 *
 *  @param dict An NSDictionary parsed from the server.
 *  @return An initialized JMapUri instance.
 */
-(nullable instancetype)initWithDictionary:(nonnull NSDictionary *)dict;

@end
