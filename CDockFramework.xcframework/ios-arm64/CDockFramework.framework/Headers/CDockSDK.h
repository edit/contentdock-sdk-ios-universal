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

#pragma mark - Init
/// Init the contentDock SDK
+ (void)initFramework;
/// Register the general project presentation vc
+ (void)registerGeneralProjectVc:(UIViewController *)vc;

#pragma mark - Validation
/// The contentDock SDK Key authoriztion. For the SDK multi mode activate the SDK in your Account Settings. For Single mode in the Project Settings. The Key must be set in the CDockSettings.plist.
+ (void)authorizedSDKKey;

#pragma mark - Callbacks
/// SDK Callbacks for Project download synchronization
+ (void)setBlockCallbacks:(void (^)(CDockSDKCallbackType type, NSDictionary *userInfo))blockCallbacks;

#pragma mark - Connection
/// Get back, if a internet connection is available
+ (BOOL)isConnectionOk;

#pragma mark - Device
/// Get back, is your Device a Tablet
+ (BOOL)isTablet;
/// Get back, is your Device a Phone
+ (BOOL)isPhone;

#pragma mark - Call params
/// Set the SDK values (host, path, params), when your App will open with an URL
+ (void)handleSchemeURL:(NSURL *)url;
/// Get the params from an open URL
+ (NSArray *)arrParams;
/// Set the params from an open URL
+ (void)setArrParams:(NSArray *)arrParams;
/// Get the path from an open URL
+ (NSString *)path;
/// Set the path from an open URL
+ (void)setPath:(NSString *)path;
/// Get the host from an open URL
+ (NSString *)host;
/// Set the host from an open URL
+ (void)setHost:(NSString *)host;

#pragma mark - Login/out
/// Check is an user logged in
+ (BOOL)isLoggedIn;
/// Logout an active user
+ (void)logOut;
/// Login an user
+ (void)loginWith:(NSString *)login password:(NSString *)password domain:(NSString *)domain blockOnComplete:(void (^)(BOOL success))blockOnComplete;
/// Get the contentDock Domain from your CDockSettings.plist
+ (NSString *)domain;


#pragma mark - Page
/// Get back a CDockPageObject for an ID of your project
+ (CDockPageObject *)pageObjectForId: (NSString *)pageId;
/// Get back the CDockPageObject for the root of your project
+ (CDockPageObject *)rootObj;
/// Get back the CDockPageObject for the current Page of your project
+ (CDockPageObject *)curPageObj;
/// Get back the CDockPageObject for the parent Page from the current Page of your project
+ (CDockPageObject *)parentObj;
/// Get CDockPageObject for swipe direction
+ (CDockPageObject *)pageIdForSwipe: (NSString *)direction pageId:(NSString *)pageId;
/// Switch to Page id
+ (void)switchToPageWithId:(NSString *)pageId;
/// Get back the childeren Ids as comma separated String for a page id
+ (NSString *)childrenIdsForPageWithId: (NSString *)pageId;
/// Get back the childeren pages as Array of CDockPageObject for a page id
+ (NSArray *)childrenPagesForPageWithId: (NSString *)pageId;


#pragma mark - Project/contentApp
// Single Mode functions
/// Get single mode project information
+ (void)getSingleModeProject:(void (^)(CDockProjectModel *projectModel))blockOnComplete;
/// Open the single mode project
+ (void)openSingleModeProject;

// Multi Mode functions
/// Get back an Array of all downloaded projects
+ (NSArray <CDockProjectModel *> *)arrLocalProjects;
/// Get Project information
+ (void)getProject:(int)projectId blockOnComplete:(void (^)(CDockProjectModel *projectModel))blockOnComplete;
/// Open a Project
+ (void)openProject:(CDockProjectModel *)projectModel;
/// Download a Project
+ (void)downloadProject:(CDockProjectModel *)projectModel;
/// Delete a downloaded project locally
+ (void)deleteLocalProject:(CDockProjectModel *)projectModel;
/// Get back the current project id
+ (int)curProjectId;
/// Get the current Project state
+ (CDDockSDKProjectState)projectState:(CDockProjectModel *)projectModel;
/// Get back the project assete path
+ (NSString *)projectAssetsPath;
/// Get back the HTML data Path for the webview elements
+ (NSString *)projectHTMLDataPath;

// Load Projects with selected categories
/// Get all private projects with the saved selected categories
+ (void)getPrivateProjectsFrom:(int)start to:(int)end blockOnComplete:(void (^)(NSArray *arrProjects))blockOnComplete;
/// Get all public projects with the saved selected categories
+ (void)getPublicProjectsFrom:(int)start to:(int)end blockOnComplete:(void (^)(NSArray *arrProjects))blockOnComplete;

// Load Projects without selected categories
/// Get all private projects
+ (void)getAllPrivateProjectsFrom:(int)start to:(int)end blockOnComplete:(void (^)(NSArray *arrProjects))blockOnComplete;
/// Get all public projects
+ (void)getAllPublicProjectsFrom:(int)start to:(int)end blockOnComplete:(void (^)(NSArray *arrProjects))blockOnComplete;

// Search projects
/// Search Projects with a keywords and categories
+ (void)getSearchProjectsFrom:(int)start to:(int)end searchString:(NSString *)searchString categoriesIds:(NSArray *)arrCategoriesIds blockOnComplete:(void (^)(NSArray *arrProjects))blockOnComplete;


#pragma mark - Categories
/// Load all your Project categories
+ (void)getCategories:(void (^)(NSArray *arrCategories))blockOnComplete;
/// Get back the saved selected categories
+ (NSMutableArray<NSNumber *> *)arrSelectedCategories;
/// Save the selected categories
+ (void)setArrSelectedCategories:(NSArray *)arrCategories;

#pragma mark - Data Container
/// Get back an Array of all DataContainers in your contentDock account
+ (NSArray <CDockDataContainer *> *)getDataContainerList;
/// Get back all records of an DataContainer for a page id and element id with an order
+ (NSArray <NSDictionary *> *)getDataContainerRecordsForElementByPageId:(NSString *)pageId elementId:(NSString *)elementId orderBy:(NSString *)orderBy orderDirection:(NSString *)orderDirection;
/// Get back all fields of an DataContainer ID
+ (NSArray <NSString *> *)getDataContainerFieldsForContainerId:(NSString *)containerId;
/// Get back all records of an DataContainer ID with an order
+ (NSArray <CDockDataContainerRecord *> *)getDataContainerRecordsByContainerId:(NSString *)containerId orderBy:(NSString *)orderBy orderDirection:(NSString *)orderDirection;

#pragma mark - Elements
/// Open the included contentDock PDF viewer for a PDF file
+ (void)showPDF:(NSString *)fileName;

@end
