//
//  KMSWipedown.h
//  LilitabSDK
//
//  Created by Kevin Snow on 3/26/20.
//  Copyright © 2020 Lilitab. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN


@interface KMSWipedown : NSObject

@property (nonatomic,readonly)  BOOL                showAlert;
@property (nonatomic,readonly)  NSTimeInterval      cleaningInterval;

@property (nonatomic,readonly)  BOOL                audioAlert;
@property (nonatomic,readonly)  BOOL                getPIN;
@property (nonatomic,readonly)  NSString*           instructionsURL;

@property (nonatomic,readonly)  BOOL                snoozeAllowed;
@property (nonatomic,readonly)  NSTimeInterval      snoozeInterval;

+(NSNotificationName) showWipedownUpdatedNotificationName;
+(NSNotificationName) snoozeWipedownUpdatedNotificationName;
+(NSNotificationName) URLWipedownUpdatedNotificationName;

-(void) updateFromServer:(NSDictionary<NSString*,NSString*>*)data;

@end

NS_ASSUME_NONNULL_END
