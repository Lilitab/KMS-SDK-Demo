//
//  KMSMenuViewController.h
//  KMSSDK
//
//  Created by Kevin Snow on 3/25/18.
//  Copyright © 2018 Lilitab LLC. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface KMSMenuViewController : UIViewController

-(void) openMenuCenterOnButton:(UIButton*)menuButton;
-(void) closeMenu;

+(NSNotificationName) aboutApp_Notification;
+(NSNotificationName) dockStatus_Notification;
+(NSNotificationName) readerStatus_Notification;
+(NSNotificationName) printerStatus_Notification;
+(NSNotificationName) support_Notification;
+(NSNotificationName) connectBLE_Notification;
+(NSNotificationName) connectBLE_PairingStatusNotification;
+(NSNotificationName) connectBLE_PairingDisconnectConfirmNotification;
+(NSNotificationName) connectBLE_PairingDisconnectImmediateNotification;
+(NSNotificationName) connectBLE_ConnectNotFoundConfirmNotification;


@property (nonatomic,assign)    BOOL    removeUpdateFirmwareButton;

@end
