//
//  AIWebViewBasePlugin.h
//  CommonProject
//
//  Created by wuyoujian on 2017/6/14.
//
//

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JavaScriptCore.h>
#import "../../Owns/BaseVC.h"

typedef NS_ENUM(NSInteger, PluginCallbackStatus) {
    PluginCallbackStatusNone,
    PluginCallbackStatusSuccessWithData,
    PluginCallbackStatusSuccessWithoutData,
    PluginCallbackStatusFail,
    PluginCallbackStatusCancel,
    PluginCallbackStatusSave,
};

/**
 *  扩展插件类
 *  1、JSExport是JS与OC之间的穿梭机；
 *  2、把需要扩展的API定义到protocol:JSExport里，在插件类里实现接口；
 *  3、若是多参数的API，可以采用JSExportAs来声明接口,可以参考ScriptPluginBase；默认的情况，在JS端是会把参数tag首字母大写拼接成JS的function调用方式，例如：test:(NString*)str key:(NString*)k --> testKey(str,k);
 *  4、注意，扩展的API,如果要操作UI的，一定要在主线程里调用。很多情况，jscontext是非主线程调用API；
 */

@protocol JN_BasePluginExport <JSExport>

// 基础的能力接口
// 1、数据存取
JSExportAs(JN_SetValueWithKey,- (void)JN_SetValueWithKey:(NSString*)key value:(NSString*)value);
- (NSString*)JN_GetValueWithKey:(NSString*)key;
- (void)JN_RemoveAllData;
- (void)JN_RemoveDataByKey:(NSString*)key;

// 2、数据安全
- (NSString*)JN_Encrypt:(NSString*)context;
- (NSString*)JN_Decrypt:(NSString*)encrypt;
- (NSString*)JN_IDMD5:(NSString*)userName;
- (NSString*)JN_Token:(NSString*)params;
JSExportAs(JN_ShowFadeMsg, -(void)JN_ShowFadeMsg:(NSString *)msg status:(int)status);

// 隐藏键盘
- (void)JN_HideKeyboard;
// 获取手机型号等信息
- (NSString *)JN_GetPhoneModule;
@end

@protocol PluginCallBack <NSObject>

// 每一个插件实现的回调函数
- (void)pluginCallbackHandler:(NSString *)apiName status:(PluginCallbackStatus)status response:(id )response argument1:(id)argument1 argument2:(id)argument2,...;

@end

#define kAIUserDefaultKey   @"kAIUserDefaultKey"

@interface AIWebViewBasePlugin : NSObject<JN_BasePluginExport,PluginCallBack>
@property(nonatomic,strong) BaseVC              *vc;
@property(nonatomic,strong) UIWebView           *webView;


@end
