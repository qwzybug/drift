//
//  GEGist.h
//  <#ProjectName#>
//
//  Created by Devin Chalmers on 04/11/10
//  Copyright 2010 __MyCompanyName__. All rights reserved.
//

#import <CoreData/CoreData.h>

#pragma mark begin emogenerator forward declarations
@class GEGist;
@class GEFile;
@class GEGist;
#pragma mark end emogenerator forward declarations

/** Gist */
@interface GEGist : NSManagedObject {
}

+ (void)clearUserGists;

+ (void)markCurrentGist:(GEGist *)gist;
+ (GEGist *)currentGist;

+ (GEGist *)gistWithID:(NSString *)gistID;

+ (GEGist *)blankGist;
+ (GEGist *)welcomeGist;
+ (GEGist *)firstGist;

+ (NSInteger)count;

+ (GEGist *)insertOrUpdateGistWithAttributes:(NSDictionary *)attributes;

+ (NSFetchRequest *)fetchRequestForCurrentUserGists;
+ (NSFetchRequest *)fetchRequestForUserGists:(NSString *)username;

- (void)updateWithAttributes:(NSDictionary *)attributes;

@property (nonatomic, readonly) GEFile *file;
@property (nonatomic, readonly) NSDictionary *filesByFilename;

#pragma mark begin emogenerator accessors

+ (NSString *)entityName;

// Attributes
@property (readwrite, retain) NSDate *updatedAt;
@property (readwrite, retain) NSString *gistID;
@property (readwrite, assign) BOOL dirty;
@property (readwrite, retain) NSNumber *dirtyValue;
@property (readwrite, retain) NSString *revision;
@property (readwrite, retain) NSString *url;
@property (readwrite, retain) NSString *desc;
@property (readwrite, retain) NSString *user;
@property (readwrite, assign) BOOL public;
@property (readwrite, retain) NSNumber *publicValue;
@property (readwrite, retain) NSDate *createdAt;

// Relationships
@property (readwrite, retain) GEGist *forkOf;
- (GEGist *)forkOf;
- (void)setForkOf:(GEGist *)inForkOf;
@property (readonly, retain) NSMutableSet *files;
- (NSMutableSet *)files;
@property (readonly, retain) NSMutableSet *forks;
- (NSMutableSet *)forks;

#pragma mark end emogenerator accessors

@end
