//
//  ProjectModel.h
//  contentDock SDK iOS
//
//  Created by Michael Schild
//  Copyright (c) 2016-2021 EDIT GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CDockProjectImprint;
@class CDockProjectImage;

@interface CDockProject : NSObject

@property (nonatomic, strong) NSDictionary *dictProject;

@property (nonatomic, strong) NSString *projectDetails;
@property (nonatomic, strong) NSString *releasedDate;
@property (nonatomic, strong) NSString *updatedAt;
@property (nonatomic, strong) NSString *publishDate;
@property (nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *tags;
@property (nonatomic, strong) NSString *tagIds;
@property (nonatomic, strong) NSString *projectDescription;
@property (nonatomic, strong) NSString *version;
@property (nonatomic, strong) NSString *versionLocal;
@property (nonatomic, strong) NSString *size;
@property (nonatomic, strong) NSString *mainImage;
@property (nonatomic) int projectId;
@property (nonatomic) BOOL ageFlag;
@property (nonatomic) BOOL locked;
@property (nonatomic) BOOL isPreview;
@property (nonatomic, strong) CDockProjectImprint *imprint;
@property (nonatomic, strong) NSMutableArray<CDockProjectImage *> *arrImages;
@property (nonatomic, strong) NSMutableArray<NSDictionary *> *arrVersions;


- (id)initWithDict:(NSDictionary *)dict;
@end

@interface CDockProjectImprint : NSObject
@property(nonatomic, strong) NSString *companyAdditional;
@property(nonatomic, strong) NSString *address1;
@property(nonatomic, strong) NSString *address2;
@property(nonatomic, strong) NSString *city;
@property(nonatomic, strong) NSString *company;
@property(nonatomic, strong) NSString *copyright;
@property(nonatomic, strong) NSString *country;
@property(nonatomic, strong) NSString *edited;
@property(nonatomic, strong) NSString *fax;
@property(nonatomic, strong) NSString *legalInform;
@property(nonatomic, strong) NSString *mail;
@property(nonatomic, strong) NSString *phone;
@property(nonatomic, strong) NSString *url;
@property(nonatomic, strong) NSString *zip;
@end

@interface CDockProjectImage : NSObject
@property(nonatomic) BOOL isShow;
@property(nonatomic, strong) NSString *url;
@end
