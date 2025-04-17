//
//  JMapCoreUtils.h
//  JMap
//
//  Created by Aaron Wong on 2016-08-04.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  The JMapCoreUtils model.
 */
@interface JMapCoreUtils : NSObject

#pragma mark - Parsers
/**
 *  JSON data parsing method.
 *
 *  @param data The data to be parsed.
 *  @param handler The completion handler returning any errors or parsed data upon completion.
 */
+ (void)parseJSONWithData:(NSData *)data completionHandler:(void(^)(NSString * error, NSDictionary * data))handler;

/**
 *  JSON create with data method.
 *
 *  @param data The data used to create the JSON.
 *  @param handler The completion handler returning any errors or JSON data upon completion.
 */
+ (void)createJSONWithData:(NSDictionary <NSString *, id>*)data completionHandler:(void(^)(NSString * error, NSData * data))handler;

@end
