//
//  UIColor+KMColorHelper.m
//  Cubee
//
//  Created by 周祺华 on 2016/11/24.
//  Copyright © 2016年 周祺华. All rights reserved.
//

#import "UIColor+KMColorHelper.h"
#import "KMMathHelper.h"

@implementation UIColor (KMColorHelper)

+ (UIColor *)randomColor
{
    CGFloat red = [KMMathHelper getRandBetween:0 and:255];
    CGFloat green = [KMMathHelper getRandBetween:0 and:255];
    CGFloat blue = [KMMathHelper getRandBetween:0 and:255];
    
    return [UIColor colorWithRed:red/255.0
                           green:green/255.0
                            blue:blue/255.0 alpha:1.0];

}

+ (UIColor *)randomFiveColor
{
    switch (arc4random()%5) {
            
        case 0: return [UIColor redColor];
        case 1: return [UIColor blueColor];
        case 2: return [UIColor yellowColor];
        case 3: return [UIColor greenColor];
        case 4: return [UIColor purpleColor];
            
    }
    return [UIColor blackColor];
}

@end
