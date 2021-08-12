//
//  CDockSDK.h
//  contentDock SDK iOS
//
//  Created by Michael Schild
//  Copyright (c) 2016-2021 EDIT GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CDockFramework/CDockProject.h>
#import <CDockFramework/CDockType.h>

@class CDockPage;
@class CDockDataContainer;
@class CDockDataContainerRecord;

@interface CDockSDK : NSObject


#pragma mark - Init
/// @function @b initFramework
/// @brief The @b initFramework method is required as @b first. Basic functions in the SDK are prepared here.
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#initFramework
+ (void)initFramework;


/// @function @b registerGeneralProjectVc
/// @brief The method @b registerGeneralProjectVc is required to be called. As a parameter, specify the UIViewController that will be used to view the @b contentDock InApp projects. The method can be called directly after the @b initFramework method.
/// @param vc  UIViewController
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#registerGeneralProjectVc
+ (void)registerGeneralProjectVc:(UIViewController *)vc;


#pragma mark - Validation
/// @function @b authorizedSDKKey
/// @brief The @b authorizedSDKKey method is not required but recommended and should be called after the @b initFramework method. In this function your SDK key will be checked. If you do not call this function, then the SDK Key will be checked automatically when calling further SDK functions. The check is performed only once each time your app is started. We recommend to call this function directly, because then you will be informed via the callback @b cDockGrantedAuthorization if the key is ok or @b cDockFailedAuthorization when the key is wrong. The method requires an active Internet connection. For the SDK multi mode activate the SDK in your Account Settings in the @b contentDock Management System. For Single mode in the Project Settings in the @b contentDock Management System. The activated Key must be set in the @b CDockSettings.plist.
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#authorizedSDKKey
+ (void)authorizedSDKKey;


#pragma mark - Callbacks
/// @function @b setBlockCallbacks
/// @brief The @b setBlockCallbacks method is important for downloading a @b contentDock InApp project asynchronous. The SDK informs you about the current status of the download. If a download is interrupted, the SDK will try to restart automatically at the position where the download was aborted.
/// @param blockCallbacks CDockAppInstallationCallback typedef - this block will be invoke often in the download process of an @b contentDock App
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#setBlockCallbacks
 + (void)setBlockCallbacks:(CDockAppInstallationCallback)blockCallbacks;


#pragma mark - Connection
/// @function @b isConnectionOk
/// @brief You can simply check if you are online with the @b isConnectionOk method.
/// @return BOOL true when the connection is OK
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#isConnectionOk
+ (BOOL)isConnectionOk;


#pragma mark - Device
/// @function @b isTablet
/// @brief You can simply check if the used device is a tablet using the @b isTablet method.
/// @return BOOL true when the Device is an Tablet
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#isTablet
 + (BOOL)isTablet;


/// @function @b isPhone
/// @brief You can simply check if the used device is a smartphone using the @b isPhone method.
/// @return BOOL true when the Device is an Phone
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#isPhone
+ (BOOL)isPhone;


#pragma mark - Launch URL
/// @function @b handleLaunchURL
/// @brief Set the SDK values (host, path, params), when your App will open with an URL
/// @param url NSURL for the app launch
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#handleLaunchURL
+ (void)handleLaunchURL:(NSURL *)url NS_SWIFT_NAME(handleLaunchURL(url:));


/// @function @b getLaunchParams
/// @brief Get the params from an open URL
/// @return NSArray of the URL Params
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#getLaunchParams
+ (NSArray *)getLaunchParams;


/// @function @b getLaunchPath
/// @brief Get the path from an open URL
/// @return NSString of the URL Path
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#getLaunchPath
+ (NSString *)getLaunchPath;


/// @function @b getLaunchHost
/// @brief Get the host from an open URL
/// @return NSString of the URL Host
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#getLaunchHost
+ (NSString *)getLaunchHost;

#pragma mark - User Login/out
/// @function @b isLoggedIn
/// @brief With these methods you can check if a user is logged in.
/// @return BOOL of the login status
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#isLoggedIn
+ (BOOL)isLoggedIn;


/// @function @b logoutUser
/// @brief Logout an active user
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#logoutUser
+ (void)logoutUser;


