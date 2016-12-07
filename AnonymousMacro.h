//
//  AnonymousMacro.h
//  
//
//  Created by 周祺华 on 2016/12/7.
//
//

#ifndef AnonymousMacro_h
#define AnonymousMacro_h






#pragma mark - 字符串是否为空

#define kStringIsEmpty(str) ([str isKindOfClass:[NSNull class]] || str == nil || [str length] < 1 ? YES : NO )



#pragma mark - 数组是否为空

#define kArrayIsEmpty(array) (array == nil || [array isKindOfClass:[NSNull class]] || array.count == 0)



#pragma mark - 字典是否为空

#define kDictIsEmpty(dic) (dic == nil || [dic isKindOfClass:[NSNull class]] || dic.allKeys == 0)



#pragma mark - 是否是空对象

#define kObjectIsEmpty(_object) (_object == nil \
|| [_object isKindOfClass:[NSNull class]] \
|| ([_object respondsToSelector:@selector(length)] && [(NSData *)_object length] == 0) \
|| ([_object respondsToSelector:@selector(count)] && [(NSArray *)_object count] == 0))



#pragma mark - 获取屏幕宽度与高度 ( " \ ":连接行标志，连接上下两行 )

#define kScreenWidth \
([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)] ? [UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale : [UIScreen mainScreen].bounds.size.width)

#define kScreenHeight \
([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)] ? [UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale : [UIScreen mainScreen].bounds.size.height)

#define kScreenSize \
([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)] ? CGSizeMake([UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale,[UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale) : [UIScreen mainScreen].bounds.size)



#pragma mark - 一些常用的缩写

#define kApplication        [UIApplication sharedApplication]

#define kKeyWindow          [UIApplication sharedApplication].keyWindow

#define kAppDelegate        [UIApplication sharedApplication].delegate

#define kUserDefaults      [NSUserDefaults standardUserDefaults]

#define kNotificationCenter [NSNotificationCenter defaultCenter]



#pragma mark - APP版本号

#define kAppVersion [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]



#pragma mark - 系统版本号

#define kSystemVersion [[UIDevice currentDevice] systemVersion]



#pragma mark - 获取当前语言
#define kCurrentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])



#pragma mark - 判断是否为iPhone

#define kISiPhone (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)



#pragma mark - 判断是否为iPad

#define kISiPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)



#pragma mark - 获取沙盒Document路径

#define kDocumentPath [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]



#pragma mark - 获取沙盒temp路径

#define kTempPath NSTemporaryDirectory()



#pragma mark - 获取沙盒Cache路径

#define kCachePath [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]



#pragma mark - 判断是真机还是模拟器

#if TARGET_OS_IPHONE
//真机
#endif
#if TARGET_IPHONE_SIMULATOR
//模拟器
#endif



// 开发的时候打印，但是发布的时候不打印的NSLog
#ifdef DEBUG
#define NSLog(...) NSLog(@"%s 第%d行 \n %@\n\n",__func__,__LINE__,[NSString stringWithFormat:__VA_ARGS__])
#else
#define NSLog(...)
#endif



#pragma mark - 颜色

#define kRGBColor(r, g, b)    [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]

#define kRGBAColor(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(r)/255.0 blue:(r)/255.0 alpha:a]

#define kRandomColor    KRGBColor(arc4random_uniform(256)/255.0,arc4random_uniform(256)/255.0,arc4random_uniform(256)/255.0)        //随机色生成

#define kColorWithHex(rgbValue) \
[UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16)) / 255.0 \
green:((float)((rgbValue & 0xFF00) >> 8)) / 255.0 \
blue:((float)(rgbValue & 0xFF)) / 255.0 alpha:1.0]



#pragma mark - 弱引用/强引用

#define kWeakSelf(type)  __weak typeof(type) weak##type = type;

#define kStrongSelf(type) __strong typeof(type) type = weak##type;



#pragma mark - 由角度转换弧度

#define kDegreesToRadian(x)      (M_PI * (x) / 180.0)



#pragma mark - 由弧度转换角度

#define kRadianToDegrees(radian) (radian * 180.0) / (M_PI)



#pragma mark - 获取一段时间间隔

#define kStartTime CFAbsoluteTime start = CFAbsoluteTimeGetCurrent();

#define kEndTime  NSLog(@"Time: %f", CFAbsoluteTimeGetCurrent() - start)



#pragma mark - 宏（指令）定义

#ifndef MacroDefinition_h      // 如果没定义

#define MacroDefinition_h



#pragma mark - 获取设备尺寸大小
// NavBar高度
#define NavigationBar_HEIGHT 44
//获取屏幕 宽度、高度

