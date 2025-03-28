//
//  TalkingData.h
//  __MyProjectName__
//
//  Created by Biao Hou on 11-11-14.
//  Copyright (c) 2011年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>


#if TARGET_OS_IOS
typedef NS_ENUM(NSUInteger, TDAccountType) {
    TDAccountTypeAnonymous      = 0,    // 匿名账户
    TDAccountTypeRegistered     = 1,    // 显性注册账户
    TDAccountTypeSinaWeibo      = 2,    // 新浪微博
    TDAccountTypeQQ             = 3,    // QQ账户
    TDAccountTypeTencentWeibo   = 4,    // 腾讯微博
    TDAccountTypeND91           = 5,    // 91账户
    TDAccountTypeWeiXin         = 6,    // 微信
    TDAccountTypeType1          = 11,   // 自定义类型1
    TDAccountTypeType2          = 12,   // 自定义类型2
    TDAccountTypeType3          = 13,   // 自定义类型3
    TDAccountTypeType4          = 14,   // 自定义类型4
    TDAccountTypeType5          = 15,   // 自定义类型5
    TDAccountTypeType6          = 16,   // 自定义类型6
    TDAccountTypeType7          = 17,   // 自定义类型7
    TDAccountTypeType8          = 18,   // 自定义类型8
    TDAccountTypeType9          = 19,   // 自定义类型9
    TDAccountTypeType10         = 20    // 自定义类型10
};
#endif


#if TARGET_OS_IOS
@interface TalkingDataOrder : NSObject

/**
 *  @method createOrder
 *  @param  orderId          订单id         类型:NSString
 *  @param  total            订单总价        类型:int
 *  @param  currencyType     币种           类型:NSString
 */
+ (TalkingDataOrder *)createOrder:(NSString *)orderId total:(int)total currencyType:(NSString *)currencyType;

/**
 *  @method addItemWithCategory
 *  @param  itemId           商品Id         类型:NSString
 *  @param  category         商品类别        类型:NSString
 *  @param  name             商品名称        类型:NSString
 *  @param  unitPrice        商品单价        类型:int
 *  @param  amount           商品数量        类型:int
 */
- (TalkingDataOrder *)addItem:(NSString *)itemId category:(NSString *)category name:(NSString *)name unitPrice:(int)unitPrice amount:(int)amount;

@end


@interface TalkingDataShoppingCart : NSObject

/**
 *  @method createShoppingCart
 */
+ (TalkingDataShoppingCart *)createShoppingCart;

/**
 *  @method addItem
 *  @param  itemId           商品Id         类型:NSString
 *  @param  category         商品类别        类型:NSString
 *  @param  name             商品名称        类型:NSString
 *  @param  unitPrice        商品单价        类型:int
 *  @param  amount           商品数量        类型:int
 */
- (TalkingDataShoppingCart *)addItem:(NSString *)itemId category:(NSString *)category name:(NSString *)name unitPrice:(int)unitPrice amount:(int)amount;

@end
#endif

// 以下枚举用于WatchApp页面追踪
typedef enum {
    TDPageTypeGlance = 1,
    TDPageTypeNotification = 2,
    TDPageTypeWatchApp = 3
} TDPageType;

@interface TalkingData: NSObject

/**
 *  @method getDeviceID
 *  获取SDK所使用的DeviceID
 *  @return DeviceID
 */
+ (NSString *)getDeviceID;

/**
 *  @method setLogEnabled
 *  统计日志开关（可选）
 *  @param  enable      默认是开启状态
 */
+ (void)setLogEnabled:(BOOL)enable;

#if TARGET_OS_IOS
/**
 *  @method setExceptionReportEnabled
 *  是否捕捉程序崩溃记录（可选）
 *  如果需要记录程序崩溃日志，请将值设成YES，并且在初始化后尽早调用
 *  @param  enable      默认是 NO
 */
+ (void)setExceptionReportEnabled:(BOOL)enable;

/**
 *  @method setSignalReportEnabled
 *  是否捕捉异常信号（可选）
 *  如果需要开启异常信号捕捉功能，请将值设成YES，并且在初始化后尽早调用
 *  @param  enable      默认是NO
 */
+ (void)setSignalReportEnabled:(BOOL)enable;
#endif



#if TARGET_OS_IOS
/**
 *  @method setLatitude:longitude:
 *  设置位置信息（可选）
 *  @param  latitude    维度
 *  @param  longitude   经度
 */
+ (void)setLatitude:(double)latitude longitude:(double)longitude;
#endif

/**
 *  @method backgroundSessionEnabled
 *  开启后台使用时长统计，需在SDK初始化之前调用。
 */
+ (void)backgroundSessionEnabled;

#if TARGET_OS_IOS
/**
 *  @method	sessionStarted:withChannelId:
 *  初始化统计实例，请在application:didFinishLaunchingWithOptions:方法里调用
 *  @param  appKey      应用的唯一标识，统计后台注册得到
 *  @param  channelId   渠道名，如“app store”（可选）
 */
+ (void)sessionStarted:(NSString *)appKey withChannelId:(NSString *)channelId;
#endif


#if TARGET_OS_IOS
/**
 *	@method	setAntiCheatingEnabled
 *  是否开启反作弊功能
 *	@param 	enabled 	默认是开启状态
 */
+ (void)setAntiCheatingEnabled:(BOOL)enabled;
#endif


