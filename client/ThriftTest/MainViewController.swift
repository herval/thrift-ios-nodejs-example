import UIKit

class MainViewController: UIViewController {

    var messaging: MessagingService? = nil
    
    @IBOutlet var operationsLog: UITextView!
    
    @IBAction func pingServerTapped(sender: AnyObject) {
        messaging!.ping({
            self.operationsLog.insertText("\nping complete!")
        })
    }

    override func viewDidLoad() {
        super.viewDidLoad()

        let storedCredentials: UserCredentials! = UserCredentials(token: "DEADBEEF")
        messaging = MessagingService(credentials: storedCredentials);
    }

}

