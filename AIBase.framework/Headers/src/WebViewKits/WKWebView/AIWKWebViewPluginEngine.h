//
//  AIWKWebViewPluginEngine.h
//  CommonProject
//
//  Created by wuyoujian on 2018/5/12.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import "../../Owns/BaseVC.h"


#define kJSObjectName    @"WadeNAObjHander"

@interface AIWKWebViewPluginEngine : NSObject<WKScriptMessageHandler>

// 根据传入的配置文件，注册插件,配置文件从mainBundle里加载
- (WKWebView *_Nonnull)newPluginWKWebViewInVC:(BaseVC<WKNavigationDelegate,WKUIDelegate>*_Nonnull)vc frame:(CGRect)frame configFile:(NSString*_Nonnull)configFile;

// 根据传入的配置文件，注册插件,配置文件数据
- (WKWebView *_Nonnull)newPluginWKWebViewInVC:(BaseVC<WKNavigationDelegate,WKUIDelegate>*_Nonnull)vc frame:(CGRect)frame configData:(NSData*_Nonnull)configData;

// 释放插件
- (void)unregisterPlugins;

// 调用JS API
- (void)excuteJavascript:(NSString*_Nonnull)script;

// 调用JS API
- (void)excuteJavascript:(NSString*_Nonnull)script completionHandler:(void (^ _Nullable)(_Nullable id, NSError * _Nullable error))completionHandler;

// 参数js格式化
+ (NSString *_Nonnull)paramEncodeForJs:(NSString *_Nonnull)string;

@end
