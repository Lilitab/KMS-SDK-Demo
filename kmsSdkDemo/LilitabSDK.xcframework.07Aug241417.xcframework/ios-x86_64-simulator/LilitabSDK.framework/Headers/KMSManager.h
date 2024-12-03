//
//  KMSManager.h
//  SmartDock
//
//  Created by MONIQUE BARBANSON on 8/27/15.
//  Copyright (c) 2015-2018 Lilitab. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "LilitabAPIClient.h"
#import "SmartDockUser.h"




// Pretend the dock is connected, for debugging (should be a user setting if used for demo!)
//#define SIMULATE_DOCK_CONNECTED

@class KMSAdminViewController;
@class SmartDockUser;
@class CloudConnection;
@class GeofenceManager;


NS_ASSUME_NONNULL_BEGIN

extern NSString * const kWriteUsersListToLocalCacheNotification;
extern NSString * const kDidUpdateUsersListFromServiceNotification;
extern NSString * const kWriteDocksListToLocalCacheNotification;
extern NSString * const kDBVerifyUserPinCacheNotification;

extern NSString * const kUpdateDockIDNotification;
extern NSString * const kAPIAuthTokenDidUpdateNotification;
extern NSString * const kRenewAPIAuthTokenNotification;
extern NSString * const kRenewAboutToExpireTokenNotification;
extern NSString * const kDidRenewAuthTokenNotification;

extern NSString * const kDockUnlockedEventNotification;
extern NSString * const kFirmwareUpdatedEventNotification;
extern NSString * const kUpdateBatteryTimerNotification;
extern NSString * const kUpdateDockStatusTimerNotification;

extern NSString * const kUpdateApprovedDomainsNotification;
extern NSString * const kTabletRenamedNotification;
extern NSString * const kUpdateShowMenuButtonNotification;
extern NSString * const kUpdateDockLockUINotification;
extern NSString * const kUpdateCoordinatesDisplayNotification;

//TODO: rename this to SDC?
extern NSString * const kBLEPairingUnsuccessfulNotification;
extern NSString * const kBLEPairingSuccessfulNotification;

extern NSString * const kBatteryChargingState;
extern NSString * const BATTERY_STATE_UNKNOWN;
extern NSString * const BATTERY_STATE_UNPLUGGED;
extern NSString * const BATTERY_STATE_CHARGING;
extern NSString * const BATTERY_STATE_FULL;

extern NSString * const kPreviousTabletIDKey;
extern NSString * const kPreviousEnterpriseIDKey;
extern NSString * const kPreviousGroupIDKey;
extern NSString * const kPreviousTabletHandleKey;
extern NSString * const kGroupUserPINKey;

extern NSString * const KMSGeofenceRadiusPrefsKey;
extern NSString * const KMSLocationUpdateIntervalPrefsKey;
extern NSString * const KMSGeofenceTestIntervalPrefsKey;
extern NSString * const KMSBatteryStatusUpdateIntervalPrefsKey;
extern NSString * const KMSDockStatusUpdateIntervalPrefsKey;

extern NSString *const DOCK_ALREADY_REGISTERED_URL;

extern NSString * const kDataHandle;
extern NSString * const kCenteredOnDockParameterKey;

extern NSString * const kDockEventTypeKey;


typedef enum {
    unknown = -1,
    notReachable = 0,
    reachable = 1
} ReachabilityResult;





@interface KMSManager : NSObject

    // KMSManager
@property (nonatomic, copy) NSString *urlScheme;
@property (nonatomic, copy) NSString *hostName;
@property (nonatomic, copy) NSString *groupAdminURLFormat;
@property (nonatomic, copy) NSString *adminExitURL;
@property (nonatomic, copy) NSString *regWizardURL;
@property (nonatomic, copy) NSString *regCompleteURL;
@property (nonatomic, copy) NSString *regExitURL;
@property (nonatomic, copy) NSString *dockWizardURL;
@property (nonatomic, copy) NSString *dockWizardCompleteURL;
@property (nonatomic, copy) NSString *dockUnlockOnlyURL;
//@property (nonatomic, copy) NSString *dockRegisteredToCoordinatesURL;
@property (nonatomic, copy) NSString *sessionTimeoutURL;
@property (nonatomic, copy) NSString *geofenceStartedURL;
@property (nonatomic, copy) NSString *geofenceDroppedURL;
@property (nonatomic, copy) NSString *tabletLeftGroupURL;
@property (nonatomic, copy) NSString *tabletIDChangedURL;

    // current pin pad user
@property (nonatomic,strong)    SmartDockUser*  currentUser;
@property (nonatomic,assign)    BOOL    openedViaLilitabSDK;
@property (nonatomic,assign)    BOOL    doRegistrationWizard;
@property (nonatomic,assign)    BOOL    coordinatesValidationDone;
@property (nonatomic,assign)    BOOL    dockNeverRegistered;

@property (nonatomic,strong)    GeofenceManager*    geofence;
@property (nonatomic,readonly,nullable)  NSDictionary*       tabletDetails;

