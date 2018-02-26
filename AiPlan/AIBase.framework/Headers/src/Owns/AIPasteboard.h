//
//  AIPasteboard.h
//  CommonProject
//
//  Created by wuyoujian on 16/8/26.
//  Copyright © 2016年 wuyoujian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface AIPasteboard : NSObject

// @创建的系统级的剪贴板
- (instancetype)initPasteboard;

// @aKey是字段的key
- (void)setData:(NSData*)data forKey:(NSString *)aKey;
- (NSData*)getDataForKey:(NSString *)aKey;

// @aKey是字段的key
- (void)setImage:(UIImage*)image forKey:(NSString *)aKey;
- (UIImage*)getImageForKey:(NSString *)aKey;

// @aKey是字段的key
- (void)setString:(NSString*)string forKey:(NSString *)aKey;
- (NSString*)getStringForKey:(NSString *)aKey;

// 一定要调用这个方法保存数据
- (void)save;

@end
