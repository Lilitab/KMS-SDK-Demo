//
//  LilitabAPIClient.h
//  SmartDock
//
//  Created by MONIQUE BARBANSON on 10/16/15.
//  Copyright © 2015 Lilitab. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>
#import "AFNetworking.h"

    // service URLs
extern NSString * const KMSURLScheme;
extern NSString * const KMSURLSchemeDev;

    // HTTP Verbs
extern NSString * const kPOSTMethod;
extern NSString * const kPUTMethod;

extern NSString * const KMSSupportURL;
extern NSString * const kLilitabMetricJSAPI;
extern NSString * const kLilitabAuthenticationCompleteURL;
extern NSString * const kRevertToOldCoordinatesURL;
extern NSString * const kRegisterExistingTabletErrorURL;
extern NSString * const kRegistrationFailedURL;
extern NSString * const kFailureExplanationKey;

extern NSString * const kContinueSilentLoginURL;
extern NSString * const kRegistrationFinishedURL;
extern NSString * const kEnterpriseID;
extern NSString * const kGroupID;
extern NSString * const kTabletID;
extern NSString * const kDeviceUUID;
extern NSString * const kDockID;
extern NSString * const kLilitabAPIDockUDID;
extern NSString * const kNewEnterpriseID;
extern NSString * const kNewGroupID;
extern NSString * const kNewTabletID;
extern NSString * const kNewDeviceUUID;
extern NSString * const kUserID;

    // HTTP headers
extern NSString * const kAuthorizationHeaderKey;
extern NSString * const kAuthorizationTokenHeaderKey;
extern NSString * const kTabletWasRenamedHeaderKey;
extern NSString * const kTokenAboutToExpireHeaderKey;
extern NSString * const kEnterpriseConfigurationChangedHeaderKey;

    // API parameter keys
extern NSString * const kLilitabAPIPOSIXKey;
extern NSString * const kLilitabAPIGMTOffsetKey;
extern NSString * const kNewFWVersionParameterKey;
extern NSString * const kPreviousFWVersionParameterKey;
extern NSString * const kLilitabAPITimestampParameterKey;
extern NSString * const kAlertMsgParameterKey;
extern NSString * const kLilitabAPITypeKey;
extern NSString * const kLilitabAPIChargingKey;
extern NSString * const kLilitabAPIStateKey;

extern NSString * const kUsersTimestampKey;
extern NSString * const kDocksTimestampKey;

extern NSString * const kTabletHandle;
extern NSString * const kDockHandle;
extern NSString * const kUserHandle;

extern NSString * const kLilitabAPIGeofenceStatusKey;
extern NSString * const kLilitabAPIGeofenceRadiusKey;

extern NSString * const kLilitabAPITabletHandleKey;
extern NSString * const kLilitabAPITabletIDKey;
extern NSString * const kLilitabAPIUserKey;
extern NSString * const kLilitabAPIHashedPinKey;
extern NSString * const kLilitabAPINewPinFlag;

extern NSString * const kTabletHomeLatitude;
extern NSString * const kTabletHomeLongitude;
extern NSString * const kTabletHomeAddress;
extern NSString * const kInsideGeofenceFlag;

extern NSString * const kLilitabAPIDockFWVersionKey;
extern NSString * const kLilitabAPIDockFWVersionUpdateKey;

//extern NSString * const kNetworkStatusUpdateFrequency;
extern NSString * const kDockStatusUpdateFrequency;

extern NSString * const kPostTabletChargingStatusAPI;


typedef void (^failureBlockType)(NSURLSessionDataTask*, NSError* error);
typedef void (^successBlockType)(NSURLSessionDataTask*, id responseObject);

@class SmartDockUser;






@interface LilitabAPIClient : AFHTTPSessionManager

+(LilitabAPIClient*) sharedClient;

+(void) addPosixTimestampTo:(NSMutableDictionary*)mDict;

+(NSString*) KMSHostName;
+(NSString*) LilitabBaseURLString;

- (void)initializeAuthorizationHeader;

    // dock APIs

-(NSMutableURLRequest*) postRequestForCachedDockInfo:(NSDictionary*)dataDict;
-(NSMutableURLRequest*) postRequestForCachedMetric:(NSMutableDictionary*)paramDict;

    // tablet charge API
-(NSMutableURLRequest*) postRequestForBatteryStatus:(NSDictionary*)statusDict;

    // tablet APIs
-(void) updateTablet:(NSMutableDictionary*)tabletDict
          updatePath:(NSString*)urlPath
             success:(void(^)(NSURLSessionDataTask* task, id responseObject))success
             failure:(void(^)(NSURLSessionDataTask* task, NSError* error))failure;
- (NSMutableURLRequest*)putRequestForTabletUpdate:(NSMutableDictionary*)tabletDict
                                        updatePath:(NSString*)urlPath;


    // Location Support