#define SCREEN_WIDTH ([UIScreen mainScreen].bounds.size.width)

#define SCREEN_HEIGHT ([UIScreen mainScreen].bounds.size.height)



#pragma mark - 打印日志
// DEBUG 模式下打印日志,当前行

#ifdef DEBUG
#  define DLog(fmt, ...) NSLog((@"%s [Line %d] " fmt), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__);

#else
#  define DLog(...)
#endif
// 重写NSLog,Debug模式下打印日志和当前行数

#if DEBUG
#define NSLog(FORMAT, ...) fprintf(stderr,"\nfunction:%s line:%d content:%s\n", __FUNCTION__, __LINE__, ［NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);

#else
#define NSLog(FORMAT, ...) nil
#endif
// DEBUG 模式下打印日志,当前行 并弹出一个警告

#ifdef DEBUG
#  define ULog(fmt, ...)  { UIAlertView *alert = ［UIAlertView alloc] initWithTitle:[NSString stringWithFormat:
@"%s\n [Line %d] ", __PRETTY_FUNCTION__, __LINE__] message:[NSString stringWithFormat:fmt, ##__VA_ARGS__]
delegate:nil cancelButtonTitle:@"Ok" otherButtonTitles:nil]; [alert show]; }

#else
#  define ULog(...)
#endif
#define ITTDEBUG

#define ITTLOGLEVEL_INFO    10

#define ITTLOGLEVEL_WARNING  3

#define ITTLOGLEVEL_ERROR    1

#ifndef ITTMAXLOGLEVEL

#ifdef DEBUG

#define ITTMAXLOGLEVEL ITTLOGLEVEL_INFO

#else

#define ITTMAXLOGLEVEL ITTLOGLEVEL_ERROR

#endif

#endif
// The general purpose logger. This ignores logging levels.

#ifdef ITTDEBUG
#define ITTDPRINT(xx, ...)  NSLog(@"%s(%d): " xx, __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)

#else
#define ITTDPRINT(xx, ...)  ((void)0)
#endif
// 打印当前方法的名称
#define ITTDPRINTMETHODNAME() ITTDPRINT(@"%s", __PRETTY_FUNCTION__)
// Log-level based logging macros.

#if ITTLOGLEVEL_ERROR <= ITTMAXLOGLEVEL
#define ITTDERROR(xx, ...)  ITTDPRINT(xx, ##__VA_ARGS__)

#else
#define ITTDERROR(xx, ...)  ((void)0)

#endif

#if ITTLOGLEVEL_WARNING <= ITTMAXLOGLEVEL
#define ITTDWARNING(xx, ...)  ITTDPRINT(xx, ##__VA_ARGS__)

#else
#define ITTDWARNING(xx, ...)  ((void)0)

#endif

#if ITTLOGLEVEL_INFO <= ITTMAXLOGLEVEL
#define ITTDINFO(xx, ...)  ITTDPRINT(xx, ##__VA_ARGS__)

#else
#define ITTDINFO(xx, ...)  ((void)0)

#endif

#ifdef ITTDEBUG
#define ITTDCONDITIONLOG(condition, xx, ...) { if ((condition)) { \
ITTDPRINT(xx, ##__VA_ARGS__); \
} \
} ((void)0)

#else
#define ITTDCONDITIONLOG(condition, xx, ...) ((void)0)

#endif

#define ITTAssert(condition, ...)                                      \
do {                                                                      \
if (!(condition)) {                                                    \
［NSAssertionHandler currentHandler]                                  \
handleFailureInFunction:[NSString                 stringWithUTF8String:__PRETTY_FUNCTION__] \
file:[NSString stringWithUTF8String:__FILE__]  \
lineNumber:__LINE__                                  \
description:__VA_ARGS__];                            \
}                                                                      \
} while(0)



#pragma mark - 系统
// 是否iPad

#define isPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
// 是否iPad

#define someThing (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)? ipad: iphone
// 获取系统版本

#define IOS_VERSION ［[UIDevice currentDevice] systemVersion] floatValue]

#define CurrentSystemVersion ［UIDevice currentDevice] systemVersion]
// 获取当前语言

#define CurrentLanguage (［NSLocale preferredLanguages] objectAtIndex:0])
// 判断是否 Retina屏、设备是否为iPone 5、是否是iPad

#define isRetina ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), ［UIScreen mainScreen] currentMode].size) : NO)

#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), ［UIScreen mainScreen] currentMode].size) : NO)

#define isPad (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
// 判断设备的操做系统是不是ios7

#define IOS7 (［[UIDevice currentDevice].systemVersion doubleValue] >= 7.0]
// 判断当前设备是不是iphone5

