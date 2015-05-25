//
//  As seen on http://www.russbishop.net/handle-exceptions-in-swift
//

@interface OSSExceptionHelper : NSObject
+ (void)tryInvokeBlock:(void(^)(void))tryBlock catch:(void(^)(NSException*))catchBlock finally:(void(^)(void))finallyBlock;
+ (id)tryInvokeBlockWithReturn:(id(^)(void))tryBlock catch:(id(^)(NSException*))catchBlock finally:(void(^)(void))finallyBlock;
+ (void)throwExceptionNamed:(NSString *)name message:(NSString *)message;
@end
