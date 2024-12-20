//
//  LilitabSDCAccessory.h
//
//  Created by Mike Voytovich on 3/15/22.
//  Copyright © 2022 Lilitab. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ExternalAccessory/ExternalAccessory.h>

// #import "LilitabAccessory_INTERNAL.h" //DO WE NEED THIS? (JSL 20230727)
#import "LilitabAccessory.h"

NS_ASSUME_NONNULL_BEGIN

@interface LilitabSDCAccessory : LilitabAccessory<LilitabDock, /*LilitabDockINTERNAL,*/ LilitabFirmwareUpdatable>
+ (id)sharedLilitabSDCAccessory;
-(void) postCommLost:(BOOL)forceResync; //07Feb24
-(void) updateBtnToLostDockCommResetSmartDock; //14Dec24
-(void) setDockFirmwareUUID:(NSString*)UUID; //15Dec24
@property (nonatomic,assign)    BOOL            hasHeartbeat;
@end

NS_ASSUME_NONNULL_END
