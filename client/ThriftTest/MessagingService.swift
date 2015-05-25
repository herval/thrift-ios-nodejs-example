import UIKit

class MessagingService {
    
    let serverHost = "localhost"
    let serverPort: Int32 = 9090
    
    let transport: TSocketClient!
    let proto: TBinaryProtocol!
    let credentials: UserCredentials!
    
    
    init(credentials: UserCredentials!) {
        self.credentials = credentials
        self.transport = TSocketClient(hostname: serverHost, port: serverPort)
        self.proto = TBinaryProtocol(transport: transport, strictRead: true, strictWrite: true)
    }
    
    func ping(done: () -> Void) {
        MessagingClient(withProtocol: proto).ping(self.credentials)
        done()
    }
    
}