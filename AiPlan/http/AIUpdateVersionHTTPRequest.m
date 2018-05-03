//
//  AIUpdateVersionHTTPRequest.m
//  Portal-sx
//
//  Created by wuyoujian on 2017/6/29.
//  Copyright © 2017年 Asiainfo. All rights reserved.
//

#import "AIUpdateVersionHTTPRequest.h"

@implementation AIUpdateVersionHTTPRequest

- (NSURLRequest *)toHTTPRequest {
    
    NSLog(@"uploadFileURL:%@",self.url);
    
    NSURL *URL = [NSURL URLWithString:self.url];
    NSMutableURLRequest *requestObj = [NSMutableURLRequest requestWithURL:URL cachePolicy:NSURLRequestUseProtocolCachePolicy timeoutInterval:self.timeout];
    
    [requestObj setHTTPMethod:@"GET"];
    //设置http 头
    [requestObj addValue:@"UTF-8" forHTTPHeaderField:@"Accept-Language"];
    [requestObj addValue:@"close" forHTTPHeaderField:@"Connection"];
    
    NSString *host = URL.host;
    [requestObj addValue:host forHTTPHeaderField:@"Host"];
    
    return requestObj;
}

@end
