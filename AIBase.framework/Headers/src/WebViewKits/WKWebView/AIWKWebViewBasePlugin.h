//
//  AIWKWebViewBasePlugin.h
//  CommonProject
//
//  Created by wuyoujian on 2018/5/12.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import "../../Owns/BaseVC.h"

@interface AIWKWebViewBasePlugin : NSObject
@property(nonatomic,strong,nonnull) BaseVC              *vc;
@property(nonatomic,strong,nonnull) WKWebView           *wkWebView;

// 调用JS API
- (void)excuteJavascript:(NSString*_Nonnull)script;

// 调用JS API
- (void)excuteJavascript:(NSString*_Nonnull)script completionHandler:(void (^ _Nullable)(_Nullable id, NSError * _Nullable error))completionHandler;

// js匿名回调, actionName 即配置wade-plugin.xml中，action的name
- (void)callback:(NSString *_Nonnull)actionName param:(NSString *_Nonnull)param;

// 格式化js
+ (NSString * _Nullable )paramEncodeForJs:(NSString *_Nonnull)string;

// 扩展原生能力接口
- (void)JN_Test:(NSDictionary *_Nullable)params;

// 退出程序
- (void)JN_Quit:(NSString *)params;

// 分享程序
- (void)JN_Sharing:(NSString *)params;

@end
