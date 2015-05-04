//
//  Theme.m
//  AirBitz
//
//  Created by Paul Puey on 5/2/15.
//  Copyright (c) 2015 AirBitz. All rights reserved.
//

#import "Theme.h"
#import "Util.h"

static BOOL bInitialized = NO;

@implementation Theme

static Theme *singleton = nil;  // this will be the one and only object this static singleton class has

+ (void)initAll
{
    if (NO == bInitialized)
    {
        singleton = [[Theme alloc] init];
        bInitialized = YES;
    }
}

+ (void)freeAll
{
    if (YES == bInitialized)
    {
        // release our singleton
        singleton = nil;
        
        bInitialized = NO;
    }
}

+ (Theme *)Singleton
{
    return singleton;
}

- (id)init
{
    self = [super init];

    //    self.denomination = 100000000;
    self.colorTextLink = UIColorFromARGB(0xFF007aFF);
    self.deleteAccountWarning = NSLocalizedString(@"Delete '%@' on this device? This will disable access via PIN. If 2FA is enabled on this account, this device will not be able to login without a 2FA reset which takes 7 days.", @"Delete Account Warning");

    if (IS_IPHONE4)
    {
        self.heightListings = 90.0;
        self.heightSearchClues = 35.0;
    }
    else if (IS_IPHONE5)
    {
        self.heightListings = 110.0;
        self.heightSearchClues = 40.0;
    }
    else if (IS_IPHONE6)
    {
        self.heightListings = 120.0;
        self.heightSearchClues = 45.0;
    }
    else if (IS_IPHONE6_PLUS || IS_IPAD)
    {
        self.heightListings = 130.0;
        self.heightSearchClues = 45.0;
    }

    return self;
}

@end