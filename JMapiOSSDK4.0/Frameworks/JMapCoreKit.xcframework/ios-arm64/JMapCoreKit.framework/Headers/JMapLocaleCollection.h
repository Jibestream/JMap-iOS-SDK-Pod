//
//  JMapLocaleCollection.h
//  JMapCore
//
//  Created by Louie Yuen on 2017-05-03.
//  Copyright © 2017 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>

@class JMapLocale;

/**
 *  The JMapLocaleCollection model.
 */
@interface JMapLocaleCollection : JMapBaseCollection

/**
 *  Gets a locale with name.
 *
 *  @param name The string name associated to the locale.
 *  @return A locale with the given name.
 */
- (nullable JMapLocale*)getByName:(nonnull NSString *)name;

/**
 *  Gets a locale with locale code.
 *
 *  @param localeCode The string locale code associated to the locale.
 *  @return A locale with the given locale code.
 */
- (nullable JMapLocale*)getByLocaleCode:(nonnull NSString *)localeCode;

@end