#if TARGET_OS_IOS
/**
 *  @method onRegister  注册
 *  @param  accountId   账户ID
 *  @param  type        账户类型
 *  @param  name        账户昵称
 */
+ (void)onRegister:(NSString *)accountId type:(TDAccountType)type name:(NSString *)name;

/**
 *  @method onLogin     登录
 *  @param  accountId   账户ID
 *  @param  type        账户类型
 *  @param  name        账户昵称
 */
+ (void)onLogin:(NSString *)accountId type:(TDAccountType)type name:(NSString *)name;

#endif

/**
 *  @method trackEvent
 *  统计自定义事件（可选），如购买动作
 *  @param  eventId     事件名称（自定义）
 */
+ (void)trackEvent:(NSString *)eventId;

/**
 *  @method trackEvent:label:
 *  统计带标签的自定义事件（可选），可用标签来区别同一个事件的不同应用场景
    如购买某一特定的商品
 *  @param  eventId     事件名称（自定义）
 *  @param  eventLabel  事件标签（自定义）
 */
+ (void)trackEvent:(NSString *)eventId label:(NSString *)eventLabel;

/**
 *  @method	trackEvent:label:parameters
 *  统计带二级参数的自定义事件，单次调用的参数数量不能超过10个
 *  @param  eventId     事件名称（自定义）
 *  @param  eventLabel  事件标签（自定义）
 *  @param  parameters  事件参数 (key只支持NSString, value支持NSString和NSNumber)
 */
+ (void)trackEvent:(NSString *)eventId 
             label:(NSString *)eventLabel 
        parameters:(NSDictionary *)parameters;

/**
 *  @method setGlobalKV:value:
 *  添加全局的字段，这里的内容会每次的自定义事都会带着，发到服务器。也就是说如果您的自定义事件中每一条都需要带同样的内容，如用户名称等，就可以添加进去
 *  @param  key         自定义事件的key，如果在之后，创建自定义的时候，有相同的key，则会覆盖，全局的里相同key的内容
 *  @param  value       这里是NSObject类型，或者是NSString 或者NSNumber类型
 */
+ (void)setGlobalKV:(NSString *)key value:(id)value;

/**
 *  @method removeGlobalKV:
 *  删除全局数据
 *  @param  key         自定义事件的key
 */
+ (void)removeGlobalKV:(NSString *)key;

/**
 *  @method	trackPageBegin
 *  开始跟踪某一页面（可选），记录页面打开时间
    建议在viewWillAppear或者viewDidAppear方法里调用
 *  @param  pageName    页面名称（自定义）
 */
+ (void)trackPageBegin:(NSString *)pageName;

/**
 *  @method trackPageBegin:withPageType:
 *  开始跟踪WatchApp某一页面（可选），记录页面打开时间
    建议在willActivate方法里调用
 *  @param  pageName    页面名称（自定义）
 *  @param  pageType    页面类型（TDPageType枚举类型）
 */
+ (void)trackPageBegin:(NSString *)pageName withPageType:(TDPageType)pageType;

/**
 *  @method trackPageEnd
 *  结束某一页面的跟踪（可选），记录页面的关闭时间
    此方法与trackPageBegin方法结对使用，
    在iOS应用中建议在viewWillDisappear或者viewDidDisappear方法里调用
    在Watch应用中建议在DidDeactivate方法里调用
 *  @param  pageName    页面名称，请跟trackPageBegin方法的页面名称保持一致
 */
+ (void)trackPageEnd:(NSString *)pageName;

#if TARGET_OS_IOS
/**
 *  @method onPlaceOrder    下单
 *  @param  accountId       账户ID          类型:NSString
 *  @param  order           订单            类型:TalkingDataOrder
 */
+ (void)onPlaceOrder:(NSString *)accountId order:(TalkingDataOrder *)order;

/**
 *  @method onOrderPaySucc  支付
 *  @param  accountId       账户ID          类型:NSString
 *  @param  payType         支付类型         类型:NSString
 *  @param  order           订单详情         类型:TalkingDataOrder
 */
+ (void)onOrderPaySucc:(NSString *)accountId payType:(NSString *)payType order:(TalkingDataOrder *)order;

/**
 *  @method onViewItem
 *  @param  itemId           商品Id         类型:NSString
 *  @param  category         商品类别        类型:NSString
 *  @param  name             商品名称        类型:NSString
 *  @param  unitPrice        商品单价        类型:int
 */
+ (void)onViewItem:(NSString *)itemId category:(NSString *)category name:(NSString *)name unitPrice:(int)unitPrice;

/**
 *  @method onAddItemToShoppingCart
 *  @param  itemId           商品Id         类型:NSString
 *  @param  category         商品类别        类型:NSString
 *  @param  name             商品名称        类型:NSString
 *  @param  unitPrice        商品单价        类型:int
 *  @param  amount           商品数量        类型:int
 */
+ (void)onAddItemToShoppingCart:(NSString *)itemId category:(NSString *)category name:(NSString *)name unitPrice:(int)unitPrice amount:(int)amount;

/**
 *  @method onViewShoppingCart
 *  @param  shoppingCart    购物车信息       类型:TalkingDataShoppingCart
 */
+ (void)onViewShoppingCart:(TalkingDataShoppingCart *)shoppingCart;
#endif






@end
