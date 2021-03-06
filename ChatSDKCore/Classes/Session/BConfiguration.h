//
//  BConfiguration.h
//  AFNetworking
//
//  Created by Ben on 11/7/17.
//

#import <Foundation/Foundation.h>
#import <ChatSDK/PMessage.h>

#define bEmailTitle @"email_title"
#define bEmailBody @"email_body"
#define bSMSBody @"sms_body"

#define bXMPPKey @"xmpp"
#define bXMPPHostAddressKey @"host_address"
#define bXMPPDomainKey @"domain"
#define bXMPPPortKey @"port"
#define bXMPPResourceKey @"resource"

@interface BConfiguration : NSObject {
    NSString * _defaultUserName;
    NSMutableDictionary * _messageBubblePadding;
    NSMutableDictionary * _messageBubbleMargin;
}

// Background color of messages: hex value like "FFFFFF"
@property (nonatomic, readwrite) NSString * messageColorMe;
@property (nonatomic, readwrite) NSString * messageColorReply;

// The Firebase root path. Data will be added to Firebase root/rootPath...
// this allows you to run multiple chat instances on one Firebase database
@property (nonatomic, readwrite) NSString * rootPath;

// Firebase cloud messaging server key
@property (nonatomic, readwrite) NSString * firebaseCloudMessagingServerKey;

// Enable the unread messages count on the main app badge
@property (nonatomic, readwrite) BOOL appBadgeEnabled;

// What will the user be called when they first sign up and before they
// set their name
@property (nonatomic, readonly) NSString * defaultUserName;
@property (nonatomic, readwrite) NSString * defaultUserNamePrefix;

// Should empty chats be shown in the threads view?
@property (nonatomic, readwrite) BOOL showEmptyChats;

// User profile image
@property (nonatomic, readwrite) NSString * defaultAvatarURL;

// Which image should be used if no avatar is set
@property (nonatomic, readwrite) UIImage * defaultBlankAvatar;

// Which image should be used if no avatar is set
@property (nonatomic, readwrite) UIImage * defaultGroupChatAvatar;

@property (nonatomic, readwrite) NSString * timeFormat;

// Can users make new public chats. It's recommended to set this to no otherwise
// users will create a large number of chats
@property (nonatomic, readwrite) BOOL allowUsersToCreatePublicChats;

// Enable or disable social login options
@property (nonatomic, readwrite) BOOL googleLoginEnabled;
@property (nonatomic, readwrite) BOOL facebookLoginEnabled;
@property (nonatomic, readwrite) BOOL twitterLoginEnabled;
@property (nonatomic, readwrite) BOOL anonymousLoginEnabled;
@property (nonatomic, readwrite) BOOL forgotPasswordEnabled;
@property (nonatomic, readwrite) BOOL termsAndConditionsEnabled;

// Twitter login credentials
@property (nonatomic, readwrite) NSString * twitterApiKey;
@property (nonatomic, readwrite) NSString * twitterSecret;

@property (nonatomic, readwrite) NSString * xmppDomain;
@property (nonatomic, readwrite) NSString * xmppHostAddress;
@property (nonatomic, readwrite) int xmppPort;
@property (nonatomic, readwrite) NSString * xmppResource;
@property (nonatomic, readwrite) int xmppMucMessageHistory;

// Google login credentials
@property (nonatomic, readwrite) NSString * googleClientKey;

@property (nonatomic, readwrite) NSString * facebookAppId;

// The the image to be displayed on the login screen. Image should be
// 120x120px
@property (nonatomic, readwrite) UIImage * loginScreenLogoImage;

// The app name text displayed on the login screen
@property (nonatomic, readwrite) NSString * loginScreenAppName;

// Login username / email placeholder text
@property (nonatomic, readwrite) NSString * loginUsernamePlaceholder;

// When a push notification is clicked, should the chat screen be opened
@property(nonatomic, readwrite) BOOL shouldOpenChatWhenPushNotificationClicked;

// This allows us to make it so the chat will only be opened if the tab bar is visible. This can be
// useful in some advanced situations where the tab bar may not be the root view
@property(nonatomic, readwrite) BOOL shouldOpenChatWhenPushNotificationClickedOnlyIfTabBarVisible;

// Should the client send push notifications?
@property(nonatomic, readwrite) BOOL clientPushEnabled;

// Allow the owner of a public thread to delete it
@property (nonatomic, readwrite) BOOL allowPublicThreadDeletion;

// Can the user click the title bar to open the chat info
@property (nonatomic, readwrite) BOOL userChatInfoEnabled;

