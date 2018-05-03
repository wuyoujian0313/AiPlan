//
//  AIHTTPURLSession.h
//  Portal-sx
//
//  Created by wuyoujian on 2017/6/29.
//  Copyright © 2017年 Asiainfo. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface AIHTTPURLSession : NSObject

+ (AIHTTPURLSession *)sharedHTTPURLSession;

- (void)sendHTTPRequest:(NSURLRequest*)request completionHandler:(void (^)(NSData *data, NSURLResponse *response, NSError *error))completionHandler;

- (void)downloadFileRequest:(NSURLRequest *)request completionHandler:(void (^)(NSURL * location, NSURLResponse * response, NSError * error))completionHandler;

@end
