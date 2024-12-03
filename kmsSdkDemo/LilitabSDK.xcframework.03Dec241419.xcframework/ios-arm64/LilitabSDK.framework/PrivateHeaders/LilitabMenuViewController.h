//
//  LilitabMenuViewController.h
//
//  Created by Kevin Snow on 3/25/18.
//  Copyright © 2018 Lilitab LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LilitabMenuViewController : UIViewController

-(void) openMenuCenterOnButton:(UIButton*)menuButton;
-(void) closeMenu;

@property (nonatomic,assign)    BOOL    removeUpdateFirmwareButton;

+(NSNotificationName) dockStatus_Notification;

@end
