//
//  LocCacheURLProtocol.h
//  Portal-sx
//
//  Created by wuyoujian on 2017/7/10.
//  Copyright © 2017年 Asiainfo. All rights reserved.
//

#import <Foundation/Foundation.h>

//
#define kCACHE_PATHNAME   @".cacheFiles"

@interface LocCacheURLProtocol : NSURLProtocol

+ (NSString *)cacheFilePath;

// 仅缓存来自hosts 服务器上的请求
+ (BOOL)registerProtocolWithHosts:(NSArray*)hosts;

// 仅缓存来自hosts 服务器上的请求，忽视哪些url不走缓存
+ (BOOL)registerProtocolWithIgnoreURLs:(NSArray*)ignores fromHosts:(NSArray*)hosts;

// 卸载
+ (void)unregisterCacheURLProtocol;

@end
