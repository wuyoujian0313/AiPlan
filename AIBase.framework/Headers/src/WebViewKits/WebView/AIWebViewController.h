//
//  AIWebViewController.h
//  CommonProject
//
//  Created by wuyoujian on 16/7/14.
//  Copyright © 2016年 wuyoujian. All rights reserved.
//

#import "../../Owns/BaseVC.h"
#import "AIWebViewBasePlugin.h"


@interface AIWebViewController : BaseVC
@property (nonatomic, weak) id <UIWebViewDelegate> delegate;
@property (nonatomic, readonly, strong) UIWebView *contentWebView;


// 设置user-agent
- (void)setUserAgent:(NSString*)userAgent;

// 加载对应的url web页面
- (void)loadWebViewForURL:(NSURL*)url;

// 刷新当前页面
- (void)reload;

// 根据配置文件注册H5插件
- (void)registerScriptPluginsWithFile:(NSString *)configFile;

// 根据配置文件注册H5插件
- (void)registerScriptPluginsWithData:(NSData *)configData;

// 回调H5 JS的匿名回调函数
// @param:pluginAPIName,插件方法名称：构成结构：className_functionName,例如：AIWebViewBasePlugin_JN_Test
- (void)callbackWithPluginAPIName:(NSString *)pluginAPIName param:(NSString *)param;

// 调用js
- (void)evaluateScript:(NSString*)script;

// 调用js function
// 调用全局js方法
- (void)invokeMethod:(NSString *)method withArguments:(NSArray *)arguments;

// 调用JS对象@objectName上的@prama method的方法
- (void)invokeObjectName:(NSString*)objectName method:(NSString *)method withArguments:(NSArray *)arguments;

// 注册WebView的http(s)的请求监听组件
- (BOOL)registerURLProtocolClass:(Class)protocolClass;

// 释放WebView的http(s)的请求监听组件
- (void)unregisterURLProtocolClass:(Class)protocolClass;


@end
