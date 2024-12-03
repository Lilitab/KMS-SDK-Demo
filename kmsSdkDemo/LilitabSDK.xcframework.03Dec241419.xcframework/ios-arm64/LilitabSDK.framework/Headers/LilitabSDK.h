//
//  LilitabSDK.h
//  LilitabSDK
//
//  Created by Kevin Snow on 3/7/21.
//

#import <Foundation/Foundation.h>

//! Project version number for LilitabSDK.
FOUNDATION_EXPORT double LilitabSDKVersionNumber;

//! Project version string for LilitabSDK.
FOUNDATION_EXPORT const unsigned char LilitabSDKVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <LilitabSDK/PublicHeader.h>

#import <LilitabSDK/LilitabAccessories.h>
#import <LilitabSDK/LilitabAccessory.h>
#import <LilitabSDK/LilitabAccessories+AccessoryGetters.h>
#import <LilitabSDK/LilitabSignatureView.h>
#import <LilitabSDK/LilitabSignatureOverlayView.h>
#import <LilitabSDK/LilitabSwipeAnimationView.h>
#import <LilitabSDK/LilitabSwipeAnimationOverlayView.h>
#import <LilitabSDK/LilitabBLEHelpOverlayView.h>
#import <LilitabSDK/LilitabMenuButton.h>
#import <LilitabSDK/LilitabWebView.h>

#import <LilitabSDK/CaptureViewController.h>
#import <LilitabSDK/CaptureOverlay.h>

#import <LilitabSDK/KMS.h>
#import <LilitabSDK/KMSGeolocateButton.h>
#import <LilitabSDK/KMSHelpButton.h>
#import <LilitabSDK/KMSHomeButton.h>
#import <LilitabSDK/KMSMenuButton.h>
#import <LilitabSDK/KMSUnlockButton.h>
#import <LilitabSDK/KMSWebView.h>
#import <LilitabSDK/KMSServerView.h>
#import <LilitabSDK/KMSLockIconView.h>
#import <LilitabSDK/KMSFirmwareUpdateView.h>
#import <LilitabSDK/KMSDockStatusViewController.h>
#import <LilitabSDK/KMSReaderStatusViewController.h>
#import <LilitabSDK/KMSGeolocateMenuViewController.h>
#import <LilitabSDK/KMSPinpadViewController.h>
#import <LilitabSDK/KMSPrinterStatusViewController.h>
#import <LilitabSDK/KMSBarsViewController.h>
#import <LilitabSDK/KMSBars.h> //JSL
#import <LilitabSDK/KMSManager.h> //JSL 06Dec23
#import <LilitabSDK/LilitabDB.h> //JSL 06Dec23
#import <LilitabSDK/AppleLocationService.h> //JSL 08Dec23

#import <LilitabSDK/BLEPairingStatus1ViewController.h>
#import <LilitabSDK/BLEPairingStatus2ViewController.h>
#import <LilitabSDK/BLEPairingStatus3ViewController.h>
#import <LilitabSDK/BLEPairingStatus4ViewController.h>
#import <LilitabSDK/BLEPairingStatus5ViewController.h>
#import <LilitabSDK/BLEPairingStatus6ViewController.h>
#import <LilitabSDK/BLEPairingStatus8ViewController.h>

#import <LilitabSDK/ConfirmFWUpdateController.h>

#import <LilitabSDK/BLEViewController.h>
#import <LilitabSDK/BLEDock.h>
#import <LilitabSDK/KMSMenuViewController.h>
//#import <LilitabSDK/KMSDoc
#import <LilitabSDK/LilitabSDCAccessory.h> //JSL 20230727
#import <LilitabSDK/KMSWipedown.h> //JSL 20230914
//#import <LilitabSDK/SDKLog.h> //JSL 20231026
#import <LilitabSDK/DockStatusViewController.h>
#import <LilitabSDK/FirmwareDownloader.h>
#import <LilitabSDK/BlockTimer.h>

@interface LilitabSDK : NSObject

+(NSString* _Nonnull) version;

+(void) setEnableSpeakerOverride:(BOOL)override;

//FOR TESTING: override speaker and mic in one place
+(void) setEnableSpeakerOverrideORIG:(BOOL)override;

//check to see if audio route has changed (not working as expected [7/30/2021 JSL])
//-(void)didSessionRouteChange:(NSNotification *_Nullable)notification;

+(void) selectBuiltInMicrophone;

//selectHeadsetMicrophone also has debug to list in/out audio sources
+(NSDictionary* _Nullable) selectHeadsetMicrophone;

+(NSDictionary* _Nullable) getAudioCurrentRouteInfo;


@end
