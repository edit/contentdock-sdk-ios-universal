//
//  DataContainerRecord.h
//  contentDock SDK iOS
//
//  Created by Michael Schild
//  Copyright (c) 2019 EDIT GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CDockDataContainerRecord : NSObject
@property (nonatomic, strong) NSDictionary *dictItem;
@property (nonatomic, strong) NSString *pageId;
@property (nonatomic, strong) NSString *elementId;
@end
