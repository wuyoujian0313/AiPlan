//
//  AIOpenDocumentController.h
//  CommonProject
//
//  Created by Wu YouJian on 2018/7/9.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "AICommonDef.h"


@interface AIOpenDocumentController : NSObject

// 单例实例
AISINGLETON_DEF(AIOpenDocumentController,SharedDocumentController)

// 打开分享页面
- (void)openInView:(UIView *_Nonnull)view filePath:(NSString *_Nonnull)filePath;
// 打开分享页面
- (void)openOnlineFileInView:(UIView *_Nonnull)view fileUrl:(NSString *_Nonnull)fileUrl;

// 一般不需要主动调用
- (void)close;

@end
