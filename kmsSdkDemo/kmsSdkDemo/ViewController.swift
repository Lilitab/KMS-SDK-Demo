//
//  ViewController.swift
//  kmsSdkDemo
//
//  Created by John Lindstrom on 8/2/23.
//

import UIKit
import LilitabSDK

class ViewController: UIViewController,  KMSEventDelegate  {
    
    func kmsBarShowAboutView() {
        NSLog("[show your about view dialog here]")
        //NOTE: the kmsSdkDemo app is recognized by the SDK and therefore shows that "about SDK demo" menu, but you will need  to render your own 'about app' dialog
        //TODO: render "about SDKDemo" within this App, I guess... (although, that is kinda "extra"...)
    }
    
    func kmsDockEvent(_ dockEvent: KMSDockEvent) {
        let eventStr = KMS.formatDockEvent(toString: dockEvent)!
        NSLog("kmsDockEvent=\(eventStr)")
        
        if (dockEvent == KMSDockEvent.AlertLostComm) {
            NSLog("kmsDockEvent, dockEvent==AlertLostComm!")
        }
    }
    
    func kmsDockStatusUpdate(_ dict: [AnyHashable : Any]!) {
        NSLog("kmsDockStatusDidUpdate, dockStatus(dict)=\(dict!)")
    }
    
    func kmsUserAuthenticated(_ userId: String!, _ userName: String!) {
        NSLog("kmsUserAuthenticated, userId=\(String(describing: userId)), userName=\(String(describing: userName))")
    }
    
    func kmsUserPINFailed(_ reason: String!) {
        NSLog("kmsUserPINFailed, reason= \(String(describing: reason))")
    }
    
    func kmsServiceReachabilityChanged(_ dict: [AnyHashable : Any]!) {
        NSLog("kmsServiceReachabilityChanged, dict=\(String(describing: dict))")
    }
    
    enum ActiveButton {
        
        case startServices

        case whoAmI
        case showControls
        case hideControls
        case openPortal
        case userAuth
        case clearUser

        case dockPairingStatus
        case dockPairingInfo
        case dockUnlock
        case unlockButtonState
        case dockStatus
        case dockInfo

        case postMetric
        case getMetric
        
        case configStore
        case configGet
        
        case datastoreStore
        case datastoreSearch
        case datastoreGet
        case datastoreDelete
        
        case postEvent
        case geofenceStatus
        case wipedownNow
        case wipedownStatus
    }
    
    var lastButton = ActiveButton.startServices
    
    @IBOutlet weak var binBtnDesc: UILabel!
    @IBOutlet weak var labelDesc1: UILabel!
    
    @IBOutlet weak var btnTextViewDesc: UITextView!
    
    @IBOutlet weak var btn_startServices: RoundButton!

    @IBOutlet weak var btn_whoAmI: RoundButton!
    @IBOutlet weak var btn_showControls: RoundButton!
    @IBOutlet weak var btn_hideControls: RoundButton!
    @IBOutlet weak var btn_openPortal: RoundButton!
    @IBOutlet weak var btn_userAuth: RoundButton!
    @IBOutlet weak var btn_clearUser: RoundButton!
    
    @IBOutlet weak var btn_dockPairingStatus: RoundButton!
    @IBOutlet weak var btn_dockPairingInfo: RoundButton!
    @IBOutlet weak var btn_dockUnlock: RoundButton!
    @IBOutlet weak var btn_unlockButtonState: RoundButton!
    @IBOutlet weak var btn_dockStatus: RoundButton!
    @IBOutlet weak var btn_dockInfo: RoundButton!

    @IBOutlet weak var btn_postMetric: RoundButton!
    @IBOutlet weak var btn_getMetric: RoundButton!
    
    @IBOutlet weak var btn_configStore: RoundButton!
    @IBOutlet weak var btn_configGet: RoundButton!
    
    @IBOutlet weak var btn_datastoreStore: RoundButton!
    @IBOutlet weak var btn_datastoreSearch: RoundButton!
    @IBOutlet weak var btn_datastoreGet: RoundButton!
    @IBOutlet weak var btn_datastoreDelete: RoundButton!
   
    @IBOutlet weak var btn_postEvent: RoundButton!
    @IBOutlet weak var btn_geofenceStatus: RoundButton!
    @IBOutlet weak var btn_wipedownNow: RoundButton!
    @IBOutlet weak var btn_wipedownStatus: RoundButton!
    
    @IBOutlet weak var respTextDesc: UILabel!
    
    @IBOutlet weak var callTextViewDesc: UITextView!
    @IBOutlet weak var respTextViewDesc: UITextView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        //start with startServices button selected
        selectStartSvcsPressed(self)
        
