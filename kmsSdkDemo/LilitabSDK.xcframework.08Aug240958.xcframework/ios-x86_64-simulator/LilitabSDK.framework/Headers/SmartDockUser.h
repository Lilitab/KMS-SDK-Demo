//
//  SmartDockUser.h
//  SmartDock
//
//  Created by Kevin Snow on 3/1/15.
//  Copyright (c) 2015-2018 Lilitab. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface SmartDockUser : NSObject 

@property (nonatomic, copy)      NSString*   userID;
@property (nonatomic, copy)      NSString*   userName;
@property (nonatomic, copy)      NSString*   userRole;
@property (nonatomic, copy)      NSString*   userPermission;
@property (nonatomic, copy)      NSString*   userEmail;
@property (nonatomic, copy)      NSString*   userPhone;
@property (nonatomic, copy)      NSString*   userHandle;
@property (readonly) BOOL        newPinFlag;

-(NSDictionary<NSString*,NSString*>*) getStorageDict;

    // Resetting pin nil forces newPinFlag;
-(void) resetPin:(NSString*)newPin;

+(NSString *)digestFromPin:(NSString *)inputPin userID:(NSString *)userID;

-(BOOL) testAgainstPin:(NSString*)inputPin;

-(BOOL) hasAdminPermission;

-(BOOL) hasOwnerPermission;

-(BOOL) hasManagerPermission;

-(id) initWithDictionary:(NSDictionary*)userData updatePin:(BOOL)updatePin;

+ (BOOL)saveHashedPin:(NSString *)pin
             withSalt:(NSString *)salt
              forUser:(NSString *)userID;

+ (BOOL)saveDigest:(NSString *)digest
           forUser:(NSString *)userID;

+ (NSString *)findHashedPinByUserID:(NSString *)userID;
+ (NSString *)findDigestByUserID:(NSString *)userID;

+ (BOOL)updatePinsForUsers:(NSArray*)users;

+ (void)clearAllPins;

+ (NSString *)extractSaltFromDigest:(NSString *)digest;

+ (NSString *)extractHashFromDigest:(NSString *)digest;

+ (NSString *)generateSalt256;

@end
