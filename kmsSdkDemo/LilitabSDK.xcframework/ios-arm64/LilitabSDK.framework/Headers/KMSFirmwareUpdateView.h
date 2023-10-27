//
//  KMSFirmwareUpdateView.h
//  KMSSDK
//
//  Created by Kevin Snow on 1/17/18.
//  Copyright © 2018 Lilitab LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface KMSFirmwareUpdateView : UIView

+(NSNotificationName) SHOW_PROGRESS_Notification;
+(NSNotificationName) UPDATE_PROGRESS_Notification;
+(NSNotificationName) HIDE_PROGRESS_Notification;

@end