@property (nonatomic,strong)    NSString *passThroughUrl;

+(KMSManager*) singleton;

// Preferences
+ (NSDictionary*) KMSDefaultPreferencesValues;
+ (UIColor*) backgroundColorFromSettings;

    // reachability
-(ReachabilityResult) isServiceReachable;
-(ReachabilityResult) isInternetReachable;

-(void) goToGroupAdminPage;
-(void) showSupportPage;
-(void) goToRegWizard:(NSString*)regwizardNavigationReason;
-(void) goToDockRegWizard;
-(void) refreshGroupAdminPage;

- (NSDictionary *)queryParametersFromQueryString:(NSString*)queryString;

- (NSString *)getPortalURL;


@property (nonatomic,readonly) NSString*  keychainEnterpriseID;
@property (nonatomic,readonly) NSString*  keychainGroupID;
@property (nonatomic,readonly) NSString*  keychainTabletID;
@property (nonatomic,readonly) NSString*  keychainGroupHandle;
@property (nonatomic,readonly) NSString*  keychainTabletHandle;
@property (nonatomic,readonly) NSString*  keychainTabletUUID;
@property (nonatomic,readonly) NSString*  keychainJamfToken;
@property (nonatomic,readonly) NSString*  keychainJamfUDID;


    // tablet and tablet registration
@property (nonatomic,strong)    NSString*   settingsEnterpriseID;
@property (nonatomic,strong)    NSString*   settingsGroupID;
@property (nonatomic,strong)    NSString*   settingsTabletID;


-(BOOL) areSettingsCoordinatesEmpty;
-(BOOL) areKeychainCoordinatesEmpty;
-(BOOL) areSettingsCoordinatesComplete;
-(BOOL) areKeychainCoordinatesComplete;
-(void) copyTabletCoordinatesFromKeychainToSettings;
-(BOOL) tabletCoordinatesMatch;
-(void) updateTabletWithCoordinates:(NSDictionary*)tabletData;

+(NSString*) deviceName;

@property (nonatomic, readonly) NSString*   appleDeviceUUID;

@property (nonatomic, strong) NSString*     inMemoryTokenTimestamp;
@property (nonatomic, strong) NSString*     inMemoryToken;

-(void) keychainWriteTabletUUID;
-(BOOL) isTabletFullyValidated;
-(BOOL) needsTabletRegistration;
-(BOOL) needsDockRegistration;

    // Battery State & Level handling
-(void) initializeBatteryStatus;
-(void) updateBatteryStatus;
-(void) updateBatteryStatus:(successBlockType _Nullable)success failure:(failureBlockType _Nullable)failure;

    // dictionary of current group users indexed by userID
@property (strong)  NSMutableDictionary* userDict;

- (void) initialActiveScreen;
- (BOOL) nextDockValidationAction;
- (void) nextTabletValidationAction;
- (void) normalAppStartupSequence;

-(void) executeFullLaunchSequence;  //TODO: remove this, no need to expose this method (but test first) JSL
//JSL
-(void) configure;
    
-(void) applicationDidBecomeActive:(NSNotification*)notification; //14Jun24
    
-(void) postHomeRequest;
-(void) postDockWizardReqest;
-(void) postTabletRegistrationReqest:(NSString*)registrationNavigationReason;
    
    
    // dock
@property (nonatomic,readonly)  NSDictionary*               dockDetails;           // current dock details from service

@property (nonatomic,strong)    NSMutableDictionary*        groupDocksDict;         // dock list for current group

@property (nonatomic,strong)    NSTimer*                    loginPromptTimer;
@property (nonatomic,assign)    BOOL                        tokenAboutToExpire;

@property (nonatomic,assign)    BOOL                        hasExpiredAuthorizationToken;

@property (nonatomic,assign)    BOOL                        enterpriseConfigChanged;


-(void) enterUnlockOnlyModeOnDock:(NSString*)dockUDID;
-(BOOL) inUnlockOnlyMode;
-(void) clearUnlockOnlyMode;
-(BOOL) isInDockWizardMode; //JSL 05Mar24
-(void) clearEnteredDockWizardMode; //JSL 05Mar24
-(void) clearUnlockOnlyModeForMissingUUIDS:(NSArray*)docksArray; //JSL 05Mar24

-(void) turnOnGeofence:(NSString*)centerOnDockUUID;
-(void) turnOffGeofence;

@property (nonatomic,readonly)  BOOL                        isTabletOnHomeDock;
@property (nonatomic,strong)    NSString*                   homeDockUUID;       // dockUUID of dock geofence is centered on if any

-(BOOL) dockByUUIDFromDockCache:(NSString *)UUIDStr;

-(BOOL) dockExistsInCache:(NSDictionary*)dockInfo;

@property (nonatomic,readonly)  BOOL        isFlashingFirmware;
@property (nonatomic,strong)    NSString*   dockFirmwareVersion;
-(void) testFirmwareUpdate;

-(void) monitorHomepage;

@end

NS_ASSUME_NONNULL_END
