//
//  AIUpdateVersionHTTPRequest.h
//  Portal-sx
//
//  Created by wuyoujian on 2017/6/29.
//  Copyright © 2017年 Asiainfo. All rights reserved.
//

#import "AIHTTPRequest.h"

@interface AIUpdateVersionHTTPRequest : AIHTTPRequest
@property (nonatomic, copy) NSString    *versionUrl;

- (NSURLRequest *)toHTTPRequest;
@end
