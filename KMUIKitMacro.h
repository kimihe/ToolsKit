//
//  KMUIKitMacro.h
//  KMNineBoxDemo
//
//  Created by 周祺华 on 2016/10/28.
//  Copyright © 2016年 周祺华. All rights reserved.
//

#ifndef KMUIKitMacro_h
#define KMUIKitMacro_h

//获取屏幕 宽度、高度
#define kSCREEN_WIDTH          ([UIScreen mainScreen].bounds.size.width)             //!< UIScreen宽度
#define kSCREEN_HEIGHT         ([UIScreen mainScreen].bounds.size.height)            //!< UIScreen高度

//16进制表示RGBA
#define colorFromRGBA(rgbValue,trans) [UIColor \
                colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
                         green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
                         blue:((float)(rgbValue & 0xFF))/255.0 alpha:trans]



#pragma mark - Weakify/strongify

/**
 Synthsize a weak or strong reference.
 
 Example:
    @weakify(self)
        [self doSomething^{
    @strongify(self)
        if (!self) return;
        ...
    }];
 
 */
#ifndef weakify
    #if DEBUG
        #if __has_feature(objc_arc)
            #define weakify(object) autoreleasepool{} __weak __typeof__(object) weak##_##object = object;
        #else
            #define weakify(object) autoreleasepool{} __block __typeof__(object) block##_##object = object;
        #endif
    #else
        #if __has_feature(objc_arc)
            #define weakify(object) try{} @finally{} {} __weak __typeof__(object) weak##_##object = object;
    #else
        #define weakify(object) try{} @finally{} {} __block __typeof__(object) block##_##object = object;
        #endif
    #endif
#endif

#ifndef strongify
    #if DEBUG
        #if __has_feature(objc_arc)
            #define strongify(object) autoreleasepool{} __typeof__(object) object = weak##_##object;
        #else
            #define strongify(object) autoreleasepool{} __typeof__(object) object = block##_##object;
        #endif
    #else
        #if __has_feature(objc_arc)
            #define strongify(object) try{} @finally{} __typeof__(object) object = weak##_##object;
        #else
            #define strongify(object) try{} @finally{} __typeof__(object) object = block##_##object;
        #endif
    #endif
#endif



#endif /* KMUIKitMacro_h */
