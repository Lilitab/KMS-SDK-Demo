//
//  AppleLocationService.h
//  SmartDock
//
//  Created by Kevin Snow on 3/5/17.
//  Copyright © 2017 Lilitab. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>



#define LOCATION_SERVICES_DENIED    @"denied"
#define LOCATION_SERVICES_ACTIVE    @"active"
#define LOCATION_SERVICES_PENDING   @"pending"



extern NSString* _Nonnull const kAppleLocationServiceStateUpdateNotification;
extern NSString* _Nonnull const kAppleLocationServiceErrorNotification;



@interface AppleLocationService : NSObject

@property (nonatomic,readonly)          BOOL            isActive;
@property (nonatomic,readonly)  CLLocation* _Nullable   currentLocation;

@property (nonatomic,assign)            NSTimeInterval  algorithmUpdateInterval;

@property (nonatomic,readonly,nonnull)  NSString*       locationServicesStateForCloud;

@property (nonatomic,readonly)          BOOL            canBackground;
@property (nonatomic,readonly)     NSString* _Nullable  errorMessage;

-(void) checkStatus;

+(nullable AppleLocationService*) singleton;

@end
