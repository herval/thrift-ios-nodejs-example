/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

#import <Foundation/Foundation.h>

#import "TProtocol.h"
#import "TApplicationException.h"
#import "TProtocolException.h"
#import "TProtocolUtil.h"
#import "TProcessor.h"
#import "TObjective-C.h"
#import "TBase.h"


@interface User : NSObject <TBase, NSCoding> {
  int32_t __id;
  NSString * __name;

  BOOL __id_isset;
  BOOL __name_isset;
}

#if TARGET_OS_IPHONE || (MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_5)
@property (nonatomic, getter=id, setter=setId:) int32_t id;
@property (nonatomic, retain, getter=name, setter=setName:) NSString * name;
#endif

- (id) init;
- (id) initWithId: (int32_t) id name: (NSString *) name;

- (void) read: (id <TProtocol>) inProtocol;
- (void) write: (id <TProtocol>) outProtocol;

- (void) validate;

#if !__has_feature(objc_arc)
- (int32_t) id;
- (void) setId: (int32_t) id;
#endif
- (BOOL) idIsSet;

#if !__has_feature(objc_arc)
- (NSString *) name;
- (void) setName: (NSString *) name;
#endif
- (BOOL) nameIsSet;

@end

@interface Message : NSObject <TBase, NSCoding> {
  NSString * __body;
  User * __sender;
  int32_t __timestamp;

  BOOL __body_isset;
  BOOL __sender_isset;
  BOOL __timestamp_isset;
}

#if TARGET_OS_IPHONE || (MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_5)
@property (nonatomic, retain, getter=body, setter=setBody:) NSString * body;
@property (nonatomic, retain, getter=sender, setter=setSender:) User * sender;
@property (nonatomic, getter=timestamp, setter=setTimestamp:) int32_t timestamp;
#endif

- (id) init;
- (id) initWithBody: (NSString *) body sender: (User *) sender timestamp: (int32_t) timestamp;

- (void) read: (id <TProtocol>) inProtocol;
- (void) write: (id <TProtocol>) outProtocol;

- (void) validate;

#if !__has_feature(objc_arc)
- (NSString *) body;
- (void) setBody: (NSString *) body;
#endif
- (BOOL) bodyIsSet;

#if !__has_feature(objc_arc)
- (User *) sender;
- (void) setSender: (User *) sender;
#endif
- (BOOL) senderIsSet;

#if !__has_feature(objc_arc)
- (int32_t) timestamp;
- (void) setTimestamp: (int32_t) timestamp;
#endif
- (BOOL) timestampIsSet;

@end

@interface UserCredentials : NSObject <TBase, NSCoding> {
  NSString * __token;

  BOOL __token_isset;
}

#if TARGET_OS_IPHONE || (MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_5)
@property (nonatomic, retain, getter=token, setter=setToken:) NSString * token;
#endif

- (id) init;
- (id) initWithToken: (NSString *) token;

- (void) read: (id <TProtocol>) inProtocol;
- (void) write: (id <TProtocol>) outProtocol;

- (void) validate;

#if !__has_feature(objc_arc)
- (NSString *) token;
- (void) setToken: (NSString *) token;
#endif
- (BOOL) tokenIsSet;

@end

@interface NewMessage : NSObject <TBase, NSCoding> {
  UserCredentials * __sender;
  NSString * __body;
  int32_t __targetUserId;

  BOOL __sender_isset;
  BOOL __body_isset;
  BOOL __targetUserId_isset;
}

#if TARGET_OS_IPHONE || (MAC_OS_X_VERSION_MAX_ALLOWED >= MAC_OS_X_VERSION_10_5)
@property (nonatomic, retain, getter=sender, setter=setSender:) UserCredentials * sender;
@property (nonatomic, retain, getter=body, setter=setBody:) NSString * body;
@property (nonatomic, getter=targetUserId, setter=setTargetUserId:) int32_t targetUserId;
#endif

- (id) init;
- (id) initWithSender: (UserCredentials *) sender body: (NSString *) body targetUserId: (int32_t) targetUserId;

- (void) read: (id <TProtocol>) inProtocol;
- (void) write: (id <TProtocol>) outProtocol;

- (void) validate;

#if !__has_feature(objc_arc)
- (UserCredentials *) sender;
- (void) setSender: (UserCredentials *) sender;
#endif
- (BOOL) senderIsSet;

#if !__has_feature(objc_arc)
- (NSString *) body;
- (void) setBody: (NSString *) body;
#endif
- (BOOL) bodyIsSet;

#if !__has_feature(objc_arc)
- (int32_t) targetUserId;
- (void) setTargetUserId: (int32_t) targetUserId;
#endif
- (BOOL) targetUserIdIsSet;

@end

@protocol Messaging <NSObject>
- (NSMutableArray *) fetchMessages: (UserCredentials *) credentials;  // throws TException
- (BOOL) postMessage: (NewMessage *) message;  // throws TException
- (void) ping: (UserCredentials *) credentials;  // throws TException
@end

@interface MessagingClient : NSObject <Messaging> {
  id <TProtocol> inProtocol;
  id <TProtocol> outProtocol;
}
- (id) initWithProtocol: (id <TProtocol>) protocol;
- (id) initWithInProtocol: (id <TProtocol>) inProtocol outProtocol: (id <TProtocol>) outProtocol;
@end

@interface MessagingProcessor : NSObject <TProcessor> {
  id <Messaging> mService;
  NSDictionary * mMethodMap;
}
- (id) initWithMessaging: (id <Messaging>) service;
- (id<Messaging>) service;
@end

@interface MessagingServiceConstants : NSObject {
}
@end
