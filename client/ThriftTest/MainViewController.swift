import UIKit

class MainViewController: UIViewController {

    var messaging: MessagingService? = nil
    
    @IBOutlet var operationsLog: UITextView!
    
    @IBAction func pingServerTapped(sender: AnyObject) {
        messaging!.ping({ (err: NSException?) in
            if let error = err {
                self.operationsLog.insertText("\n\(error.description)")
                return
            }
            self.operationsLog.insertText("\nping complete!")
        })
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        let storedCredentials: UserCredentials! = UserCredentials(token: "DEADBEEF")
        messaging = MessagingService(credentials: storedCredentials);
    }

}

