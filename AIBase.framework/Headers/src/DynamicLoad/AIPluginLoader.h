//
//  AIPluginLoader.h
//  CommonProject
//
//  Created by wuyoujian on 2017/6/19.
//
//

#import <Foundation/Foundation.h>
#import "../Owns/AINavigationController.h"
#import "../Owns/AICommonDef.h"
#import "AIPluginProtocol.h"


typedef NS_ENUM(NSInteger,PluginLoadStatus) {
    
    PluginLoadStatusNone = 0,
    PluginLoadStatusUnDownload = 1,     // 没有下载
    PluginLoadStatusDownloading = 2,    // 下载中
    PluginLoadStatusDownloaded = 3,     // 下载完毕
    PluginLoadStatusException = 4,      // 加载异常
    
};

@interface AIPluginLoader : NSObject

AISINGLETON_DEF(AIPluginLoader,SharedObj);

// 获取插件的状态
- (PluginLoadStatus)pluginloadStatus:(NSString*)pluginURL;

// 下载插件
- (void)downloadPlugin:(NSString*)pluginURL;

// 加载插件
- (void)loadPluginName:(NSString*)frameworkName
                   nav:(AINavigationController*)navVC
      enterVCClassName:(NSString*)className;

// 加载插件
- (UIViewController<AIPluginProtocol> *)loadPluginName:(NSString*)frameworkName enterVCClassName:(NSString*)className;

@end