// Phone book module invite by email title and body
@property (nonatomic, readwrite) NSString * inviteByEmailTitle;
@property (nonatomic, readwrite) NSString * inviteByEmailBody;
@property (nonatomic, readwrite) NSString * inviteBySMSBody;

// Message fonts
@property (nonatomic, readwrite) UIFont * messageTextFont;
@property (nonatomic, readwrite) NSString * messageTextColorMe;
@property (nonatomic, readwrite) NSString * messageTextColorReply;

@property (nonatomic, readwrite) UIFont * messageTimeFont;
@property (nonatomic, readwrite) UIFont * messageNameFont;

@property (nonatomic, readwrite) UIFont * threadTitleFont;
@property (nonatomic, readwrite) UIFont * threadTimeFont;
@property (nonatomic, readwrite) UIFont * threadSubtitleFont;

@property (nonatomic, readwrite) BOOL locationMessagesEnabled;
@property (nonatomic, readwrite) BOOL imageMessagesEnabled;

@property (nonatomic, readwrite) int audioMessageMaxLengthSeconds;

@property (nonatomic, readwrite) BOOL prefersLargeTitles;

// How many messages should be loaded initially when a chat is opened
@property (nonatomic, readwrite) int chatMessagesToLoad;

// Push notification sound - name of sound file to play i.e. "mySound"
@property (nonatomic, readwrite) NSString * pushNotificationSound;

// The action associated with the push notification
@property (nonatomic, readwrite) NSString * pushNotificationAction;

// If this is true, then we will only send a push notification if the recipient is offline
@property (nonatomic, readwrite) BOOL onlySendPushToOfflineUsers;

@property (nonatomic, readwrite) NSString * googleMapsApiKey;

// Reset the database when core data changes
@property (nonatomic, readwrite) BOOL clearDataWhenRootPathChanges;

// Database version
@property (nonatomic, readwrite) NSString * databaseVersion;

// If this databbase version changes, the database will be cleared and re-populated from Firebase
@property (nonatomic, readwrite) BOOL clearDatabaseWhenDataVersionChanges;

// Firebase options

// Should the Chat SDK call [FIRApp configure];
@property (nonatomic, readwrite) BOOL firebaseShouldConfigureAutomatically;

// The name of the custom Firebase Google-Services plist file
@property (nonatomic, readwrite) NSString * firebaseGoogleServicesPlistName;

// Chat SDK can auto-detect and install modules. Some modules need to a different setup
// procedure depending on which server is being used - Firebase or XMPP. If only one
// network adapter is set, modules will be installed for that server but if there
// are multiple network adapters in the source code, the default server will be used
// Allowable values:
// bServerFirebase
// bServerXMPP
@property (nonatomic, readwrite) NSString * defaultServer;

@property (nonatomic, readwrite) BOOL showUserAvatarsOn1to1Threads;

@property (nonatomic, readwrite) BOOL enableMessageModerationTab;

// Show local notifications when a message is received
@property (nonatomic, readwrite) BOOL showLocalNotifications;

// Message data properties
// This should be used for backwards compatibility with v3 of the project
@property (nonatomic, readwrite) BOOL includeMessagePayload;

// This should be enabled for compatibility with any version less than 4.3.x
@property (nonatomic, readwrite) BOOL includeMessageJSON;

// In the future we will be moving towards using native JSON for the message payload enable this for 4.4.x+
@property (nonatomic, readwrite) BOOL includeMessageJSONV2;

#define bChatSDK_API_1 @"3.x"
#define bChatSDK_API_2 @"4.0.0 - 4.3.18"
#define bChatSDK_API_3 @"4.4.0+"

// Configure Chat SDK to support the API levels of choice
// The default version supports all API levels
-(void) configureForCompatibilityWithVersions: (NSArray *) versions;

+(BConfiguration *) configuration;

-(void) xmppWithHostAddress: (NSString *) hostAddress;
-(void) xmppWithDomain: (NSString *) domain hostAddress: (NSString *) hostAddress;
-(void) xmppWithDomain: (NSString *) domain hostAddress: (NSString *) hostAddress port: (int) port;
-(void) xmppWithDomain: (NSString *) domain hostAddress: (NSString *) hostAddress port: (int) port resource: (NSString *) resource;

-(void) setMessageBubbleMargin: (UIEdgeInsets) margin forMessageType: (bMessageType) type;
-(void) setMessageBubblePadding: (UIEdgeInsets) padding forMessageType: (bMessageType) type;

-(NSValue *) messageBubbleMarginForType: (bMessageType) type;
-(NSValue *) messageBubblePaddingForType: (bMessageType) type;

@end
