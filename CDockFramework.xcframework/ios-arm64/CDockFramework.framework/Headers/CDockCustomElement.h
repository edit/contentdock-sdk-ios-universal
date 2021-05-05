//
//  UserCustomElement.h
//  contentDock Core + SDK iOS
//
//  Created by Michael Schild
//  Copyright (c) 2019 EDIT GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CDockCustomElement : UIView
@property (nonatomic, strong) NSString *functionName;
@property (nonatomic, strong) NSString *elementId;
@property (nonatomic, strong) NSString *pageId;
@end
