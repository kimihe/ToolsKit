//
//  UIColor+KMColorHelper.h
//  Cubee
//
//  Created by 周祺华 on 2016/11/24.
//  Copyright © 2016年 周祺华. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (KMColorHelper)
/**
 *  返回随机颜色
 *
 *  @return 0x000000 - 0xFFFFFF间随机
 */
+ (UIColor *)randomColor;


/**
 *  在五种常见的颜色中随机选取(红，绿，蓝，黄，紫)
 *
 *  @return 返回颜色
 */
+ (UIColor *)randomFiveColor;

@end
