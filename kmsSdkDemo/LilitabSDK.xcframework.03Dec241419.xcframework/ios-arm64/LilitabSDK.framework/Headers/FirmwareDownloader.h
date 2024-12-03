//
//  FirmwareDownloader.h
//  MynaBayLib
//
//  Created by Kevin Snow on 9/19/14.
//  Copyright (c) 2014-2018 Lilitab. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface FirmwareDownloader : NSObject

-(NSData*) getFirmware:(NSString*)filename;                                                             // Returns NSData of firmware, included embedded

-(NSArray<NSString*>*) downloadedFirmware;                                                              // Returns array of downloaded binary filenames.
-(NSArray<NSString*>*) allFirmware;                                                                     // Returns array of embedded anddownloaded binary filenames.

-(void) downloadLatestWithCompletion:(void (^)(NSDictionary<NSString*,NSString*>* result))completion;   // Download the latest ROM. 

-(void) removeDownloads;                                                                                // Remove all downloaded firmware images.

@end
