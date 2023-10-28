# KMS SDK Demo

**SDK Demo Source Code Disclaimer**

The source code for the "SDK Demo" iOS application is provided on an as-is basis. Developers may copy and utilize the source code as desired. By  using the code, developers acknowledge that they do so at their own discretion and assume full responsibility for the functionality of the  applications they develop.

Lilitab provides no warranties, expressed or implied, regarding the suitability of the code for developers' intended applications or its  compatibility with developers' development environments. Lilitab does not provide technical support for the implementation or troubleshooting  of customer applications which use sample code or the KMS SDK.

Lilitab reserves the right to update the KMS SDK periodically at its own discretion. The enterprise agent will be notified of changes that may  impact the operation and availability of existing SDK functions.

**Usage**

KMS SKD Demo illustrates various ways in which the LilitabSDK can be called. (Most of which are used after a tablet is registered in KMS)

For more details on how to use LilitabSDK, please refer to: [SDK Reference Guide](https://lilitabkmspdfs.s3.us-west-2.amazonaws.com/SDK+Reference+Guide+v4.03.pdf)<br>
For SmartDOCK Connect, please refer to: [SmartDOCK Connect Quick Start Guide](https://lilitabkmspdfs.s3.us-west-2.amazonaws.com/Lilitab+SmartDOCK+Connect+Quick+Start+Guide%2C+v1.00.pdf)

**Build Notes**

1. clone the KMS SDK Demo repository located at: https://github.com/Lilitab/KMS-SDK-Demo.git
2. from Xcode, open the project: "kmsSdkDemo.xcodeproj" that you just cloned
3. verify that the file "LilitabSDK.xcframework" is located at the root of kmsSdkDemo project.
Please note that you will need to include the library "LilitabSDK.xcframework" in your own project to work with KMS services. Also make sure that you select "Embed & Sign" from "Frameworks, Libraries & Embedded content" on your general project settings
4. to run this project, you will need to deploy to an actual iPad (an iOS simulator target will not work)
5. attach your iPad via usb cable and select the target ipad from build-target/devices
6. run the project. note: once the app is running, first select "startServices" and click "place" on CALL panel. Follow any tablet registration instructions from there (this will only be needed when tablet has not yet been registered in your enterprise).

