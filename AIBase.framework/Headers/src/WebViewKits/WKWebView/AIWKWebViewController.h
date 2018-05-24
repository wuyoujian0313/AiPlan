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
@property (nonatomic,weak, nullable) id <WKNavigationDelegate,WKUIDelegate> delegate;
@property (nonatomic,readonly, strong) WKWebView * _Nonnull wkWebView;

// 注册WebView的http(s)的请求监听组件
- (BOOL)registerURLProtocolClass:(Class _Nonnull )protocolClass;

// 释放WebView的http(s)的请求监听组件
- (void)unregisterURLProtocolClass:(Class _Nonnull )protocolClass;

@end
