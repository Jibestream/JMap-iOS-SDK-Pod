//
//  JMapCanvas.h
//  JMapRendering
//
//  Created by Aaron Wong on 2016-08-30.
//  Copyright © 2016 Jibestream. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <JMapRenderingKit/JMapRenderingKit.h>

@class JMapIconView;

@protocol JMapRenderingKitDelegate;

@interface JMapCanvas : UIScrollView

@property (nonatomic, weak, nullable) id <JMapRenderingKitDelegate> mapDelegate;
@property (nonatomic, strong, nonnull) UIRotationGestureRecognizer * rotationGestureRecognizer;

@end
