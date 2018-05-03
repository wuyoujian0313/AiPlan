//
//  AIHTTPURLSession.m
//  Portal-sx
//
//  Created by wuyoujian on 2017/6/29.
//  Copyright © 2017年 Asiainfo. All rights reserved.
//

#import "AIHTTPURLSession.h"


@implementation AIHTTPURLSession

+ (AIHTTPURLSession *)sharedHTTPURLSession {
    
    static AIHTTPURLSession *obj = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        obj = [[self alloc] init];
    });
    return obj;
}

- (void)sendHTTPRequest:(NSURLRequest*)request completionHandler:(void (^)(NSData *data, NSURLResponse *response, NSError *error))completionHandler{
    
    NSURLSession *session = [NSURLSession sharedSession];
    NSURLSessionDataTask *dataTask = [session dataTaskWithRequest:request completionHandler: ^(NSData *data, NSURLResponse *response, NSError *error) {
    
//        NSString *str = [[NSString alloc] initWithData:data encoding:NSASCIIStringEncoding];
//        NSLog(@"response:%@",str);
        if (completionHandler) {
            completionHandler(data,response,error);
        }
    }];
    // 使用resume方法启动任务
    [dataTask resume];
}

- (void)downloadFileRequest:(NSURLRequest *)request completionHandler:(void (^)(NSURL * location, NSURLResponse * response, NSError * error))completionHandler {
    
    NSURLSession *session = [NSURLSession sharedSession];
    NSURLSessionDownloadTask *dataTask = [session downloadTaskWithRequest:request completionHandler:^(NSURL * _Nullable location, NSURLResponse * _Nullable response, NSError * _Nullable error) {
        //
        completionHandler(location,response,error);
    }];
    // 使用resume方法启动任务
    [dataTask resume];
    
}



@end