#define kScreenIphone5    ((［UIScreen mainScreen] bounds].size.height)>=568)
// 获取当前屏幕的高度

#define kMainScreenHeight ([UIScreen mainScreen].applicationFrame.size.height)
// 获取当前屏幕的宽度

#define kMainScreenWidth  ([UIScreen mainScreen].applicationFrame.size.width)
// 定义一个define函数

#define TT_RELEASE_CF_SAFELY(__REF) { if (nil != (__REF)) { CFRelease(__REF); __REF = nil; } }
// 判断是真机还是模拟器

#if TARGET_OS_IPHONE                           //iPhone Device

#endif
#if TARGET_IPHONE_SIMULATOR          //iPhone Simulator

#endif
// 检查系统版本

#define SYSTEM_VERSION_EQUAL_TO(v)                  (［[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)

#define SYSTEM_VERSION_GREATER_THAN(v)              (［[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)

#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  (［[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)

#define SYSTEM_VERSION_LESS_THAN(v)                (［[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)

#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)    (［[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)



#pragma mark - 内存
// 使用ARC和不使用ARC

#if __has_feature(objc_arc)

//compiling with ARC

#else

// compiling without ARC

#endif
#pragma mark - common functions

#define RELEASE_SAFELY(__POINTER) { [__POINTER release]; __POINTER = nil; }
// 释放一个对象

#define SAFE_DELETE(P) if(P) { [P release], P = nil; }

#define SAFE_RELEASE(x) [x release];x=nil



#pragma mark - 图片
// 读取本地图片

#define LOADIMAGE(file,ext) [UIImage imageWithContentsOfFile:［NSBundle mainBundle]pathForResource:file ofType:ext］
// 定义UIImage对象

#define IMAGE(A) [UIImage imageWithContentsOfFile:［NSBundle mainBundle] pathForResource:A ofType:nil］
// 定义UIImage对象

#define ImageNamed(_pointer) [UIImage imageNamed:[UIUtil imageName:_pointer］
//建议使用前两种宏定义,性能高于后者




#pragma mark - 颜色类
// rgb颜色转换（16进制->10进制）

#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]
// 带有RGBA的颜色设置

#define COLOR(R, G, B, A) [UIColor colorWithRed:R/255.0 green:G/255.0 blue:B/255.0 alpha:A]
// 获取RGB颜色

#define RGBA(r,g,b,a) [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a]

#define RGB(r,g,b) RGBA(r,g,b,1.0f)
// 背景色

#define BACKGROUND_COLOR [UIColor colorWithRed:242.0/255.0 green:236.0/255.0 blue:231.0/255.0 alpha:1.0]
// 清除背景色

#define CLEARCOLOR [UIColor clearColor]

#pragma mark - color functions

#define RGBCOLOR(r,g,b) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]

#define RGBACOLOR(r,g,b,a) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]



#pragma mark - 其他
// 方正黑体简体字体定义

#define FONT(F) [UIFont fontWithName:@"FZHTJW--GB1-0" size:F]
// 定义一个API

#define APIURL                @"http://xxxxx/"
// 登录API

#define APILogin              [APIURL stringByAppendingString:@"Login"]
// 设置View的tag属性

#define VIEWWITHTAG(_OBJECT, _TAG)    [_OBJECT viewWithTag : _TAG]// 程序的本地化,引用国际化的文件

#define MyLocal(x, ...) NSLocalizedString(x, nil)
// G－C－D

#define BACK(block) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), block)

#define MAIN(block) dispatch_async(dispatch_get_main_queue(),block)
// NSUserDefaults 实例化

#define USER_DEFAULT [NSUserDefaults standardUserDefaults]
// 由角度获取弧度

#define degreesToRadian(x) (M_PI * (x) / 180.0)
// 由弧度获取角度

#define radianToDegrees(radian) (radian*180.0)/(M_PI)
// 单例化一个类

#define SYNTHESIZE_SINGLETON_FOR_CLASS(classname) \
\
static classname *shared##classname = nil; \
\

+ (classname *)shared##classname \
{ \
    
    @synchronized(self) \
    { \
        
        if (shared##classname == nil) \
        { \
            
            shared##classname = ［self alloc] init]; \
        } \
        
    } \
    \
    
    return shared##classname; \
} \
\

+ (id)allocWithZone:(NSZone *)zone \
{ \
    
    @synchronized(self) \
    { \
        
        if (shared##classname == nil) \
        { \
            
            shared##classname = [super allocWithZone:zone]; \
            return shared##classname; \
        } \
    } \
    \
    
    return nil; \
} \
\
- (id)copyWithZone:(NSZone *)zone \
{ \
    
    return self; \
}

#endif






#endif /* AnonymousMacro_h */
