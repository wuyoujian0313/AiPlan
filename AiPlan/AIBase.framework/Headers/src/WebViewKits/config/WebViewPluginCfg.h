//
//  WebViewPluginCfg.h
//  CommonProject
//
//  Created by wuyoujian on 2017/6/13.
//
//

#import "AbstractCfg.h"
#import "../../Owns/AICommonDef.h"

@interface WebViewPluginCfg : AbstractCfg

@property(nonatomic,copy,readonly) NSString* CONFIG_FIND_PATH;
@property(nonatomic,copy,readonly) NSString* CONFIG_ATTR_NAME;
@property(nonatomic,copy,readonly) NSString* CONFIG_ATTR_CLASS;
@property(nonatomic,copy,readonly) NSString* CONFIG_ATTR_PACKAGENAME;

AISINGLETON_CLASS_DEF(WebViewPluginCfg,SharedObj);

- (NSDictionary *)get:(NSString *)name;
- (NSString *)attr:(NSString *)name attrName:(NSString*)attr;

@end
