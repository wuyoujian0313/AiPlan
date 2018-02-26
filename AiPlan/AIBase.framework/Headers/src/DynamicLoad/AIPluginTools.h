//
//  AIPluginTools.h
//  AIBase
//
//  Created by wuyoujian on 2017/6/21.
//  Copyright © 2017年 Asiainfo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "../Owns/AICommonDef.h"

@interface AIPluginTools : NSObject

AISINGLETON_DEF(AIPluginTools,SharedObj);

// 从framework根目录下加载图片
- (UIImage *)roadImageWithName:(NSString *)name;

// 从framework根目录下的包名：@param bunleName 中加载图片，例如，res.bundle
- (UIImage *)roadImageWithName:(NSString *)name inResBundle:(NSString*)bundleName;

// 从矢量图加载图片
- (UIImage *)roadVectorImageWithName:(NSString *)name;

// 从framework根目录下加载其他资源
- (NSData *)roadResWithName:(NSString*)name;

// 从framework根目录下的包名：@param bunleName 中加载其他资源，例如，res.bundle
- (NSData *)roadResWithName:(NSString*)name inResBundle:(NSString *)bundleName;

// 返回资源路径
- (NSString *)resPathWithName:(NSString*)name;

// 返回资源路径
- (NSString *)resPathWithName:(NSString*)name inResBundle:(NSString *)bundleName;


@end