/// @function @b loginUser
/// @brief With the login method you can start the login asynchronous. The session handling is completely handled by the @b contentDock SDK.
/// @param login NSString of the username (email)
/// @param password NSString of the password
/// @param blockOnComplete CDockUserLoginCallback typedef
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#loginUser
+ (void)loginUser:(NSString *)login password:(NSString *)password blockOnComplete:(CDockUserLoginCallback)blockOnComplete NS_SWIFT_NAME(loginUser(user:password:blockOnComplete:));


#pragma mark - Project / InApp Page
/// @function @b getProjectRootPage
/// @brief Get back the @b CDockPage object for the root of your project
/// @return CDockPage Object
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#getProjectRootPage
+ (CDockPage *)getProjectRootPage;


/// @function @b getProjectCurrentPage
/// @brief Get back the @b CDockPage object for the current Page of your active project
/// @return CDockPage Object
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#getProjectCurrentPage
+ (CDockPage *)getProjectCurrentPage;


/// @function @b getProjectParentPage
/// @brief Get back the @b CDockPage object for the parent Page from the current Page of your active project
/// @return CDockPage Object
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#getProjectParentPage
+ (CDockPage *)getProjectParentPage;


/// @function @b getProjectPageForId
/// @brief Get back a CDockPage Object for an page ID of your active project
/// @param pageId NSString of the page Id
/// @return CDockPage Object
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#getProjectPageForId
+ (CDockPage *)getProjectPageForId:(NSString *)pageId NS_SWIFT_NAME(getProjectPageForId(pageId:));


/// @function @b getProjectPageForSwipe
/// @brief Get CDockPage object for swipe direction
/// @param swipeType CDockSwipe
/// @param pageId NSString of the page Id
/// @return CDockPage Object
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#getProjectPageForSwipe
+ (CDockPage *)getProjectPageForSwipe:(CDockSwipe)swipeType pageId:(NSString *)pageId NS_SWIFT_NAME(getProjectPageForSwipe(swipeType:pageId:));


/// @function @b getSubPageIdsForProjectPageId
/// @brief Get back the sub page Ids as comma separated String for a page id
/// @param pageId NSString of the page Id
/// @return NSString sub page Ids as comma separated
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#getSubPageIdsForProjectPageId
+ (NSString *)getSubPageIdsForProjectPageId:(NSString *)pageId NS_SWIFT_NAME(getSubPageIdsForProjectPageId(pageId:));


/// @function @b getSubPagesForProjectPageId
/// @brief Get back the sub pages as Array of CDockPage objects for a page id
/// @param pageId NSString of the page Id
/// @return NSArray of CDockPage objects
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#getSubPagesForProjectPageId
+ (NSArray *)getSubPagesForProjectPageId:(NSString *)pageId NS_SWIFT_NAME(getSubPagesForProjectPageId(pageId:));


/// @function @b switchToProjectPageId
/// @brief With this function you can directly open the page to the required page ID.
/// @param pageId NSString of the page Id
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#switchToProjectPageId
+ (void)switchToProjectPageId:(NSString *)pageId NS_SWIFT_NAME(switchToProjectPageId(pageId:));


#pragma mark - Project/InApp (Single Mode)
/// @function @b getSingleModeProject
/// @brief Get single mode contentDock project information asynchronous
/// @param blockOnComplete CDockLoadProjectCallback typedef
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#getSingleModeProject
+ (void)getSingleModeProject:(CDockLoadProjectCallback)blockOnComplete NS_SWIFT_NAME(getSingleModeProject(blockOnComplete:));


/// @function @b openSingleModeProject
/// @brief Open the single mode contentDock project
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#openSingleModeProject
+ (void)openSingleModeProject;


#pragma mark - Project/InApp (Multi Mode)

/// @function @b getProject
/// @brief Get contentDock project information asynchronous
/// @param projectId Int of the contentDock project Id
/// @param blockOnComplete CDockLoadProjectCallback typedef
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#getProject
+ (void)getProject:(int)projectId blockOnComplete:(CDockLoadProjectCallback)blockOnComplete NS_SWIFT_NAME(getProject(projectId:blockOnComplete:));


/// @function @b getProjectState
/// @brief Get the current Project state
/// @param projectObj CDockProject object
/// @return CDockProjectState typedef
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#getProjectState
+ (CDockProjectState)getProjectState:(CDockProject *)projectObj NS_SWIFT_NAME(getProjectState(projectObj:));


