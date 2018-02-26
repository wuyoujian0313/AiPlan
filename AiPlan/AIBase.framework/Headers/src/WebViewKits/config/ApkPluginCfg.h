//
//  ApkPluginCfg.h
//  AIBase
//
//  Created by wuyoujian on 2017/6/22.
//  Copyright © 2017年 Asiainfo. All rights reserved.
//

#import "AbstractCfg.h"
#import "../../Owns/AICommonDef.h"


@interface ApkPluginCfg : AbstractCfg

@property(nonatomic,copy,readonly) NSString* CONFIG_FIND_PATH;
@property(nonatomic,copy,readonly) NSString* CONFIG_ATTR_NAME;
@property(nonatomic,copy,readonly) NSString* CONFIG_ATTR_CLASS;
@property(nonatomic,copy,readonly) NSString* CONFIG_ATTR_PACKAGENAME;
@property(nonatomic,copy,readonly) NSString* CONFIG_ATTR_APKURL;

AISINGLETON_CLASS_DEF(ApkPluginCfg,SharedObj);

- (NSDictionary *)get:(NSString *)name;
- (NSString *)attr:(NSString *)name attrName:(NSString*)attr;

@end