- (void)updateLocationServicesState:(void(^)(NSError* error))completionBlock;
- (void)recordHomeLocation:(CLLocation*) coordinate
            withCompletion: (void(^)(NSError* error)) completionBlock;
- (void)recordLocationUpdate:(CLLocation*) coordinate
                     options:(NSDictionary*)options
              withCompletion: (void(^)(NSError* error)) completionBlock;

-(NSMutableURLRequest*)requestForHomeLocation:(CLLocation*)loc;
-(NSMutableURLRequest*)requestForUpdateLocationServicesState:(CLLocation*)loc;
-(NSMutableURLRequest*)requestForUpdateCurrentLocation:(CLLocation*)loc;

    // users
-(void) putUser:(SmartDockUser*)user
          success:(void(^)(NSURLSessionDataTask *task, id responseObject))success
          failure:(void(^)(NSURLSessionDataTask *task, NSError *error))failure;

-(void) putUser:(SmartDockUser*)user
          withPin:(NSString *)pin
          success:(void(^)(NSURLSessionDataTask *task, id responseObject))success
          failure:(void(^)(NSURLSessionDataTask *task, NSError *error))failure;

-(void) verifyUserTempDigest:(NSString *)digest
                      userID:(NSString *)userID
                     success:(void (^)(void))successBlock
                     failure:(void (^)(void))failureBlock;

-(void) verifyUserPin:(NSString *)pin
               userID:(NSString *)userID
              success:(void (^)(NSDictionary *responseDict))successBlock
              failure:(void(^)(NSURLSessionDataTask *task, NSError *error))failure;

+(NSString*) apiURLStringforUser:(SmartDockUser*)user groupID:(NSString *)groupID enterpriseID:(NSString *)enterpriseID;

    // tabletRenamed
- (void)tabletRenamedCoordinates:(void(^)(NSURLSessionDataTask *task, id responseObject))success
                         failure:(void(^)(NSURLSessionDataTask *task, NSError *error))failure;

    // updateTabletUUID
-(void) updateTabletUUIDSuccess:(void(^)(NSURLSessionDataTask *task, id responseObject))success
                        failure:(void(^)(NSURLSessionDataTask *task, NSError *error))failure;

    // GetFirmware
-(void) getKMSFirmware:(NSString*)UDID
               success:(void(^)(NSURLSessionDataTask *task, id responseObject))success
               failure:(void(^)(NSURLSessionDataTask *task, NSError *error))failure;

    // metrics
-(void) postMetric:(NSString*)metricTag
             value:(NSString*)metricValue
    withCompletion:(void(^)(NSError* error))completionBlock;

- (void)incrementVisitorsByCount:(NSString *) count
                  withCompletion: (void(^)(NSError* error)) completionBlock;

- (void)incrementClicksByCount:(NSString *) count
                   withCompletion: (void(^)(NSError* error)) completionBlock;

+ (void)addTabletHardwareParameters:(NSMutableDictionary *)parameters;
+ (void)addKeychainTabletCoordinates:(NSMutableDictionary *)parameters useOldKey:(BOOL)useOldKey;
+ (void)addSettingsTabletCoordinates:(NSMutableDictionary *)parameters;
+ (void)addTabletRegistrationParameters:(NSMutableDictionary *)parameters with:(NSString*)registrationNavigationReason;
+ (void)addTabletHandleParameter:(NSMutableDictionary *)parameters;
+ (void)addDockHandleParameter:(NSMutableDictionary *)parameters;
+ (void)addUserHandleParameter:(NSMutableDictionary *)parameters;
+ (void)addDockUUIDParameter:(NSMutableDictionary *)parameters;
+ (void)addApplicationParameters:(NSMutableDictionary *)parameters;


+(NSString*) posixTimestamp;

+(void) alertAuthenticationError;

@property (nonatomic,readonly)   NSUInteger  reponseCount401;

-(void) increment401ResponseCount;

-(NSMutableDictionary*) updateParametersWithCurrentTabletCoordinates:(NSDictionary*)parameters;

@property (nonatomic,strong)    NSMutableDictionary*    chargePayload;



@property (nonatomic,strong)    NSDate*                 readerStatusLastDate;
@property (nonatomic,strong)    NSDictionary*           readerStatusLastCargo;

@end




@interface LilitabAPIClient (PostCCSwipe)

-(void) postCCSwipe:(NSDictionary*)swipeData
            success:(void(^)(NSURLSessionDataTask *task, NSDictionary* responseDict, NSString* transactionId))success
            failure:(void(^)(NSURLSessionDataTask *task, NSError *error))failure;

@end



@interface LilitabAPIClient (PostDataStore)
-(void) postDataStore:(NSDictionary<NSString*,id>*)dict
              success:(void(^)(NSDictionary* responseObject))success
              failure:(void(^)(NSDictionary* errObject))failure;
@end