/// @function @b openProject
/// @brief Open/Launch a contentDock project
/// @param projectObj CDockProject object
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#openProject
+ (void)openProject:(CDockProject *)projectObj NS_SWIFT_NAME(openProject(projectObj:));


/// @function @b downloadProject
/// @brief Download a contentDock project
/// @param projectObj CDockProject object
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#downloadProject
+ (void)downloadProject:(CDockProject *)projectObj NS_SWIFT_NAME(downloadProject(projectObj:));


/// @function @b deleteLocalProject
/// @brief Delete a downloaded project locally on the device
/// @param projectObj CDockProject object
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#deleteLocalProject
+ (void)deleteLocalProject:(CDockProject *)projectObj NS_SWIFT_NAME(deleteLocalProject(projectObj:));


/// @function @b getCurrentProjectId
/// @brief Get back the current active project id
/// @return Project id as Int
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#getCurrentProjectId
+ (int)getCurrentProjectId;


/// @function @b getCurrentProjectAssetsPath
/// @brief With this function you can get the local asset path of the current active project on the device.
/// @return NSString of the Path
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#getCurrentProjectAssetsPath
+ (NSString *)getCurrentProjectAssetsPath;


/// @function @b getCurrentProjectHTMLDataPath
/// @brief With this function you get the local path of the downloaded project RTE / Webview elements on the device. This function is needed e.g. if you use the field type RTE in a data container and want to access the HTML data. All HTML data from the RTE / Webview element will be saved as a zip file in this folder.
/// @return NSString of the Path
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#getCurrentProjectHTMLDataPath
+ (NSString *)getCurrentProjectHTMLDataPath;


#pragma mark - Projects/InApps (Multi Mode)

/// @function @b getPrivateProjectsFrom
/// @brief Get all private projects
/// @param start Int of the project range
/// @param end Int of the project range
/// @param skipCategories if true - ignore the selected categories array
/// @param blockOnComplete CDockLoadProjectsCallback typedef
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#getPrivateProjectsFrom
+ (void)getPrivateProjectsFrom:(int)start to:(int)end skipCategories:(Boolean)skipCategories blockOnComplete:(CDockLoadProjectsCallback)blockOnComplete NS_SWIFT_NAME(getPrivateProjectsFrom(start:end:skipCategories:blockOnComplete:));


/// @function @b getPublicProjectsFrom
/// @brief Get all public projects
/// @param start Int of the project range
/// @param end Int of the project range
/// @param skipCategories if true - ignore the selected categories array
/// @param blockOnComplete CDockLoadProjectsCallback typedef
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#getPublicProjectsFrom
+ (void)getPublicProjectsFrom:(int)start to:(int)end skipCategories:(Boolean)skipCategories blockOnComplete:(CDockLoadProjectsCallback)blockOnComplete NS_SWIFT_NAME(getPublicProjectsFrom(start:end:skipCategories:blockOnComplete:));


/// @function @b getPrivateProjectsCount
/// @brief Get the count of all private projects
/// @param skipCategories if true - ignore the selected categories array
/// @param blockOnComplete CDockCountProjectsCallback typedef
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#getPrivateProjectsCount
+ (void)getPrivateProjectsCount:(Boolean)skipCategories blockOnComplete:(CDockCountProjectsCallback)blockOnComplete NS_SWIFT_NAME(getPrivateProjectsCount(skipCategories:blockOnComplete:));


/// @function @b getPublicProjectsCount
/// @brief Get the count of all public projects
/// @param skipCategories if true - ignore the selected categories array
/// @param blockOnComplete CDockCountProjectsCallback typedef
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#getPublicProjectsCount
+ (void)getPublicProjectsCount:(Boolean)skipCategories blockOnComplete:(CDockCountProjectsCallback)blockOnComplete NS_SWIFT_NAME(getPublicProjectsCount(skipCategories:blockOnComplete:));


/// @function @b getLocalProjects
/// @brief Get back an Array of all downloaded projects
/// @return NSArray of CDockProject objects
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#getLocalProjects
+ (NSArray <CDockProject *> *)getLocalProjects;


