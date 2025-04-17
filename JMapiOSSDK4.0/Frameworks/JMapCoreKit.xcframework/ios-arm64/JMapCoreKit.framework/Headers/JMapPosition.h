//
//  JMapPosition.h
//  JMapCore
//
//  Created by Louie Yuen on 2016-09-30.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  The JMapPosition model.
 */
@interface JMapPosition : NSObject
/**
 *  The top left coordinates in the form of [x,y].
 */
@property (nonatomic, strong, readonly, nullable) NSArray *topLeft;
/**
 *  The bottom right coordinates in the form of [x,y].
 */
@property (nonatomic, strong, readonly, nullable) NSArray *bottomRight;
/**
 *  Initializes a JMapPosition.
 *
 *  @param dict An NSDictionary parsed from the server.
 *  @return An initialized JMapPosition instance.
 */
-(nullable instancetype)initWithDictionary:(nonnull NSDictionary *)dict;

@end
