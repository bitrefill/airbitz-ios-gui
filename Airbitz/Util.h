//
//  Util.h
//  AirBitz
//
//  Created by Adam Harris on 5/19/14.
//  Copyright (c) 2014 AirBitz. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AddressBookUI/AddressBookUI.h>
#import "AirbitzCore.h"

@import Foundation.NSString;

@class AirbitzViewController;

#define UIColorFromRGB(rgbValue) \
        [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
                        green:((float)((rgbValue & 0x00FF00) >>  8))/255.0 \
                         blue:((float)((rgbValue & 0x0000FF) >>  0))/255.0 \
                        alpha:1.0]

#define UIColorFromARGB(rgbValue) \
        [UIColor colorWithRed:((float)((rgbValue & 0x00FF0000) >> 16))/255.0 \
                        green:((float)((rgbValue & 0x0000FF00) >>  8))/255.0 \
                         blue:((float)((rgbValue & 0x000000FF) >>  0))/255.0 \
                        alpha:((float)((rgbValue & 0xFF000000) >> 24))/255.0]

#define expenseCategoryColon    [NSString stringWithFormat:@"%@:", abcStringExpenseCategory]
#define incomeCategoryColon     [NSString stringWithFormat:@"%@:", abcStringIncomeCategory]
#define transferCategoryColon   [NSString stringWithFormat:@"%@:", abcStringTransferCategory]
#define exchangeCategoryColon   [NSString stringWithFormat:@"%@:", abcStringExchangeCategory]

#define ARRAY_CATEGORY_PREFIXES         @[expenseCategoryColon,incomeCategoryColon,transferCategoryColon,exchangeCategoryColon]
#define ARRAY_CATEGORY_PREFIXES_NOCOLON @[abcStringExpenseCategory,abcStringIncomeCategory,abcStringTransferCategory,abcStringExchangeCategory]

@interface Util : NSObject

+ (void)resizeView:(UIView *)theView withDisplayView:(UIView *)theDisplayView;
+ (NSString *)getNameFromAddressRecord:(ABRecordRef)person;
+ (void)callTelephoneNumber:(NSString *)telNum;
+ (void)stylizeTextField:(UITextField *)textField;
+ (void)stylizeTextView:(UITextView *)textField;
+(CGRect)currentScreenBoundsDependOnOrientation;


+ (UIViewController *)animateIn:(NSString *)identifier parentController:(UIViewController *)parent;
+ (UIViewController *)animateIn:(NSString *)identifier storyboard:(NSString *)storyboardName parentController:(UIViewController *)parent;
+ (UIViewController *)animateController:(UIViewController *)controller parentController:(UIViewController *)parent;
+ (void)animateOut:(UIViewController *)controller parentController:(UIViewController *)parent complete:(void(^)(void))cb;
+ (void)animateControllerFadeOut:(UIViewController *)viewController;
+ (void)animateControllerFadeIn:(UIViewController *)viewController;

+ (void)checkPasswordAsync:(NSString *)password withSelector:(SEL)selector controller:(UIViewController *)controller;
+ (NSString *)urlencode:(NSString *)url;
+ (NSMutableDictionary *)getUrlParameters:(NSURL *)url;
+ (BOOL)isValidCategory:(NSString *)category;
+ (NSArray *)insertSubviewControllerWithConstraints:(AirbitzViewController *)parentViewController child:(AirbitzViewController *)childViewController belowSubView:(UIView *)belowView;
+ (NSArray *)insertSubviewControllerWithConstraints:(AirbitzViewController *)parentViewController child:(AirbitzViewController *)childViewController aboveSubView:(UIView *)aboveView;
+ (NSArray *)addSubviewControllerWithConstraints:(AirbitzViewController *)parentViewController child:(AirbitzViewController *)childViewController;
+ (NSArray *)addSubviewWithConstraints:(UIView *)parentView child:(UIView *)childView;
+ (void)replaceHtmlTags:(NSString **) strContent;
+ (NSString *)checkPasswordResultsMessage:(ABCPasswordRuleResult *)result;


@end
