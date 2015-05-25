//
//  As seen on http://www.russbishop.net/handle-exceptions-in-swift
//

#import <Foundation/Foundation.h>

@interface OSSExceptionHelper : NSObject
+ (void)tryInvokeBlock:(void(^)(void))tryBlock catch:(void(^)(NSException*))catchBlock finally:(void(^)(void))finallyBlock;
+ (id)tryInvokeBlockWithReturn:(id(^)(void))tryBlock catch:(id(^)(NSException*))catchBlock finally:(void(^)(void))finallyBlock;
+ (void)throwExceptionNamed:(NSString *)name message:(NSString *)message;
@end

@implementation OSSExceptionHelper
+ (void)tryInvokeBlock:(void(^)(void))tryBlock catch:(void(^)(NSException*))catchBlock finally:(void(^)(void))finallyBlock
{
    NSAssert(tryBlock != NULL, @"try block cannot be null");
    NSAssert(catchBlock != NULL || finallyBlock != NULL, @"catch or finally block must be provided");
    @try {
        tryBlock();
    }
    @catch (NSException *ex) {
        if(catchBlock != NULL) {
            catchBlock(ex);
        }
    }
    @finally {
        if(finallyBlock != NULL) {
            finallyBlock();
        }
    }
}

+ (id)tryInvokeBlockWithReturn:(id(^)(void))tryBlock catch:(id(^)(NSException*))catchBlock finally:(void(^)(void))finallyBlock
{
    NSAssert(tryBlock != NULL, @"try block cannot be null");
    NSAssert(catchBlock != NULL || finallyBlock != NULL, @"catch or finally block must be provided");
    
    id returnValue = nil;
    @try {
        returnValue = tryBlock();
    }
    @catch (NSException *ex) {
        if(catchBlock != NULL) {
            returnValue = catchBlock(ex);
        }
    }
    @finally {
        if(finallyBlock != NULL) {
            finallyBlock();
        }
    }
    return returnValue;
}

+ (void)throwExceptionNamed:(NSString *)name message:(NSString *)message;
{
    [NSException raise:name format:message];
}
@end