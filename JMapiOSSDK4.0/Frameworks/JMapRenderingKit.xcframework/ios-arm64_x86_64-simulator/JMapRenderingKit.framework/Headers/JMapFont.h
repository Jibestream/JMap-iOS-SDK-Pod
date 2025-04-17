//
//  JMapFont.h
//  JMapRenderingKit
//
//  Created by Louie Yuen on 2018-10-16.
//  Copyright © 2018 Jibestream. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 *  The JMapTransform object.
 */
@interface JMapFont : NSObject

/**
 *  The JMapFont's font family.
 */
@property (nonatomic, nullable) NSString *fontFamily;
/**
 *  The JMapFont's hex fill string.
 */
@property (nonatomic, nullable) NSString *fill;
/**
 *  The JMapFont's font size.
 */
@property (nonatomic, nullable) NSNumber *fontSize;

@end
