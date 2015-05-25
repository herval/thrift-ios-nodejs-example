//
//  As seen on http://www.russbishop.net/handle-exceptions-in-swift
//

func try(maker: ()->(()->(), catch:((NSException!)->())?, finally:(()->())? )) {
    let (action, catch, finally) = maker()
    OSSExceptionHelper.tryInvokeBlock(action, catch: catch, finally: finally)
}

func try<T: AnyObject>(maker: ()->( ()->T, catch:((NSException!)->())?, finally: (()->())? )) -> T? {
    let (action, catch, finally) = maker()
    let result : AnyObject! = OSSExceptionHelper.tryInvokeBlockWithReturn(action, catch: { ex in
        if let catchClause = catch {
            catchClause(ex)
        }
        return nil
        }, finally: finally)
    if (result != nil) {
        return result as? T
    } else {
        return nil
    }
}

func try<T: AnyObject>(maker: ()->( ()->T, catch:((NSException!)->T)?, finally: (()->())? )) -> T? {
    let (action, catch, finally) = maker()
    let result : AnyObject! = OSSExceptionHelper.tryInvokeBlockWithReturn(action, catch: catch, finally: finally)
    if (result != nil) {
        return result as? T
    } else {
        return nil
    }
}

func throw(name:String, message:String) {
    OSSExceptionHelper.throwExceptionNamed(name, message: message)
}