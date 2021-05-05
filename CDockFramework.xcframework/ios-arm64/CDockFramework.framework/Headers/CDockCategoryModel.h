//
//  UIImageView+S3.h
//  contentDock SDK iOS
//
//  Created by Michael Schild
//  Copyright (c) 2019 EDIT GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CDCategory;

@interface CDockCategoryModel : NSObject
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *imageURL;
@property (nonatomic) int categoryId;
@property (nonatomic) int categoryMainId;
@property (nonatomic) int sorting;
@property (nonatomic) BOOL private;
@property (nonatomic, strong) NSMutableArray<NSString *> *arrProjectSorting;


- (CDockCategoryModel *)initWithCDCategory:(CDCategory *)category;
@end
 
