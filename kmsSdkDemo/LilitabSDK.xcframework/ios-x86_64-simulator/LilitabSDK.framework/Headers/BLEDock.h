//
//  BLEDock.h
//  LilitabSDK
//
//  Created by Mike Voytovich on 9/1/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef struct
{
    uint8_t     startMSB;
    uint8_t     startLSB;
    uint8_t     lengthMSB;
    uint8_t     lengthLSB;
    uint8_t     control;
    uint8_t     seqNum;
    uint8_t     ackSeqNum;
    uint8_t     sessionID;
    uint8_t     headerChecksum;
} iAP2_PacketHeader;

typedef struct
{
        //// Header ////
    uint8_t     startMSB;
    uint8_t     startLSB;
    uint8_t     lengthMSB;
    uint8_t     lengthLSB;
    uint8_t     control;
    uint8_t     seqNum;
    uint8_t     ackSeqNum;
    uint8_t     sessionID;
    uint8_t     headerChecksum;
        //// Payload ////
    uint8_t     eaSessionMSB;
    uint8_t     eaSessionLSB;
    uint8_t     string[1024];
    uint8_t     payloadChecksum;
} iAP2_ProtocolPacket;

typedef struct
{
        //// Header ////
    uint8_t     startMSB;
    uint8_t     startLSB;
    uint8_t     lengthMSB;
    uint8_t     lengthLSB;
    uint8_t     control;
    uint8_t     seqNum;
    uint8_t     ackSeqNum;
    uint8_t     sessionID;
    uint8_t     headerChecksum;
        //// Payload ////
    uint8_t     linkVersion;
    uint8_t     maxOutstandingPackets;
    uint8_t     maxPacketLenMSB;
    uint8_t     maxPacketLenLSB;
    uint8_t     retransmitTimeoutMSB;
    uint8_t     retransmitTimeoutLSB;
    uint8_t     cumACKTimeoutMSB;
    uint8_t     cumACKTimeoutLSB;
    uint8_t     maxRetransmit;
    uint8_t     maxCumACK;
    uint8_t     session1ID;
    uint8_t     session1Type;
    uint8_t     session1Version;
    uint8_t     session2ID;
    uint8_t     session2Type;
    uint8_t     session2Version;
    //uint8_t     session3ID;
    //uint8_t     session3Type;
    //uint8_t     session3Version;
    uint8_t     payloadChecksum;
} iAP2_LinkSynchPacket;

// FIXME: move this into a more appropriate place.  The equilavent is found in the Framework EAAccessoryManager.h
extern NSString * const SDCAccessoryDidConnectNotification;
extern NSString * const SDCAccessoryDidDisconnectNotification;

@interface BLEDock : NSObject

+ (id)sharedBLEDock;

- (NSString *) getBLEId;

// Primary API's called from UI

// returns TRUE if we have a BLE connection
- (BOOL) isConnected;

// returns TRUE if we haved a saved serial number
- (BOOL) isPaired;

- (BOOL) isBleOn;

// remove saved serial number, disconnect if connected
- (void) unPair;

- (void) setPairingMode:(BOOL)enable;


- (void) sendNusData:(NSData *)data;

- (void) echo:(NSString *)data
            success:(void(^)(NSDictionary* responseObject))success
            failure:(void(^)(NSDictionary* errObject))failure;

- (void) uart_send_string:(NSString *)data
            success:(void(^)(NSDictionary* responseObject))success
            failure:(void(^)(NSDictionary* errObject))failure;


- (void) send_paired_beep;

- (void) send_unlock_command;

- (void) send_data:(NSData *)data response:(void(^)(NSData* responseObject))response;

//uses callback
- (void) write:(NSMutableData *)data;

- (void) setReadDataCallback:(void(^)(NSData* inputData))cb;


// low-level resync via DKP command - repeatedly send command and look for "OK"
- (void) resyncDKP;


@end

NS_ASSUME_NONNULL_END
