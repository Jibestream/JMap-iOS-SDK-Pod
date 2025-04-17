//
//  JMapLocale.h
//  JMapCore
//
//  Created by Louie Yuen on 2017-05-03.
//  Copyright © 2017 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>

/**
 *  The JMapLocale model.
 */
@interface JMapLocale : JMapBaseModel

/**
 *  The name of the locale.
 */
@property (nonatomic, strong, readonly, nullable) NSString *name;

/**
 *  The locale code.
 */
@property (nonatomic, strong, readonly, nullable) NSString *localeCode;

/**
 *  Initializes a JMapMapLabelInstance.
 *
 *  @param dict An NSDictionary parsed from the server.
 *  @return An initialized JMapLocale instance.
 */
-(nullable instancetype)initWithDictionary:(nonnull NSDictionary *)dict;
@end
