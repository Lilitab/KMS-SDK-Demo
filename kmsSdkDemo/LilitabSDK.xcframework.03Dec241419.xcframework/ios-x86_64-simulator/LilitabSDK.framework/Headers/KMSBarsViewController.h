//
//  KMSBarsViewController.h
//  KMS
//
//  Created by Kevin Snow on 10/28/17.
//  Copyright © 2017 Lilitab LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol KMSUnlockButtonDelegate;

@interface KMSBarsViewController : UIViewController

-(void) show;
-(void) hide;

@property (weak, nonatomic) IBOutlet NSLayoutConstraint *menuButtonLeadingConstraintOutlet;

@property (nonatomic,strong)    id<KMSUnlockButtonDelegate> unlockButtonDelegate;
@property (nonatomic,assign)    BOOL                        unlockButtonHidden;

@property (nonatomic,readonly)  NSTimeInterval              autoCloseTimeout;

+(NSNotificationName) resetBarTimer_Notification;
+(void) sendResetBarTimerNotification;
+(void) sendResetBarTimerNotificationWithInterval:(NSTimeInterval)newInterval;

+(NSNotificationName) cancelBarTimer_Notification;
+(void) sendCancelBarTimerNotification;

+(NSNotificationName) showControlsFromServer_Notification;
+(void) showControlsFromServer:(BOOL)show;

+(NSNotificationName) showControlsFromSettings_Notification;
+(void) showControlsFromSettings:(BOOL)show;

@end
