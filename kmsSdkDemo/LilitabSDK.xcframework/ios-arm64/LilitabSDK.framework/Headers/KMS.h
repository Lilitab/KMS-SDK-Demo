//
//  KMS.h
//  KMSSDK
//
//  Created by Kevin Snow on 11/19/17.
//  Copyright © 2017 Lilitab LLC. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <OSLog/OSLog.h>
#import <UIKit/UIKit.h>
#import <LilitabSDK/KMSServerView.h>
#import <LilitabSDK/KMSBars.h>
#import <LilitabSDK/KMSFirmwareUpdateView.h>

// Add BOOL property of "KMS-BLOCK-LOCATION-SERVICES" to app's info.plist to prevent location services
//#import <LilitabSDK-Swift.h>
//@class KMSWipedown

@interface KMS : NSObject

-(NSString*) enterpriseId;
-(NSString*) groupId;
-(NSString*) tabletId;
-(NSString*) dockId;
+(NSNotificationName) KMS_COORDINATES_CHANGED_Notification;         // KMS Coordinates changed notification

-(UIColor*) backgroundColor;
+(NSNotificationName) KMS_BACKGROUNDCOLOR_CHANGED_Notification;     // Background color changed notification

-(NSURLRequest*) homeUrlRequest;

-(void) openKmsServerView;

-(NSString*) startServices;
-(NSMutableDictionary<NSString*,id>*) whoAmI;
-(NSString*) showControls;
-(NSString*) hideControls;
-(NSString*) openPortal;
-(NSString*) userAuth;
-(NSString*) clearUser;

-(NSString*) dockPairingStatus;
-(NSMutableDictionary<NSString*,id>*) dockPairingInfo;
-(NSString*) dockUnlock;
-(NSString*) unlockButtonState;
-(NSDictionary*) dockStatus;
-(NSDictionary*) dockInfo;

-(NSString*) postMetric:(NSString*)metricTag value:(NSString*)metricVal;
//-(NSMutableDictionary<NSString*,id>*) getMetric:(NSString*)metricTag;
-(NSMutableDictionary<NSString*,id>*) getMetric:(NSString*)metricTag minPosix:(NSInteger)minPosix maxPosix:(NSInteger)maxPosix;

-(NSString*) configStore:(NSString*)configStore configValues:(NSDictionary<NSString*,id>*)configValues;
-(NSMutableDictionary<NSString*,id>*) configGet:(NSString*)configTag;

-(NSString*) datastoreStore;
-(NSString*) datastoreSearch;
-(NSString*) datastoreGet;
-(NSString*) datastoreDelete;

-(NSString*) postEvent;
-(NSString*) postEvent:(NSString*)eventMsg;
-(NSMutableDictionary<NSString*,id>*) geofenceStatus;
-(NSString*) wipedownNow;
-(NSMutableDictionary<NSString*,id>*) wipedownStatus;

-(NSDictionary*) getEmployeeNameForID:(NSError **)errorPtr;


-(NSURLRequest*) tabletRegistrationUrlRequest:(NSString*)regWizardNavigationReason;
-(NSURLRequest*) dockRegistrationUrlRequest;

-(void) setDockLaunchAppName:(NSString*)name;


+(NSNotificationName) NETWORK_REACHABILITY_CHANGED_Notification;
+(NSNotificationName) KMS_SERVICE_REACHABILITY_CHANGED_Notification;
+(NSNotificationName) HOMEPAGE_REACHABILITY_CHANGED_Notification;


+(KMS*) singleton;
@property (nonatomic,assign)    BOOL    enabled;    // once KMS is enabled, it cannot be stopped.
@property (nonatomic,assign)    BOOL    startServicesCalled;
@property (strong)    KMSServerView*    kmsServerView;
@property (strong) NSString* lastAuthUserID;
@property (strong) NSString* lastAuthUserName;
@property (strong) KMSBars* kmsBars;
@property (strong) KMSFirmwareUpdateView* firmwareUpdateView;
@property (nonatomic,assign)    NSString*    wipedownCleaningMode;



+(void) setSDKLicenseKey:(NSDictionary<NSString*,NSObject*>*)licenseObj;

@end
