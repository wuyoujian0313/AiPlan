//
//  AIWKWebViewController.h
//  WebViewTest-iOS
//
//  Created by wuyoujian on 2018/5/12.
//  Copyright © 2018年 AI. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "../../Owns/BaseVC.h"
#import <WebKit/WebKit.h>

@interface AIWKWebViewController : BaseVC<WKNavigationDelegate,WKUIDelegate>

@property (nullable,nonatomic,weak) id <WKNavigationDelegate,WKUIDelegate> delegate;
@property (nonatomic, readonly, strong) WKWebView * _Nonnull wkWebView;

// 设置user-agent
- (void)setUserAgent:(NSString*_Nonnull)userAgent;

// 加载对应的url web页面
- (void)loadWKWebViewForURL:(NSURL*_Nonnull)url configFile:(NSString *_Nullable)configFile;
// 加载对应的url web页面
- (void)loadWKWebViewForURL:(NSURL*_Nonnull)url configData:(NSData *_Nullable)configData;

// 刷新当前页面
- (void)reload;

// 调用js
- (void)evaluateScript:(NSString*_Nonnull)script;

// 调用JS API
- (void)excuteJavascript:(NSString*_Nonnull)script completionHandler:(void (^ _Nullable)(_Nullable id, NSError * _Nullable error))completionHandler;

// 注册WebView的http(s)的请求监听组件
- (BOOL)registerURLProtocolClass:(Class _Nonnull )protocolClass;

// 释放WebView的http(s)的请求监听组件
- (void)unregisterURLProtocolClass:(Class _Nonnull )protocolClass;

@end
