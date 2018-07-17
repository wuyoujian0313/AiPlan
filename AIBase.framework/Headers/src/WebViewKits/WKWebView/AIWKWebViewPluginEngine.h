//
//  AIWKWebViewPluginEngine.h
//  CommonProject
//
//  Created by wuyoujian on 2018/5/12.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>
#import "../../Owns/BaseVC.h"
#import "../../Owns/AICommonDef.h"


@interface AIWKWebViewPluginEngine : NSObject

AISINGLETON_DEF(AIWKWebViewPluginEngine,SharedEngine);

/*
 根据传入的配置文件，注册插件,配置文件从mainBundle里加载
 给使用者构造一个支持JS交互的WKWebView，！！！！！注意构造出来的WKWebView未加入到父视图，你可以自由加入到父视图
 @param vc :WKWebView所在的ViewController
 @param frame:WKWebView的frame
 @param configFile配置文件
 */
- (WKWebView *_Nonnull)newPluginWKWebViewInVC:(BaseVC<WKNavigationDelegate,WKUIDelegate>*_Nonnull)vc frame:(CGRect)frame configFile:(NSString*_Nonnull)configFile;

/*
 根据传入的配置文件，注册插件,配置文件数据
 给使用者构造一个支持JS交互的WKWebView，！！！！！注意构造出来的WKWebView未加入到父视图，你可以自由加入到父视图
 @param vc :WKWebView所在的ViewController
 @param frame:WKWebView的frame
 @param configData配置文件数据
 */
- (WKWebView *_Nonnull)newPluginWKWebViewInVC:(BaseVC<WKNavigationDelegate,WKUIDelegate>*_Nonnull)vc frame:(CGRect)frame configData:(NSData*_Nonnull)configData;

// 释放插件
- (void)unregisterPlugins;

// 调用JS API
- (void)excuteJavascript:(NSString*_Nonnull)script;

// 调用JS API
- (void)excuteJavascript:(NSString*_Nonnull)script completionHandler:(void (^ _Nullable)(_Nullable id, NSError * _Nullable error))completionHandler;

@end
