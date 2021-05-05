//
//  CDockSDK.h
//  contentDock SDK iOS
//
//  Created by Michael Schild
//  Copyright (c) 2019 EDIT GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CDockFramework/CDockProjectModel.h>

@class CDockPageObject;
@class CDockDataContainer;
@class CDockDataContainerRecord;

typedef enum {
    syncProgress,
    syncSuccess,
    syncFailed,
    syncEstimate
} CDockSDKCallbackType;

typedef enum {
    none,
    syncInProgress,
    syncFinished,
    syncInterrupted,
    needUpdate
} CDDockSDKProjectState;

@interface CDockSDK : NSObject

#pragma mark - Callbacks
+ (void)setBlockCallbacks:(void (^)(CDockSDKCallbackType type, NSDictionary *userInfo))blockCallbacks;

#pragma mark - Connection
+ (BOOL)isConnectionOk;

#pragma mark - Device
+ (BOOL)isTablet;
+ (BOOL)isPhone;

#pragma mark - Call params
+ (NSArray *)arrParams;
+ (void)setArrParams:(NSArray *)arrParams;
+ (NSString *)path;
+ (void)setPath:(NSString *)path;
+ (NSString *)host;
+ (void)setHost:(NSString *)host;

#pragma mark - Login/out
+ (BOOL)isLoggedIn;
+ (void)logOut;
+ (void)loginWith:(NSString *)login password:(NSString *)password domain:(NSString *)domain blockOnComplete:(void (^)(BOOL success))blockOnComplete;
+ (NSString *)domain;


#pragma mark - Page
+ (CDockPageObject *)pageObjectForId: (NSString *)pageId;
+ (CDockPageObject *)rootObj;
+ (CDockPageObject *)curPageObj;
+ (CDockPageObject *)parentObj;

#pragma mark - Project/contentApp
+ (NSArray <CDockProjectModel *> *)arrLocalProjects;

+ (void)getProject:(int)projectId blockOnComplete:(void (^)(CDockProjectModel *projectModel))blockOnComplete;
+ (void)openProject:(CDockProjectModel *)projectModel;
+ (void)downloadProject:(CDockProjectModel *)projectModel;
+ (void)deleteLocalProject:(CDockProjectModel *)projectModel;
+ (int)curProjectId;

// Load Projects with selected categories
+ (void)getPrivateProjectsFrom:(int)start to:(int)end blockOnComplete:(void (^)(NSArray *arrProjects))blockOnComplete;
+ (void)getPublicProjectsFrom:(int)start to:(int)end blockOnComplete:(void (^)(NSArray *arrProjects))blockOnComplete;

// Load Projects without selected categories
+ (void)getAllPrivateProjectsFrom:(int)start to:(int)end blockOnComplete:(void (^)(NSArray *arrProjects))blockOnComplete;
+ (void)getAllPublicProjectsFrom:(int)start to:(int)end blockOnComplete:(void (^)(NSArray *arrProjects))blockOnComplete;

// Search projects
+ (void)getSearchProjectsFrom:(int)start to:(int)end searchString:(NSString *)searchString categoriesIds:(NSArray *)arrCategoriesIds blockOnComplete:(void (^)(NSArray *arrProjects))blockOnComplete;

+ (CDDockSDKProjectState)projectState:(CDockProjectModel *)projectModel;

+ (NSString *)childrenIdsForPageWithId: (NSString *)pageId;
+ (NSArray *)childrenPagesForPageWithId: (NSString *)pageId;

+ (CDockPageObject *)pageIdForSwipe: (NSString *)direction pageId:(NSString *)pageId;
+ (void)switchToPageWithId:(NSString *)pageId;

+ (NSString *)projectAssetsPath;
+ (NSString *)projectHTMLDataPath;

#pragma mark - Categories
+ (void)getCategories:(void (^)(NSArray *arrCategories))blockOnComplete;
+ (NSMutableArray<NSNumber *> *)arrSelectedCategories;
+ (void)setArrSelectedCategories:(NSArray *)arrCategories;

#pragma mark - Data Container
+ (NSArray <CDockDataContainer *> *)getDataContainerList;
+ (NSArray <NSDictionary *> *)getDataContainerRecordsForElementByPageId:(NSString *)pageId elementId:(NSString *)elementId orderBy:(NSString *)orderBy orderDirection:(NSString *)orderDirection;
+ (NSArray <NSString *> *)getDataContainerFieldsForContainerId:(NSString *)containerId;
+ (NSArray <CDockDataContainerRecord *> *)getDataContainerRecordsByContainerId:(NSString *)containerId orderBy:(NSString *)orderBy orderDirection:(NSString *)orderDirection;


#pragma mark - Elements
+ (void)showPDF:(NSString *)fileName;

#pragma mark - Customs
+ (void)showCustomVC:(UIViewController *)vc;


@end