        //KMS.singleton().kmsEventsDelegate = self;      << TODO: remove this option!!!
        //[KMS.singleton() addKMSEventDelegate:self];
        KMS.singleton().addEventDelegate(self);
    }
    
    @objc func testCall1(_ notification: NSNotification) {
        NSLog("testCall1 - from eventListener")
        NSLog("testCall1, notificationInfo=\(String(describing: notification.userInfo))")
    }
    
    //for demo app, turning off status bar
    override var prefersStatusBarHidden: Bool {
        return true
    }
    
    func resetButtonTints() {
        btn_startServices.tintColor = .white
 
        btn_whoAmI.tintColor = .white
        btn_showControls.tintColor = .white
        btn_hideControls.tintColor = .white
        btn_openPortal.tintColor = .white
        btn_userAuth.tintColor = .white
        btn_clearUser.tintColor = .white

        btn_dockPairingStatus.tintColor = .white
        btn_dockPairingInfo.tintColor = .white
        btn_dockUnlock.tintColor = .white
        btn_unlockButtonState.tintColor = .white
        btn_dockStatus.tintColor = .white
        btn_dockInfo.tintColor = .white
        
        btn_postMetric.tintColor = .white
        btn_getMetric.tintColor = .white
        
        btn_configStore.tintColor = .white
        btn_configGet.tintColor = .white
        
        btn_datastoreStore.tintColor = .lightGray
        btn_datastoreSearch.tintColor = .lightGray
        btn_datastoreGet.tintColor = .lightGray
        btn_datastoreDelete.tintColor = .lightGray
        
        btn_postEvent.tintColor = .white
        btn_geofenceStatus.tintColor = .white
        btn_wipedownNow.tintColor = .white
        btn_wipedownStatus.tintColor = .white
    }
    
    // -----------------------------------------------------------------------------
    
    @IBAction func selectStartSvcsPressed(_ sender: Any) {
        resetButtonTints()
        lastButton = ActiveButton.startServices
        btn_startServices.tintColor = #colorLiteral(red: 0.538921535, green: 0.7828642726, blue: 0.9997832179, alpha: 1)
        
        binBtnDesc.text = "startServices"
        btnTextViewDesc.text = "startServices is the required command to initiate KMS services. Command should be executed as part of app initialization. startServices verifies tablet authorization, launches registration wizard if needed, initiates portal communication and, with that communication, provides KMS services."
        callTextViewDesc.text = "let resp:String = KMS.singleton().startServices()"
        respTextViewDesc.text = "// tap PLACE to send command //"
    }
    
    @IBAction func selectWhoAmIPress(_ sender: Any) {
        resetButtonTints()
        
        btn_whoAmI.tintColor = #colorLiteral(red: 0.538921535, green: 0.7828642726, blue: 0.9997832179, alpha: 1)

        binBtnDesc.text = "whoAmI"
        btnTextViewDesc.text = "Returns a dictionary containing the tablet/user\nregistration coordinates (EnterpriseID, GroupID,\nTabletID, UserID) or “Not Registered”.\n\n\n\n\n \n\n\n\n"
        callTextViewDesc.text = "let whoRespDict:NSMutableDictionary = KMS.singleton().whoAmI()\n\n\n\n\n\n\n\n"
        respTextViewDesc.text = "// tap PLACE to send command //\n\n\n\n\n\n\n\n"
        
        lastButton = ActiveButton.whoAmI
    }
    
    @IBAction func selectShowControlsPress(_ sender: Any) {
        resetButtonTints()
        btn_showControls.tintColor = #colorLiteral(red: 0.538921535, green: 0.7828642726, blue: 0.9997832179, alpha: 1)

        binBtnDesc.text = "showControls"
        btnTextViewDesc.text = "Displays KMS controls. Pulldown header includes\ngeofence status icon, KMS menu, KMS info icon\nand, if docked, dock status icon and unlock\nbutton. Footer includes tablet coordinates and\nportal login access. Display of KMS controls will\nrevert to that specified in 'Show KMS Controls'\nportal setting after 5 minutes."
        callTextViewDesc.text = "KMS.singleton().showControls()\n\n\n\n\n\n\n\n"
        respTextViewDesc.text = "// tap PLACE to send command //\n\n\n\n\n\n\n\n \n\n\n\n"
        btn_showControls.titleLabel?.textColor = .black
        
        lastButton = ActiveButton.showControls
    }
    
    @IBAction func selectHideControlsPress(_ sender: Any) {
        
        resetButtonTints()
        btn_hideControls.tintColor = #colorLiteral(red: 0.538921535, green: 0.7828642726, blue: 0.9997832179, alpha: 1)

        binBtnDesc.text = "hideControls"
        btnTextViewDesc.text = "Hides KMS controls. Pulldown header includes\ngeofence status icon, KMS menu, KMS info icon\nand, if docked, dock status icon and unlock\nbutton. Footer includes tablet coordinates and\nportal login access. Display of KMS controls will\nrevert to that specified in 'Show KMS Controls'\nportal setting after 5 minutes."
        callTextViewDesc.text = "KMS.singleton().hideControls()\n\n\n\n\n\n\n\n"
        respTextViewDesc.text = "// tap PLACE to send command //\n\n\n\n\n\n\n\n \n\n\n\n"
        
        lastButton = ActiveButton.hideControls
    }
    
    @IBAction func selectOpenPortalPressed(_ sender: Any) {
        resetButtonTints()
        lastButton = ActiveButton.openPortal
        
        btn_openPortal.tintColor = #colorLiteral(red: 0.538921535, green: 0.7828642726, blue: 0.9997832179, alpha: 1)
        
        binBtnDesc.text = "openPortal"
        btnTextViewDesc.text = "Launches portal login screen in overlay webview.\nUseful for administrative portal access from the\nkiosk. Webview dismissed when portal exited.\n\n\n\n\n"
        callTextViewDesc.text = "KMS.singleton().openPortal()\n\n\n\n\n\n\n\n \n\n\n\n"
        respTextViewDesc.text = "// tap PLACE to send command //\n\n\n\n\n\n\n\n"
    }
    
    @IBAction func selectUserAuthPressed(_ sender: Any) {
        resetButtonTints()
        lastButton = ActiveButton.userAuth
        btn_userAuth.tintColor = #colorLiteral(red: 0.538921535, green: 0.7828642726, blue: 0.9997832179, alpha: 1)
        
        binBtnDesc.text = "userAuth"

        btnTextViewDesc.text = "Launches the User Auth Interface which prompts a\nuser to enter their PIN. Supports the use case\nwhere user-specific application access is desired.\nUse ClearUser to clear the active user, as when\ntablet is returned to a shared asset pool. User\nidentities are created and managed in the portal."
        callTextViewDesc.text = "KMS.singleton().userAuth()\n\n\n\n\n\n\n\n \n\n\n\n"
        respTextViewDesc.text = "// tap PLACE to send command //\n\n\n\n\n\n\n\n"
    }
    
    @IBAction func selectClearUserPressed(_ sender: Any) {
        resetButtonTints()
        lastButton = ActiveButton.clearUser
        btn_clearUser.tintColor = #colorLiteral(red: 0.538921535, green: 0.7828642726, blue: 0.9997832179, alpha: 1)
        
        binBtnDesc.text = "clearUser()"
        btnTextViewDesc.text = "Use ClearUser to clear the active user, as when\ntablet is returned to a shared asset pool. User\nidentities are created and managed in the portal.\n\n \n\n\n\n"
        callTextViewDesc.text = "KMS.singleton().clearUser()\n\n\n\n\n\n\n\n"
        respTextViewDesc.text = "// tap PLACE to send command //\n\n\n\n\n\n\n\n"
    }
    
    @IBAction func selectdockPairingStatusPressed(_ sender: Any) {
        resetButtonTints()
        lastButton = ActiveButton.dockPairingStatus
        btn_dockPairingStatus.tintColor = #colorLiteral(red: 0.538921535, green: 0.7828642726, blue: 0.9997832179, alpha: 1)
        
        binBtnDesc.text = "dockPairingStatus"
        btnTextViewDesc.text = "Launches Pairing Status wizard, used to pair\nSmartDOCK Connect modules, convey BLE Pairing\nStatus, and troubleshoot BLE communication\nissues. Returns a DockPairingInfo dictionary.\n\n\n \n\n\n\n"
        callTextViewDesc.text = "KMS.singleton().dockPairingStatus()\n\n\n\n\n\n\n\n"
        respTextViewDesc.text = "// tap PLACE to send command //\n\n\n\n\n\n\n\n"
    }

    @IBAction func selectdockPairingInfoPressed(_ sender: Any) {
        resetButtonTints()
        lastButton = ActiveButton.dockPairingInfo
        btn_dockPairingInfo.tintColor = #colorLiteral(red: 0.538921535, green: 0.7828642726, blue: 0.9997832179, alpha: 1)
        
        binBtnDesc.text = "dockPairingInfo"
        btnTextViewDesc.text = "Returns a dictionary of pairing status indicators:\nisBluetoothEnabled, isPaired (is tablet currently\npaired/bonded with a SmartDOCK Connect\nModule), isConnected (is tablet currently\nconnected with bonded module), isCommunicating\n(are the tablet and dock actively communicating).\nNote that head unit must be docked for\nisConnected or isCommunicating to be true. \n\n\n\n"
        callTextViewDesc.text = "let dict:NSMutableDictionary = KMS.singleton().dockPairingInfo()\nif (dict != nil) {\n  print(\"resp=\\(dict)\")\n}\n\n\n\n"
        respTextViewDesc.text = "// tap PLACE to send command //\n\n\n\n\n\n\n\n"
    }
    
    @IBAction func selectdockUnlockPressed(_ sender: Any) {
        resetButtonTints()
        lastButton = ActiveButton.dockUnlock
        btn_dockUnlock.tintColor = #colorLiteral(red: 0.538921535, green: 0.7828642726, blue: 0.9997832179, alpha: 1)
        
        binBtnDesc.text = "dockUnlock"
        btnTextViewDesc.text = "Initiates dock unlock, with or without PIN Pad\nauthentication, depending on portal setting.\nRequires that the tablet be docked to and\ncommunicating with a Lilitab SmartDOCK.\n\n\n \n\n\n\n"
        callTextViewDesc.text = "let resp:String = KMS.singleton().dockUnlock()\n\n\n\n\n\n\n\n"
        respTextViewDesc.text = "// tap PLACE to send command //\n\n\n\n\n\n\n\n"
    }

    @IBAction func selectUnlockButtonStatePressed(_ sender: Any) {
        resetButtonTints()
        lastButton = ActiveButton.unlockButtonState
        btn_unlockButtonState.tintColor = #colorLiteral(red: 0.538921535, green: 0.7828642726, blue: 0.9997832179, alpha: 1)
        
        binBtnDesc.text = "unlockButtonState"
        btnTextViewDesc.text = "Returns unlock button state. State options include:\n'Press to Unlock' (docked, locked and\ncommunicating with dock), 'Unlocked' (unlocked\nfrom dock), 'Stall when Locking', 'Stall when\nUnlocking', 'Lost Communication' (unexpected\nloss of communication while docked and locked),\n'Resetting' (firmware update in progress), or 'Not\nAvailable' (tablet has not been docked). \n\n\n\n"
        callTextViewDesc.text = "let resp:String = KMS.singleton().unlockButtonState()\n\n\n\n\n\n\n\n"
        respTextViewDesc.text = "// tap PLACE to send command //\n\n\n\n\n\n\n\n"
    }

    @IBAction func selectDockStatusPressed(_ sender: Any) {
        resetButtonTints()
        lastButton = ActiveButton.dockStatus
        btn_dockStatus.tintColor = #colorLiteral(red: 0.538921535, green: 0.7828642726, blue: 0.9997832179, alpha: 1)
        
        binBtnDesc.text = "dockStatus"
        btnTextViewDesc.text = "Returns a dock status dictionary for the dock to\nwhich tablet is docked. Dictionary includes: Dock\nUDID, Dock ID, Hardware Type, Hardware Version,\nFirmware Version, Current State, Motor Ring\nNeutral, Lock Ring Locked, Lock Ring Unlocked,\nCharging, Stalled, Head Present, Wall Power. If\ntablet is not docked, returns 'Head Present:No'.\n \n\n\n\n"
        callTextViewDesc.text = "let dict = KMS.singleton().dockStatus()\nif (dict != nil) {\n  print(\"resp=\\(dict)\")\n}\n\n\n\n"
        respTextViewDesc.text = "// tap PLACE to send command //\n\n\n\n\n\n\n\n"
    }

    @IBAction func selectDockInfoPressed(_ sender: Any) {
        resetButtonTints()
        lastButton = ActiveButton.dockInfo
        btn_dockInfo.tintColor = #colorLiteral(red: 0.538921535, green: 0.7828642726, blue: 0.9997832179, alpha: 1)
        
        binBtnDesc.text = "dockInfo"
        btnTextViewDesc.text = "Given a valid Dock UDID in same group, returns a\ndictionary containing the following dock\ninformation parameters: Dock ID, Hardware Type,\nHardware Version, Firmware Version, Deploy Date,\nLast Update, Status.\n"
        callTextViewDesc.text = "var dict:[String:String]? = KMS.singleton().dockInfo() as NSDictionary? as? [String: String] = KMS.singleton().dockInfo()\nif (dict != nil) {\n  print(\"dict=\\(dict)\") \n}\nelse {\n  print(\"no dock found\")\n}\n\n\n\n"
        respTextViewDesc.text = "// tap PLACE to send command //\n\n\n\n\n\n\n\n \n\n\n\n"
    }
    
    @IBAction func selectPostMetricPressed(_ sender: Any) {
        resetButtonTints()
        lastButton = ActiveButton.postMetric
        btn_postMetric.tintColor = #colorLiteral(red: 0.538921535, green: 0.7828642726, blue: 0.9997832179, alpha: 1)
        
        binBtnDesc.text = "postMetric"
        btnTextViewDesc.text = "Retrieves metric data from the KMS\nportal. Metrics must be defined in the portal\nbefore use. Metrics allow kiosk performance\nstatistics to be tracked by device and over time.\nGetMetric returns the accumulated value of a\nspecified metric over a specified timerange.\n \n\n\n\n"
        
        callTextViewDesc.text = "let resp:String = KMS.singleton().postMetric(\"Clicks\", value: \"1\") \nprint(\"resp = \\(resp)\") "
        respTextViewDesc.text = "// tap PLACE to send command //\n\n\n\n\n\n\n\n"
    }
    
    @IBAction func selectGetMetricPressed(_ sender: Any) {
        resetButtonTints()
        lastButton = ActiveButton.getMetric
        btn_getMetric.tintColor = #colorLiteral(red: 0.538921535, green: 0.7828642726, blue: 0.9997832179, alpha: 1)
        
        binBtnDesc.text = "getMetric"
        btnTextViewDesc.text = "Posts metric data to the KMS\nportal. Metrics must be defined in the portal\nbefore use. Metrics allow kiosk performance\nstatistics to be tracked by device and over time.\nGetMetric returns the accumulated value of a\nspecified metric over a specified timerange.\n \n\n\n\n"
        
        callTextViewDesc.text = "/* get Clicks metric within last 10 minutes */\nlet minPosixVal = (Int)(Date().timeIntervalSince1970 - (60 * 10));\nlet maxPosixVal = (Int)(Date().timeIntervalSince1970);\nlet dict:[String:String]? = KMS.singleton().getMetric(\"Clicks\"), minPosix: minPosixVal, maxPosix: maxPosixVal) as NSDictionary? as? [String: String] \n"
        respTextViewDesc.text = "// tap PLACE to send command //\n\n\n\n\n\n\n\n"
    }

    @IBAction func selectConfigStorePressed(_ sender: Any) {
        resetButtonTints()
        lastButton = ActiveButton.configStore
        btn_configStore.tintColor = #colorLiteral(red: 0.538921535, green: 0.7828642726, blue: 0.9997832179, alpha: 1)
        
        binBtnDesc.text = "configStore"
        btnTextViewDesc.text = "Stores tablet-specific configuration values. Functionality is designed to facilitate configuration/customization/calibration of individual kiosks while running the same app. \n\n\n\n"
        callTextViewDesc.text = "var configVals: [String: Any] = [:]\nconfigVals[\"dateKey1\"] = *dateNow*\nconfigVals[\"colorkey1\"] = 808080\nconfigVals[\"colorkey2\"] = 404040\nconfigVals[\"colorkey3\"] = \"threeGreen\"\nlet dict:[String:String]? = KMS.singleton().configStore(\"colorPrefs3\", configValues:configVals) as NSDictionary? as? [String: String]"
        respTextViewDesc.text = "// tap PLACE to send command //\n\n\n\n\n\n\n\n"
    }
    
    @IBAction func selectConfigGetPressed(_ sender: Any) {
        resetButtonTints()
        lastButton = ActiveButton.configGet
        btn_configGet.tintColor = #colorLiteral(red: 0.538921535, green: 0.7828642726, blue: 0.9997832179, alpha: 1)
        
        binBtnDesc.text = "configGet"
        btnTextViewDesc.text = "Retrieves tablet-specific configuration values. Functionality is designed to facilitate configuration/customization/calibration of individual kiosks while running the same app. \n\n\n\n"
        callTextViewDesc.text = "let dict:[String:String]? = KMS.singleton().configGet(\"colorPrefs3\") as NSDictionary? as? [String: String] \n\n\n\n\n\n\n\n"
        respTextViewDesc.text = "// tap PLACE to send command //\n\n\n\n\n\n\n\n"
    }
    
    @IBAction func selectDatastoreStorePressed(_ sender: Any) {
        resetButtonTints()
        lastButton = ActiveButton.datastoreStore
        btn_datastoreStore.tintColor = #colorLiteral(red: 0.538921535, green: 0.7828642726, blue: 0.9997832179, alpha: 1)

        binBtnDesc.text = "datastoreStore"
        btnTextViewDesc.text = "DataStore functions facilitate sharing of data between tablets within an enterprise. The database has a dynamic structure that accepts and displays integer, decimal, currency, POSIX, string, list, and sum data types. Lists are nested tables within a record that can contain any set of other data types. Sum is a special data type that totals a numeric column of list data, such as the total amount of an order. Data is indexed and searchable, both programmatically from KMS-enabled apps and administratively from the KMS portal. \n\n\n\n"
        callTextViewDesc.text = "KMS.singleton().datastoreStore()\n\n\n\n\n\n\n\n"
        respTextViewDesc.text = "// tap PLACE to send command //\n\n\n\n\n\n\n\n"
    }
    
    @IBAction func selectDatastoreSearchPressed(_ sender: Any) {
        resetButtonTints()
        lastButton = ActiveButton.datastoreSearch
        btn_datastoreSearch.tintColor = #colorLiteral(red: 0.538921535, green: 0.7828642726, blue: 0.9997832179, alpha: 1)

        binBtnDesc.text = "datastoreSearch"
        btnTextViewDesc.text = "DataStore functions facilitate sharing of data between tablets within an enterprise. The database has a dynamic structure that accepts and displays integer, decimal, currency, POSIX, string, list, and sum data types. Lists are nested tables within a record that can contain any set of other data types. Sum is a special data type that totals a numeric column of list data, such as the total amount of an order. Data is indexed and searchable, both programmatically from KMS-enabled apps and administratively from the KMS portal. \n\n\n\n"
        callTextViewDesc.text = "KMS.singleton().datastoreSearch()\n\n\n\n\n\n\n\n"
        respTextViewDesc.text = "// tap PLACE to send command //\n\n\n\n\n\n\n\n"
    }
    
    @IBAction func selectDatastoreGetPressed(_ sender: Any) {
        resetButtonTints()
        lastButton = ActiveButton.datastoreGet
        btn_datastoreGet.tintColor = #colorLiteral(red: 0.538921535, green: 0.7828642726, blue: 0.9997832179, alpha: 1)

        binBtnDesc.text = "datastoreGet"
        btnTextViewDesc.text = "DataStore functions facilitate sharing of data between tablets within an enterprise. The database has a dynamic structure that accepts and displays integer, decimal, currency, POSIX, string, list, and sum data types. Lists are nested tables within a record that can contain any set of other data types. Sum is a special data type that totals a numeric column of list data, such as the total amount of an order. Data is indexed and searchable, both programmatically from KMS-enabled apps and administratively from the KMS portal. \n\n\n\n"
        callTextViewDesc.text = "KMS.singleton().datastoreGet()\n\n\n\n\n\n\n\n"
        respTextViewDesc.text = "// tap PLACE to send command //\n\n\n\n\n\n\n\n"
    }
    
    @IBAction func selectDatastoreDeletePressed(_ sender: Any) {
        resetButtonTints()
        lastButton = ActiveButton.datastoreDelete
        btn_datastoreDelete.tintColor = #colorLiteral(red: 0.538921535, green: 0.7828642726, blue: 0.9997832179, alpha: 1)

        binBtnDesc.text = "datastoreDelete"
        btnTextViewDesc.text = "DataStore functions facilitate sharing of data between tablets within an enterprise. The database has a dynamic structure that accepts and displays integer, decimal, currency, POSIX, string, list, and sum data types. Lists are nested tables within a record that can contain any set of other data types. Sum is a special data type that totals a numeric column of list data, such as the total amount of an order. Data is indexed and searchable, both programmatically from KMS-enabled apps and administratively from the KMS portal. \n\n\n\n"
        callTextViewDesc.text = "KMS.singleton().datastoreDelete()\n\n\n\n\n\n\n\n"
        respTextViewDesc.text = "// tap PLACE to send command //\n\n\n\n\n\n\n\n"
    }

    @IBAction func selectPostEventPressed(_ sender: Any) {
        resetButtonTints()
        lastButton = ActiveButton.postEvent
        btn_postEvent.tintColor = #colorLiteral(red: 0.538921535, green: 0.7828642726, blue: 0.9997832179, alpha: 1)

        binBtnDesc.text = "postEvent"
        btnTextViewDesc.text = "Posts an event of type 'AppEvent' to the portal Event Log. Events are timestamped, include tablet coordinates, and are searchable in the portal. \n\n\n\n"
        callTextViewDesc.text = "let resp:String = KMS.singleton().postEvent(\"the event message\") \nprint(\"resp = \\(resp)\") \n\n"
        respTextViewDesc.text = "// tap PLACE to send command //\n\n\n\n\n\n\n\n"
    }
    
    @IBAction func selectGeofenceStatusPressed(_ sender: Any) {
        resetButtonTints()
        lastButton = ActiveButton.geofenceStatus
        btn_geofenceStatus.tintColor = #colorLiteral(red: 0.538921535, green: 0.7828642726, blue: 0.9997832179, alpha: 1)

        binBtnDesc.text = "geofenceStatus"
        btnTextViewDesc.text = "Returns geolocation permission status and geofence state for requesting tablet. \n\n\n\n"
        callTextViewDesc.text = "KMS.singleton().geofenceStatus()\n\n\n\n\n\n\n\n"
        respTextViewDesc.text = "// tap PLACE to send command //\n\n\n\n\n\n\n\n"
    }

    @IBAction func selectWipedownNowPressed(_ sender: Any) {
        resetButtonTints()
        lastButton = ActiveButton.wipedownNow
        btn_wipedownNow.tintColor = #colorLiteral(red: 0.538921535, green: 0.7828642726, blue: 0.9997832179, alpha: 1)
        
        binBtnDesc.text = "wipedownNow"
        btnTextViewDesc.text = "call wipedown now\n \n\n\n\n"
        callTextViewDesc.text = "KMS.singleton().wipedownNow()\n\n\n\n\n\n\n\n"
        respTextViewDesc.text = "// tap PLACE to send command //\n\n\n\n\n\n\n\n"
    }
    
    @IBAction func selectWipedownStatusPressed(_ sender: Any) {
        resetButtonTints()
        lastButton = ActiveButton.wipedownStatus
        btn_wipedownStatus.tintColor = #colorLiteral(red: 0.538921535, green: 0.7828642726, blue: 0.9997832179, alpha: 1)
        
        binBtnDesc.text = "wipedownStatus"
        btnTextViewDesc.text = "call wipedown status\n \n\n\n\n"
        callTextViewDesc.text = "KMS.singleton().wipedownStatus()\n\n\n\n\n\n\n\n"
        respTextViewDesc.text = "// tap PLACE to send command //\n\n\n\n\n\n\n\n"
    }
    // -----------------------------------------------------------------------------

    @IBAction func clearButtonPress(_ sender: Any) {
        respTextViewDesc.text = "// tap PLACE to send command //\n\n\n\n\n\n\n\n"
    }

    // -----------------------------------------------------------------------------

    func call_startServices() {
        //NSLog("startSvc pressed")
        let resp:String = KMS.singleton().startServices()
        self.respTextViewDesc.text = "resp = "
        self.respTextViewDesc.text?.append(resp)
    }
    
    func call_whoAmI() {
        //NSLog("who button pressed")
        
        let whoRespDict:NSMutableDictionary = KMS.singleton().whoAmI()
        
        var whoStr:String = ""
        whoStr.append(fromDict(dict:whoRespDict, key:"enterpriseId"))
        whoStr.append(fromDict(dict:whoRespDict, key:"groupId"))
        whoStr.append(fromDict(dict:whoRespDict, key:"tabletId"))
        whoStr.append(fromDict(dict:whoRespDict, key:"deviceUUID"))
        whoStr.append(fromDict(dict:whoRespDict, key:"sdkVersion"))
        whoStr.append(fromDict(dict:whoRespDict, key:"userID"))
        whoStr.append(fromDict(dict:whoRespDict, key:"userName"))
        whoStr.append("]")
                
        self.respTextViewDesc.text = "whoRespDict = [\n"
        self.respTextViewDesc.text?.append(whoStr)
    }
    
    func call_showControls() {
        let resp:String = KMS.singleton().showControls()
        self.respTextViewDesc.text = "resp = \(resp)\n"
    }
    
    func call_hideControls() {
        let resp:String = KMS.singleton().hideControls()
        self.respTextViewDesc.text = "resp = \(resp)\n"
    }
    
    func call_openPortal() {
        let resp:String = KMS.singleton().openPortal()
        self.respTextViewDesc.text = "resp = \(resp)\n"
    }
    
    func call_userAuth() {
        let resp:String = KMS.singleton().userAuth()
        self.respTextViewDesc.text = "resp = \(resp)\n"
        //NSLog("call_userAuth")
    }
    
    func call_clearUser() {
        let resp:String = KMS.singleton().clearUser()
        self.respTextViewDesc.text = "resp = \(resp)\n"
    }
    
    
    func call_dockPairingStatus() {
        let resp:String = KMS.singleton().dockPairingStatus()
        self.respTextViewDesc.text = "resp = \(resp)\n"
    }
    
    func call_dockPairingInfo() {
        let dockPairInfoRespDict:NSMutableDictionary = KMS.singleton().dockPairingInfo()
        
        var respStr:String = ""
        respStr.append(fromDict(dict:dockPairInfoRespDict, key:"isBluetoothEnabled"))
        respStr.append(fromDict(dict:dockPairInfoRespDict, key:"isPaired"))
        respStr.append(fromDict(dict:dockPairInfoRespDict, key:"isConnected"))
        respStr.append(fromDict(dict:dockPairInfoRespDict, key:"isCommunicating"))
        
        respStr.append(fromDict(dict:dockPairInfoRespDict, key:"error"))
                
        //print("dockPairingInfo str=\(respStr)")
        self.respTextViewDesc.text = "resp = [\n\(respStr)]"
    }
    
    func call_dockUnlock() {
        let resp:String = KMS.singleton().dockUnlock()
        self.respTextViewDesc.text = "resp = \n\(resp)"
    }
    
    func call_unlockButtonState() {
        let resp:String = KMS.singleton().unlockButtonState()
        self.respTextViewDesc.text = "resp = \n\(resp)"
    }
    
    func call_dockStatus() {
        var resp:String = ""
        let dict:[String:String]? = KMS.singleton().dockStatus() as NSDictionary? as? [String: String]
        if (dict != nil) {
            getRespFromDict(dict, &resp)
        }
        else {
            resp = "no dock found"
        }
        self.respTextViewDesc.text = "resp = \n\(resp)"
    }
    
    fileprivate func getRespFromDict(_ dict: [String : String]?, _ resp: inout String) {
        for (key, value) in dict! {
            resp.append(" ")
            resp.append(key)
            resp.append(":")
            resp.append(value)
            //resp.append(",") ? need to remove from last row
            resp.append("\n")
        }
    }
    fileprivate func getRespFromDictStringAny(_ dict: [String : Any]?, _ resp: inout String) {
        for (key, value) in dict! {
            resp.append(" ")
            resp.append(key)
            resp.append(":")
            let valAsStr = String(describing: value)
            resp.append(valAsStr)
            resp.append(",");
            resp.append("\n")
        }
    }
    
    func call_dockInfo() {
        //NSLog("dockInfo button pressed")

        var resp:String = ""

        let dict:[String:String]? = KMS.singleton().dockInfo() as NSDictionary? as? [String: String]

        //print("dockInfo dict=\(String(describing: dict))")
        
        if (dict != nil) {
            getRespFromDict(dict, &resp)
        }
        else {
            resp = "no dock found"
        }
        
        self.respTextViewDesc.text = "resp = [\n\(resp) \n]"
    }
    
    func fromDict(dict:NSMutableDictionary,key:String) -> String {
        var nameValStr:String = ""
        
        if (dict.object(forKey: key) != nil) {
            nameValStr.append(" ")
            nameValStr.append(key)
            nameValStr.append(":")
            nameValStr.append(dict.value(forKey: key) as! String)
            nameValStr.append("\n")
        }
        
        return nameValStr;
    }
    
    func call_postMetric() {
        //TODO: test fails
        let resp:String = KMS.singleton().postMetric("Clicks", value: "1");
        self.respTextViewDesc.text = "resp = \(resp)\n"
    }
    
    
    func call_getMetric() {
        //NSLog("call_getMetric button pressed")

        var resp:String = ""
        
        let minPosixVal = (Int)(Date().timeIntervalSince1970 - (60 * 10));
        let maxPosixVal = (Int)(Date().timeIntervalSince1970);
        
        let dict:[String:String]? = KMS.singleton().getMetric("Clicks", minPosix: minPosixVal, maxPosix: maxPosixVal) as NSDictionary? as? [String: String]
        //NSLog("getMetric dict = \(dict)")
        
        if (dict != nil) {
            getRespFromDict(dict, &resp)
        }
        else {
            resp = "no data found"
        }
        
        self.respTextViewDesc.text = "resp = \n\(resp)"
    }
    
    func call_configStore() {
        //NSLog("call_configStore button pressed")
                
        var resp:String = ""
        
        let date = Date()
        let dateFormatter = DateFormatter()
        dateFormatter.dateFormat = "y, MMM d, HH:mm:ss"
        let dateStr = dateFormatter.string(from: date)
        
        var configVals: [String: Any] = [:]
        configVals["dateKey1"] = dateStr
        configVals["colorkey1"] = 808080
        configVals["colorkey2"] = 404040
        configVals["colorkey3"] = "threeGreen"
        
        resp = KMS.singleton().configStore("colorPrefs3", configValues:configVals)
        
        self.respTextViewDesc.text = "resp = \n\(resp)"
    }
    
    func call_configGet() {
        //NSLog("call_configGet button pressed")
        var resp:String = ""
        let dict:[String:String]? = KMS.singleton().configGet("colorPrefs3") as NSDictionary? as? [String: String]
        //NSLog("configDict dict = \(dict)")
        
        if (dict != nil) {
            getRespFromDict(dict, &resp)
        }
        else {
            resp = "no data found"
        }
        
        self.respTextViewDesc.text = "resp = \n\(resp)"

    }
    
    func call_datastoreStore() {
        let resp:String = KMS.singleton().datastoreStore()
        self.respTextViewDesc.text = "resp = \(resp)\n"
    }
    
    func call_datastoreSearch() {
        let resp:String = KMS.singleton().datastoreSearch()
        self.respTextViewDesc.text = "resp = \(resp)\n"
    }
    
    func call_datastoreGet() {
        let resp:String = KMS.singleton().datastoreGet()
        self.respTextViewDesc.text = "resp = \(resp)\n"
    }
    
    func call_datastoreDelete() {
        let resp:String = KMS.singleton().datastoreDelete()
        self.respTextViewDesc.text = "resp = \(resp)\n"
    }
    
    func call_postEvent() {
        let resp:String = KMS.singleton().postEvent("the event message")
        self.respTextViewDesc.text = "resp = \(resp)\n"
    }
    
    func call_geofenceStatus() {
        //NSLog("call geofencStatus button pressed")

        var resp:String = ""

        let dict:[String:Any]? = KMS.singleton().geofenceStatus() as NSDictionary? as? [String: Any]
        
        if (dict != nil) {
            getRespFromDictStringAny(dict, &resp)
        }
        else {
            resp = "no geofencStatus found"
        }
        
        self.respTextViewDesc.text = "resp = [\n\(resp)]"
    }
    
    func call_wipedownNow() {
        let resp:String = KMS.singleton().wipedownNow()
        self.respTextViewDesc.text = "resp = \(resp)\n"
    }
    
    func call_wipedownStatus() {
        //NSLog("call wipedownStatus button pressed")

        var resp:String = ""

        let dict:[String:Any]? = KMS.singleton().wipedownStatus() as NSDictionary? as? [String: Any]

        //print("wipedownStatus dict=\(String(describing: dict))")
        
        if (dict != nil) {
            getRespFromDictStringAny(dict, &resp)
        }
        else {
            resp = "no wipedownStatus found"
        }
        
        self.respTextViewDesc.text = "resp = [\n\(resp)]"
    }
    
    @IBAction func placeButtonPressed(_ sender: Any) {
        
        switch (lastButton) {

        case ActiveButton.startServices:
            self.call_startServices()

        case ActiveButton.whoAmI:
            self.call_whoAmI()
        case ActiveButton.showControls:
            self.call_showControls()
        case ActiveButton.hideControls:
            self.call_hideControls()
        case ActiveButton.openPortal:
            self.call_openPortal()
        case ActiveButton.userAuth:
            self.call_userAuth()
        case ActiveButton.clearUser:
            self.call_clearUser()

        case ActiveButton.dockPairingStatus:
            self.call_dockPairingStatus()
        case ActiveButton.dockPairingInfo:
            self.call_dockPairingInfo()
        case ActiveButton.dockUnlock:
            self.call_dockUnlock()
        case ActiveButton.unlockButtonState:
            self.call_unlockButtonState()
        case ActiveButton.dockStatus:
            self.call_dockStatus()
        case ActiveButton.dockInfo:
            self.call_dockInfo()
        
        case ActiveButton.postMetric:
            self.call_postMetric()
        case ActiveButton.getMetric:
            self.call_getMetric()
            
        case ActiveButton.configStore:
            self.call_configStore()
        case ActiveButton.configGet:
            self.call_configGet()
            
        case ActiveButton.datastoreStore:
            self.call_datastoreStore()
        case ActiveButton.datastoreSearch:
            self.call_datastoreSearch()
        case ActiveButton.datastoreGet:
            self.call_datastoreGet()
        case ActiveButton.datastoreDelete:
            self.call_datastoreDelete()
            
        case ActiveButton.postEvent:
            self.call_postEvent()
        case ActiveButton.geofenceStatus:
            self.call_geofenceStatus()
        case ActiveButton.wipedownNow:
            self.call_wipedownNow()
        case ActiveButton.wipedownStatus:
            self.call_wipedownStatus()
        }

    }
    
}
