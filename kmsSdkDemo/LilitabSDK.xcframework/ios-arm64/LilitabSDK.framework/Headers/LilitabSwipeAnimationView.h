//
//  LilitabSwipeAnimationView.h
//  LilitabSDK
//
//  Created by Kevin Snow on 3/15/18.
//  Copyright © 2018 Lilitab. All rights reserved.
//

#import <UIKit/UIKit.h>

IB_DESIGNABLE
@interface LilitabSwipeAnimationView : UIView

IBInspectable
@property (nonatomic,strong)    NSString* message;          // Message to display to user.

@property (nonatomic,assign)    BOOL animate;               // Show hand animating

@property (nonatomic,copy) void(^cancelPressBlock)(void);   // This block is called if cancel is pressed.

@end
