//
//  WKWebViewVC.m
//  AiPlan
//
//  Created by wuyoujian on 2018/5/11.
//  Copyright © 2018年 AI. All rights reserved.
//

#import "WKWebViewVC.h"
#import <WebKit/WebKit.h>


@interface WKWebViewVC ()<WKNavigationDelegate,WKUIDelegate>
@property (nonatomic,strong) WKWebView *wkWebView;
@end

@implementation WKWebViewVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor colorWithHex:0x282333];
    [self initWKWebView];
}

- (void)initWKWebView {
    WKWebViewConfiguration *configuration = [[WKWebViewConfiguration alloc] init];
    configuration.userContentController = [WKUserContentController new];
    
    self.wkWebView = [[WKWebView alloc] initWithFrame:CGRectMake(0, [DeviceInfo statusBarHeight], self.view.frame.size.width, self.view.frame.size.height - [DeviceInfo statusBarHeight]) configuration:configuration];
    _wkWebView.navigationDelegate = self;
    self.wkWebView.UIDelegate = self;
    _wkWebView.backgroundColor = [UIColor colorWithHex:0x282333];
    GlobalCfg *cfg = [GlobalCfg SharedObj];
#if 1
    NSString *homeURL = [cfg attr:@"online.addr"];
    NSURL *url = [NSURL URLWithString:homeURL];
#else
    NSBundle *mainBundle = [NSBundle mainBundle];
    NSURL *url = [NSURL URLWithString:[mainBundle pathForResource:@"department" ofType:@"html" inDirectory:@"demo/page"]];
#endif
    NSURLRequest *request = [NSURLRequest requestWithURL:url cachePolicy:NSURLRequestReloadIgnoringCacheData timeoutInterval:30.0];
    [self.wkWebView loadRequest:request];
    
    if (@available(iOS 11.0, *)) {
        _wkWebView.scrollView.contentInsetAdjustmentBehavior = UIApplicationBackgroundFetchIntervalNever;
    } else {
        self.automaticallyAdjustsScrollViewInsets = false;
    }
    
    [_wkWebView.scrollView setBounces:NO];
    [self.view addSubview:self.wkWebView];
    [self setCustomUserAgent];
}

- (void)setCustomUserAgent {
    __weak WKWebViewVC *wSelf = self;
    [_wkWebView evaluateJavaScript:@"navigator.userAgent" completionHandler:^(id result, NSError *error) {
        NSString *userAgent = result;
        GlobalCfg *cfg = [GlobalCfg SharedObj];
        NSString *agentString = [cfg attr:@"userAgent"];
        NSString *newUserAgent = [userAgent stringByAppendingFormat:@" ;%@",agentString];
        NSDictionary *dictionary = [NSDictionary dictionaryWithObjectsAndKeys:newUserAgent, @"UserAgent", nil];
        [[NSUserDefaults standardUserDefaults] registerDefaults:dictionary];
        [[NSUserDefaults standardUserDefaults] synchronize];
        if(@available(iOS 9.0,*)){
            [wSelf.wkWebView setCustomUserAgent:newUserAgent];
        }
    }];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - WKNavigationDelegate
// 页面开始加载时调用
- (void)webView:(WKWebView *)webView didStartProvisionalNavigation:(WKNavigation *)navigation {
    
}

// 当内容开始返回时调用
- (void)webView:(WKWebView *)webView didCommitNavigation:(WKNavigation *)navigation {
    
}

// 页面加载完成之后调用
- (void)webView:(WKWebView *)webView didFinishNavigation:(WKNavigation *)navigation {
}

// 页面加载失败时调用
- (void)webView:(WKWebView *)webView didFailProvisionalNavigation:(WKNavigation *)navigation {
}

/*
 // 接收到服务器跳转请求之后调用
 - (void)webView:(WKWebView *)webView didReceiveServerRedirectForProvisionalNavigation:(WKNavigation *)navigation {
 
 }
 
 // 在收到响应后，决定是否跳转
 - (void)webView:(WKWebView *)webView decidePolicyForNavigationResponse:(WKNavigationResponse *)navigationResponse decisionHandler:(void (^)(WKNavigationResponsePolicy))decisionHandler {
 
 }
 
 // 在发送请求之前，决定是否跳转
 - (void)webView:(WKWebView *)webView decidePolicyForNavigationAction:(WKNavigationAction *)navigationAction decisionHandler:(void (^)(WKNavigationActionPolicy))decisionHandler {
 
 }
 */


@end
