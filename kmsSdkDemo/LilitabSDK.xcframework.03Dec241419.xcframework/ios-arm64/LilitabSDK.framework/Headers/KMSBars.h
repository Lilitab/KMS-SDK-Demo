//
//  KMSBars.h
//  KMS
//
//  Created by Kevin Snow on 10/26/17.
//  Copyright © 2017 Lilitab LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol KMSUnlockButtonDelegate;

IB_DESIGNABLE
@interface KMSBars : UIView

+(NSNotificationName)   barsShown_Notification;
+(NSNotificationName)   barsHidden_Notification;

-(void) hideBars;
-(void) showBars;

    // Bottom menubar
@property (nonatomic,assign)    NSString*                   bottomBarText;

@property (nonatomic,strong)    id<KMSUnlockButtonDelegate> unlockButtonDelegate;
@property (nonatomic,assign)    BOOL                        unlockButtonHidden;

@property (nonatomic,assign)    NSTimeInterval              autoCloseTimeout;

@end
