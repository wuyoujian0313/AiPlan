//
//  AIHTTPRequest.h
//  Portal-sx
//
//  Created by wuyoujian on 2017/6/29.
//  Copyright © 2017年 Asiainfo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AIHTTPRequest : NSObject
@property(nonatomic,copy) NSString          *url;
@property(nonatomic,assign) NSTimeInterval  timeout;
@end
