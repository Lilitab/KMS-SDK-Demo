//
//  LilitabDB.h
//  SmartDock
//
//  Created by Kevin Snow on 2/28/15.
//  Copyright (c) 2015-2018 Lilitab. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <LilitabSDK/LilitabSDK.h>
#import <LilitabSDK/SmartDockUser.h>


NS_ASSUME_NONNULL_BEGIN

@interface LilitabDB : NSObject
@property (assign)  BOOL isInitializingUsersList;

+(LilitabDB*) db;

+(LilitabDB*) singleton;

+(NSUInteger)       userCount;
+(NSInteger)        usersTimestamp;
+(NSInteger)        docksTimestamp;

-(SmartDockUser* _Nullable)   getUser:(NSString*)userId;
-(NSDictionary* _Nullable)    getDockFromLilitabDB:(NSString*)dockUUID;
-(NSDictionary* _Nullable)    getCurrentDock;

-(void) updateUsers:(NSArray*)users atTimestamp:(NSUInteger)timestamp;
-(void) updateDocks:(NSArray*)docks atTimestamp:(NSUInteger)docksTimestamp;

-(void) loadDockCache;

-(void) clearUserCache;
-(void) clearDockCache;
-(void) clearAllDBCaches;

//@property (strong)  NSMutableDictionary*        cacheDict;      // in memory user DB, current list of users is synced from KMSManager.userDict
//@property (strong)  NSMutableDictionary*        dockCacheDict;  // in memory dock DB, current list of docks is synced from KMSManager.groupDocksDict

@end

NS_ASSUME_NONNULL_END