@interface LilitabAPIClient (PostBLE)
-(void) postBLE:(NSDictionary<NSString*,id>*)dict
              success:(void(^)(NSDictionary* responseObject))success
              failure:(void(^)(NSDictionary* errObject))failure;
@end


@interface LilitabAPIClient (CallAPIEndpoint)
-(void) callAPIEndpoint:(NSString*)endpoint
             parameters:(NSDictionary*)paramDict
                 method:(NSString*)method
                success:(void(^)(NSURLSessionDataTask* task, id responseObject))success
                failure:(void(^)(NSURLSessionDataTask* task, NSError* error))failure;
@end


@interface LilitabAPIClient (CommonSuccess)
-(void) commonSuccess:(NSURLSessionDataTask*)task responseObject:(id)responseObject;
@end


@interface LilitabAPIClient (CommonFailure)
-(void) commonFailure:(NSURLSessionDataTask*)task error:(NSError*)error success:(successBlockType)success failure:(failureBlockType)failure;
@end


@interface LilitabAPIClient (PostSwipeStatus)
-(void) postSwipeStatus;
@end



@interface LilitabAPIClient (PostJAMFRegistration)
-(void) postJAMFRegistration:(NSDictionary*)dataDict
                     success:(void(^)(NSURLSessionDataTask* task, id responseObject))success
                     failure:(void(^)(NSURLSessionDataTask* task, NSError* error))failure;
@end



@interface LilitabAPIClient (PostDockStatus)
-(void) postDockStatus:(NSMutableDictionary*)statusDict
                  uuid:(NSString*)dockUUID
               success:(void(^)(NSURLSessionDataTask* task, id responseObject))success
               failure:(void(^)(NSURLSessionDataTask* task, NSError* error))failure;

-(NSMutableURLRequest*) postRequestForCachedDockStatus:(NSDictionary*)statusDict;

@end



@interface LilitabAPIClient (PostReaderStatus)
-(void) postReaderStatus:(NSDictionary*)readerStatus
                 success:(void(^)(NSURLSessionDataTask* task, id responseObject))success
                 failure:(void(^)(NSURLSessionDataTask* task, NSError* error))failure;
@end

@interface LilitabAPIClient (PostDebugInfo)
-(void) postDebugInfo:(NSDictionary*)debugDict
              success:(void(^)(NSURLSessionDataTask* task, id responseObject))success
              failure:(void(^)(NSURLSessionDataTask* task, NSError* error))failure;
-(void) postDebugInfoChannel2:(NSDictionary*)debugDict
                 success:(void(^)(NSURLSessionDataTask* task, id responseObject))success
                 failure:(void(^)(NSURLSessionDataTask* task, NSError* error))failure;
@end


@interface LilitabAPIClient (PostDockInfo)
-(void) postDockInfo:(NSDictionary*)dataDict
             success:(void(^)(NSURLSessionDataTask *task, id responseObject))success
             failure:(void(^)(NSURLSessionDataTask *task, NSError *error))failure;
@end


@interface LilitabAPIClient (PostChargingStatus)
-(void) updateChargeStatusPayload:(NSDictionary*)data;
-(void) postChargingStatus:(NSDictionary*)statusDict
                   success:(void(^)(NSURLSessionDataTask* task, id responseObject))success
                   failure:(void(^)(NSURLSessionDataTask* task, NSError* error))failure;
@end


@interface LilitabAPIClient (PostEventWithType)

-(void) postEventWithType:(NSString*)eventType
               parameters:(NSMutableDictionary*)parameters
                  success:(void(^)(NSURLSessionDataTask* task, id responseObject))success
                  failure:(void(^)(NSURLSessionDataTask* task, NSError* error))failure;

-(NSMutableURLRequest*) postRequestForCachedEvent:(NSMutableDictionary*)paramDict;

@end


typedef NS_ENUM(NSInteger, DockAlertMessage) {
    dockBoot,               //Alert: Dock rebooted
    dockWallPowerLost,      //Alert: Wall power unplugged
    dockWallPowerRestored,  //Alert: Wall power restored
    dockCommLost,           //Alert: Dock communication lost
    dockCommRestored,       //Alert: Dock communication restored
    dockStallUnlocking,     //Alert: Stall when unlocking
    dockStallLocking,       //Alert: Stall when locking
    dockFirmwareUpdate      //Alert: Dock firmware updated to #.##
};

@interface LilitabAPIClient (PostDockAlert)

-(void) postDockAlert:(DockAlertMessage)msg;

-(void) postDockAlert:(DockAlertMessage)msg
           parameters:(NSMutableDictionary*)parameters
              success:(void(^)(NSURLSessionDataTask* task, id responseObject))success
              failure:(void(^)(NSURLSessionDataTask* task, NSError* error))failure;

-(void)notifyEventDelegateOfDockAlert:(NSString*)alertMsg;

@end
