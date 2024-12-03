//
//  KMSServerView.h
//  LilitabSDK
//
//  Created by John Lindstrom on 5/23/23.
//

#import <UIKit/UIKit.h>


@protocol KMSServerViewDelegate <NSObject>
@optional

-(bool) allowURI:(nonnull NSString*)uriString;
-(bool) handleCardSwipe:(nonnull NSDictionary<NSString*,NSObject*>*)swipeData;

@end




IB_DESIGNABLE
@interface KMSServerView : UIView

-(void) loadRequest:(NSDictionary<NSString*,NSObject*>*_Nullable)requestDict; //why is this not in KMSWebView????

//-(void) loadRequest:(NSDictionary<NSString*,NSObject*>*)requestDict; //why is this not in KMSWebView????

@property(nullable,nonatomic,weak)  id<KMSServerViewDelegate>  kmsDelegate;

@property (nonatomic,assign)    IBInspectable   BOOL    killBars;
@property (nonatomic,assign)    IBInspectable   BOOL    enableBars;

@property (nonatomic,assign)    IBInspectable   BOOL    enableActivityIndicator;

@property (nonatomic,assign)                    BOOL    animateActivityIndicator;

@property (readwrite,nonatomic,assign)    BOOL                            isWizardSession;

@end