/// @function @b getSearchProjectsFrom
/// @brief Search Projects with a keywords and categories
/// @param start Int of the project range
/// @param end Int of the project range
/// @param searchString NSString of the search keyword
/// @param arrCategories NSArray of the category Ids in that contentDock search
/// @param blockOnComplete CDockLoadProjectsCallback typedef
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#getSearchProjectsFrom
+ (void)getSearchProjectsFrom:(int)start to:(int)end searchString:(NSString *)searchString arrCategories:(NSArray *)arrCategories blockOnComplete:(CDockLoadProjectsCallback)blockOnComplete NS_SWIFT_NAME(getSearchProjectsFrom(start:end:searchString:arrCategories:blockOnComplete:));


#pragma mark - Project Tags / Categories
/// @function @b getCategories
/// @brief Load all your Project categories
/// @param resultType CDockResult typedef
/// @param blockOnComplete CDockLoadCategoriesCallback typedef
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#getCategories
+ (void)getCategories:(CDockResult)resultType blockOnComplete:(CDockLoadCategoriesCallback)blockOnComplete NS_SWIFT_NAME(getCategories(resultType:blockOnComplete:));


/// @function @b getSelectedCategories
/// @brief Get back the saved selected categories
/// @return NSArray with the category Ids
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#getSelectedCategories
+ (NSMutableArray<NSNumber *> *)getSelectedCategories;


/// @function @b setSelectedCategories
/// @brief Save the selected categories
/// @param arrCategories NSArray with the category Ids
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#setSelectedCategories
+ (void)setSelectedCategories:(NSArray *)arrCategories NS_SWIFT_NAME(setSelectedCategories(arrCategories:));


#pragma mark - DataContainer
/// @function @b getDataContainers
/// @brief Get back an Array of all DataContainers in your contentDock account
/// @return NSArray of CDockDataContainer objects
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#getDataContainers
+ (NSArray <CDockDataContainer *> *)getDataContainers;


/// @function @b getDataContainerFieldsForContainerId
/// @brief With this function you get the list of all configured fields for the required DataContainer ID.
/// @param containerId NSString of the DataContainer ID
/// @return NSArray with the NSString field names
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#getDataContainerFieldsForContainerId
+ (NSArray <NSString *> *)getDataContainerFieldsForContainerId:(NSString *)containerId NS_SWIFT_NAME(getDataContainerFieldsForContainerId(containerId:));

/// @function @b getDataContainerRecordsForContainerId
/// @brief Get back all records of an DataContainer ID with an order
/// @param containerId NSString of the DataContainer ID
/// @param orderBy field name of the DataContainer for the sorting
/// @param orderDirection CDockSorting typedef
/// @return NSArray of CDockDataContainerRecord objects
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#getDataContainerRecordsForContainerId
+ (NSArray <CDockDataContainerRecord *> *)getDataContainerRecordsForContainerId:(NSString *)containerId orderBy:(NSString *)orderBy orderDirection:(CDockSorting)orderDirection NS_SWIFT_NAME(getDataContainerRecordsForContainerId(containerId:orderBy:orderDirection:));


/// @function @b getDataContainerRecordsForSdkElementId
/// @brief In contentDock you can use an SDK element for individual developments. For each SDK element, you can define the data containers used and the condition for the data container records in the contentDock management system. With these functions you get the DataContainer records for a SDK element.
/// @param elementId NSString of the element ID
/// @param pageId NSString of the page ID
/// @param orderBy field name of the DataContainer for the sorting
/// @param orderDirection CDockSorting typedef
/// @return NSArray with NSDictionary objects
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#getDataContainerRecordsForSdkElementId
+ (NSArray <NSDictionary *> *)getDataContainerRecordsForSdkElementId:(NSString *)elementId pageId:(NSString *)pageId orderBy:(NSString *)orderBy orderDirection:(CDockSorting)orderDirection NS_SWIFT_NAME(getDataContainerRecordsForSdkElementId(elementId:pageId:orderBy:orderDirection:));


#pragma mark - Elements
/// @function @b showPDF
/// @brief Open the included contentDock PDF viewer for a PDF file
/// @param fileName Path to the PDF file
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/cdocksdk#showPDF
+ (void)showPDF:(NSString *)fileName;


@end
