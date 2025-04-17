//
//  UIFont+withColor.h
//  JMapCore
//
//  Created by Jibestream on 2017-11-24.
//  Copyright © 2017 Jibestream. All rights reserved.
//

#import <UIKit/UIKit.h>

/**
 *  The UIFont category to include text color.
 */
@interface UIFont (withColor)

/**
 *  The text color property of the UIFont.
 */
@property (nonatomic, strong) UIColor *textColor;

/**
 *  UIFont initialization method to include text color.
 *
 *  @param fontName The font family name.
 *  @param fontSize The size of the font.
 *  @param textColor The text color of the font.
 *  @return UIFont instance with the passed in properties.
 */
+ (UIFont *)fontWithName:(NSString *)fontName size:(CGFloat)fontSize color:(UIColor*)textColor;

/**
 *  Setter for the text color.
 *
 *  @param textColor The text color of the font.
 */
- (void)setTextColor:(UIColor *)textColor;

/**
 *  Getter for the text color.
 *
 *  @return The text color of the font.
 */
- (UIColor *)textColor;

@end
