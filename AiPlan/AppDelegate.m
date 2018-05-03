//
//  AppDelegate.m
//  AiPlan
//
//  Created by wuyoujian on 2018/2/26.
//  Copyright © 2018年 AI. All rights reserved.
//

#import "AppDelegate.h"
#import <AIBase/AIBase.h>
#import <CoreTelephony/CTCellularData.h>
#import "VersionManager.h"


@interface AppDelegate ()
@property (nonatomic, strong) AINavigationController        *mainNav;
@property (nonatomic, strong) WebViewKitController          *mainVC;
@end

@implementation AppDelegate

+ (AppDelegate*)shareMyApplication {
    return (AppDelegate*)[UIApplication sharedApplication].delegate;
}

- (void)layoutMainPage {
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    WebViewKitController *tempVC = [[WebViewKitController alloc] init];
    self.mainVC = tempVC;
    
    GlobalCfg *cfg = [GlobalCfg SharedObj];
    NSString *homeURL = [cfg attr:@"online.addr"];
    [_mainVC loadWebViewForURL:[NSURL URLWithString:homeURL]];
    NSString *userAgent = [cfg attr:@"userAgent"];
    [_mainVC setUserAgent:userAgent];
    
    
    AINavigationController *tempNav = [[AINavigationController alloc] initWithRootViewController:_mainVC];
    self.mainNav = tempNav;
    _mainNav.navigationBarHidden = YES;
    
    self.window.rootViewController = _mainNav;
    [_window makeKeyAndVisible];
}

- (void)initAppParam {
    // 解析全局配置
    GlobalCfg *cfg = [GlobalCfg SharedObj];
    NSData *cfgData = [[AIPluginTools SharedObj] roadResWithName:@"global.properties"];
    [cfg parseConfigByData:cfgData element:nil attrKey:nil];
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    [self initAppParam];
    [self checkNetAuth];
    [self layoutMainPage];

    return YES;
}

- (void)checkNetAuth {
    if (@available(iOS 9.0, *)) {
        CTCellularData *cellularData = [[CTCellularData alloc] init];
        CTCellularDataRestrictedState state = cellularData.restrictedState;
        switch (state) {
            case kCTCellularDataNotRestricted:
                NSLog(@"Not Restricted");
                
                break;
            case kCTCellularDataRestricted:
            case kCTCellularDataRestrictedStateUnknown:
            default: {
                UIViewController* viewCtrl = _window.rootViewController;
                UIAlertController* controller = [UIAlertController alertControllerWithTitle:@"使用网络权限" message:@"'信.点兵'需要使用您的wifi或者蜂窝数据，请到设置里设置权限" preferredStyle:UIAlertControllerStyleAlert];
                
                UIAlertAction* confirm = [UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:^(UIAlertAction* action) {
                    exit(0);
                }];
                [controller addAction:confirm];
                [viewCtrl presentViewController:controller animated:YES completion:nil];
            }
                
                break;
        }
    } else {
        // Fallback on earlier versions
    }
}


- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        // 耗时的操作
        [VersionManager checkVersion];
    });
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}


@end
