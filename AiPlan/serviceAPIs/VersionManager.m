//
//  VersionManager.m
//  Portal-sx
//
//  Created by wuyoujian on 2017/6/29.
//  Copyright © 2017年 Asiainfo. All rights reserved.
//

#import "VersionManager.h"
#import <AIBase/AIBase.h>
#import "AIUpdateVersionHTTPRequest.h"
#import "AIHTTPURLSession.h"
#import "AppDelegate.h"
#import <objc/runtime.h>

static NSString *const kAIAlertViewBlockKey = @"kAIAlertViewBlockKey";
@interface UIAlertView (AIAlertViewBlock)
- (void)handlerClickedButton:(void (^)(NSInteger btnIndex))aBlock;
@end
@implementation UIAlertView (AIAlertViewBlock)
- (void)handlerClickedButton:(void (^)(NSInteger btnIndex))aBlock {
    self.delegate = self;
    objc_setAssociatedObject(self,(__bridge const void *)kAIAlertViewBlockKey, aBlock, OBJC_ASSOCIATION_COPY);
}
- (void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex {
    void (^block)(NSInteger btnIndex) = objc_getAssociatedObject(self,(__bridge const void *)kAIAlertViewBlockKey);
    if (block) block(buttonIndex);
}
@end


@implementation VersionManager

+ (void)checkVersion {

    GlobalCfg *cfg = [GlobalCfg SharedObj];
    NSString  *versionString = [cfg attr:@"online.versionURL"];
    // 判断是否可以联网
    NSURL *URL = [NSURL URLWithString:versionString];
    Reachability *reach = [Reachability reachabilityWithHostName:URL.host];
    if (![reach isReachable]) {
        return;
    }
    
    AIUpdateVersionHTTPRequest *requestObj = [[AIUpdateVersionHTTPRequest alloc] init];
    requestObj.url = versionString;
    
    NSURLRequest *httpRequest = [requestObj toHTTPRequest];
    [[AIHTTPURLSession sharedHTTPURLSession] sendHTTPRequest:httpRequest completionHandler:^(NSData *data, NSURLResponse *response, NSError *error){
        //
        NSHTTPURLResponse *res = (NSHTTPURLResponse*)response;
        if (res.statusCode == 200 && data) {
            NSError * error = nil;
            
            NSDictionary* jsonDictionary = [NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingAllowFragments error:&error];
            NSString *platform = jsonDictionary[@"platform"];
            if ([platform isEqualToString:@"ios"]) {
                NSString *versionNumber = jsonDictionary[@"versionNumber"];
                NSString *versionURL = jsonDictionary[@"versionURL"];
                NSString *locationVersion = [cfg attr:@"version"];;
                if (![versionNumber isEqualToString:locationVersion]) {
                    dispatch_async(dispatch_get_main_queue(), ^{
                        NSString *updateMessage = @"远端发现新版本请更新后重新启动应用";
                        if ([[[UIDevice currentDevice] systemVersion] floatValue] >= 19.0) {
                            
                            UIViewController* viewCtrl = [AppDelegate shareMyApplication].window.rootViewController;
                            UIAlertController* controller = [UIAlertController alertControllerWithTitle:@"版本提示" message:updateMessage preferredStyle:UIAlertControllerStyleAlert];
                            
                            UIAlertAction* confirm = [UIAlertAction actionWithTitle:@"更新" style:UIAlertActionStyleDefault handler:^(UIAlertAction* action) {
                                [[UIApplication sharedApplication] openURL:[NSURL URLWithString:versionURL]];
                                exit(0);
                            }];
                            [controller addAction:confirm];
                            
                            if (viewCtrl.presentedViewController != nil) {
                                [viewCtrl.presentedViewController dismissViewControllerAnimated:YES completion:^{
                                    [viewCtrl presentViewController:controller animated:YES completion:nil];
                                }];
                            } else {
                                [viewCtrl presentViewController:controller animated:YES completion:nil];
                            }
                            
                        } else {
                            
                            // 兼容iOS9一下系统
                            UIAlertView* confirm = [[UIAlertView alloc] initWithTitle:@"版本提示" message:updateMessage delegate:nil cancelButtonTitle:@"更新" otherButtonTitles:nil];
                            [confirm handlerClickedButton:^(NSInteger btnIndex) {
                                //
                                [[UIApplication sharedApplication] openURL:[NSURL URLWithString:versionURL]];
                                exit(0);
                            }];
                            [confirm show];
                        }
                    });
                }
            }
        } else {
           //
        }
    }];
}


@end
