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

//26Jul24
-(void) flashFirmwareImage:(NSString*)firmwareFilename;

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

//26Jul24 (make property public)
@property (nonatomic,strong)                NSString*           firmwareSelected;

@property (nonatomic,assign)    BOOL    removeUpdateFirmwareButton;

@end
