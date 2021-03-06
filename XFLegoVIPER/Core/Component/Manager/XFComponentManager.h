//
//  XFComponentManager.h
//  XFLegoVIPER
//
//  Created by Yizzuide on 2016/12/20.
//  Copyright © 2016年 yizzuide. All rights reserved.
//

#import <Foundation/Foundation.h>

// 给某个组件发事件数据
#define XF_SendEventForComponent_(eventName, sendData, componentName) \
[XFComponentManager sendEventName:eventName intentData:sendData forComponent:componentName];

@protocol XFComponentRoutable;
NS_ASSUME_NONNULL_BEGIN
@interface XFComponentManager : NSObject

/**
 *  添加APP应用通知
 */
+ (void)addApplicationNotification;

/**
 *  添加组件
 *
 *  @param component 组件
 *  @param enableLog 允许组件跟踪打印
 */
+ (void)addComponent:(id<XFComponentRoutable>)component enableLog:(BOOL)enableLog;
/**
 *  删除组件
 *
 *  @param component 组件
 */
+ (void)removeComponent:(id<XFComponentRoutable>)component;
/**
 *  组件总数
 *
 */
+ (NSInteger)count;
/**
 *  查找一个组件
 *
 *  @param componentName 组件名
 *
 *  @return 组件
 */
+ (id<XFComponentRoutable>)findComponentForName:(NSString *)componentName;
/**
 *  发送组件事件消息
 *
 *  @param eventName      事件名
 *  @param intentData     消息意图数据
 *  @param componentName  组件名
 */
+ (void)sendEventName:(NSString *)eventName intentData:(nullable id)intentData forComponent:(NSString *)componentName;
/**
 *  发送多个组件事件消息
 *
 *  @param eventName      事件名
 *  @param intentData     消息意图数据
 *  @param componentNames 组件名数组
 */
+ (void)sendEventName:(NSString *)eventName intentData:(nullable id)intentData forComponents:(NSArray<NSString *> *)componentNames;

@end
NS_ASSUME_NONNULL_END
