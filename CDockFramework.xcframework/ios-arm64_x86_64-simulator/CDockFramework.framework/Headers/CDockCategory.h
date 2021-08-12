//
//  CDCategory.h
//  contentDock SDK iOS
//
//  Created by Michael Schild
//  Copyright (c) 2016-2021 EDIT GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CDCategory;

@interface CDockCategory : NSObject
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *imageURL;
@property (nonatomic) int categoryId;
@property (nonatomic) int categoryMainId;
@property (nonatomic) int sorting;
@property (nonatomic) BOOL private;
@property (nonatomic, strong) NSMutableArray<NSString *> *arrProjectSorting;
@property (nonatomic, strong) NSMutableArray<CDockCategory *> *arrSubCategories;


- (CDockCategory *)initWithCDCategory:(CDCategory *)category;
@end
 
