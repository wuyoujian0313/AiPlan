//
//  AIGesturePasswordView.h
//  CommonProject
//
//  Created by wuyoujian on 16/9/21.
//  Copyright © 2016年 wuyoujian. All rights reserved.
//

#import <UIKit/UIKit.h>

@class AIGesturePasswordView;
@protocol AIGesturePasswordViewDelegate <NSObject>

// 通过手势设置密码
- (void)gesturePasswordView:(AIGesturePasswordView*)sender password:(NSString*)password;
// 密码个数小于4位，无效
- (void)gestureInvalidPasswordView:(AIGesturePasswordView*)sender;
@end

@interface AIGesturePasswordView : UIView
@property (nonatomic, assign) id<AIGesturePasswordViewDelegate> delegate;
@property (nonatomic, assign) CGFloat pathWidth;
@property (nonatomic, strong) UIColor *selectColor;
@property (nonatomic, strong) UIColor *defaultColor;
@property (nonatomic, strong) UIColor *wrongColor;
@property (nonatomic, strong) UIColor *pathColor;

- (void)showWrongPasswordView;
- (void)clear;

@end
