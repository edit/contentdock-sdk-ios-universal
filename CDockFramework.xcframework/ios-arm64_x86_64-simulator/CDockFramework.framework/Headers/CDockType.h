//
//  CDockType.h
//  contentDock SDK iOS
//
//  Created by Michael Schild
//  Copyright (c) 2016-2021 EDIT GmbH. All rights reserved.
//

#import <CDockFramework/CDockProject.h>


#pragma mark - Enums
/// @typedef @b CDockCallback
/// @brief Enums for the parameter type in the Callback @b CDockAppInstallationCallback
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/typedef#enum-CDockCallback
typedef NS_ENUM(NSInteger, CDockCallback) {
    /// Installation / Update of the contentDock App is in progress
    syncProgress,
    /// Installation / Update of the contentDock App is successfully completed
    syncSuccess,
    /// Installation / Update of the contentDock App is aborted
    syncFailed,
    /// Calculated time to complete installation / update of the contentDock App
    syncEstimate
} NS_SWIFT_NAME(CDockSDK.Callback);


/// @typedef @b CDockProjectState
/// @brief Enum for the return value of the SDK Function @b getProjectState
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/typedef#cDockProjectState
typedef NS_ENUM(NSInteger, CDockProjectState) {
    /// contentDock App is not installed locally
    none,
    /// contentDock App is currently being installed
    syncInProgress,
    /// contentDock App is installed / synchronized
    syncFinished,
    /// Installation was interrupted (app closed or connection problems)
    syncInterrupted,
    /// A new version is available for the contentDock App
    needUpdate
} NS_SWIFT_NAME(CDockSDK.ProjectState);


/// @typedef @b CDockResult
/// @brief Enum for the parameter in the SDK Function @b getCategories
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/typedef#enum-CDockResult
typedef NS_ENUM(NSInteger, CDockResult) {
    /// All main and sub categories are returned in an array (on the same level)
    resultPlain,
    /// All main categories are returned in an array. All sub-categories will be found in the respective main categories
    resultTree
} NS_SWIFT_NAME(CDockSDK.Result);


/// @typedef @b CDockSwipe
/// @brief Enum for the parameter in the SDK Function @b getProjectPageForSwipe
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/typedef#enum-CDockSwipe
typedef NS_ENUM(NSInteger, CDockSwipe) {
    /// Swipe up
    swipeUp,
    /// Swipe left
    swipeLeft,
    /// Swipe down
    swipeDown,
    /// Swipe right
    swipeRight
}  NS_SWIFT_NAME(CDockSDK.Swipe);


/// @typedef @b CDockSorting
/// @brief Enum for the parameter in the SDK Function @b getDataContainerRecordsForContainerId
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/typedef#enum-CDockSorting
typedef NS_ENUM(NSInteger, CDockSorting) {
    /// Sorting ascending of the DataContainer Records
    ascending,
    /// Sorting descending of the DataContainer Records
    descending
} NS_SWIFT_NAME(CDockSDK.Sorting);


#pragma mark - Callbacks
/// @typedef @b CDockAppInstallationCallback
/// @brief blockCallbacks parameter declaration for the @b CDockSDK.setBlockCallbacks function
/// @param type CDockCallback enum
/// @param userInfo NSDictionary with more callback information
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/typedef#enum-CDockAppInstallationCallback
typedef void (^CDockAppInstallationCallback)(CDockCallback type, NSDictionary *userInfo);


/// @typedef @b CDockUserLoginCallback
/// @brief blockCallbacks parameter declaration for the @b CDockSDK.loginUser function
/// @param success BOOL true if login successfully
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/typedef#enum-CDockUserLoginCallback
typedef void (^CDockUserLoginCallback)(BOOL success);


/// @typedef @b CDockLoadProjectCallback
/// @brief blockCallbacks parameter declaration for the function @b CDockSDK.getSingleModeProject and @b CDockSDK.getProject
/// @param projectObj CDockProject object
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/typedef#enum-CDockLoadProjectCallback
typedef void (^CDockLoadProjectCallback)(CDockProject *projectObj);

 
/// @typedef @b CDockLoadProjectsCallback
/// @brief blockCallbacks parameter declaration for the function @b CDockSDK.getPrivateProjectsFrom , @b CDockSDK.getPublicProjectsFrom and @b CDockSDK.getSearchProjectsFrom
/// @param arrProjects NSArray of CDockProject objects
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/typedef#enum-CDockLoadProjectsCallback
typedef void (^CDockLoadProjectsCallback)(NSArray *arrProjects);


/// @typedef @b CDockCountProjectsCallback
/// @brief blockCallbacks parameter declaration for the function @b CDockSDK.getPrivateProjectsCount and @b CDockSDK.getPublicProjectsCount
/// @param numberOfProjects as long
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/typedef#enum-CDockCountProjectsCallback
typedef void (^CDockCountProjectsCallback)(long numberOfProjects);


/// @typedef @b CDockLoadCategoriesCallback
/// @brief blockCallbacks parameter declaration for the function @b CDockSDK.getCategories
/// @param arrCategories NSArray of CDockCategory objects
/// @discussion https://www.contentdock.com/en/documentation/sdk-ios/classes/typedef#enum-CDockLoadCategoriesCallback
typedef void (^CDockLoadCategoriesCallback)(NSArray *arrCategories);

