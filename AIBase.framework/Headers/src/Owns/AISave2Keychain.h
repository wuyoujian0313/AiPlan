//
//  AISave2Keychain.h
//  CommonProject
//
//  Created by wuyoujian on 16/9/22.
//  Copyright © 2016年 wuyoujian. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AISave2Keychain : NSObject

// 不支持keychain共享能力
- (instancetype)initWithIdentifier:(NSString *)identifier;

// 支持keychain共享能力
- (instancetype)initWithIdentifier:(NSString *)identifier accessGroup:(NSString *)accessGroup;

// 保存数据,一般为：NString,NSData等支持NSCoding协议的OC对象
- (BOOL)saveObject:(id)inObject forKey:(NSString*)key;
- (id)objectForKey:(NSString*)key;
- (BOOL)removeObjectForKey:(NSString*)key;
- (BOOL)removeAllObjects;



@end
