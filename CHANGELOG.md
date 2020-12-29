12/29/2020 Li Fenxiang  <lifenxiang@trinity-tech.io>

Release-v6.0.2-hotfix Main changes:

    - Synchronized with using the latest native SDK v6.0.2-hotfix

12/16/2020 Li Fenxiang  <lifenxiang@trinity-tech.io>

Release-v6.0.1 Main changes:

    - Internal bugfix for file-transfer module;
    - Implemented the extension module for WebRTC with the latest native extension APIs;
    - Fixed the issue related to the Gradle build project;
    - Synchronized with using the latest native SDK v6.0.1
    - Removed the deprecated public method: Carrier.sendFriendMessage()  to return value indicating as online or offline message.

08/10/2020 Meng Xiaokun  <mengxiaokun@trinity-tech.io>

Release-v5.6.3 Main changes:
	Carrier:
    - Remove express config ece01.io.

	Native carrier lib changes:
    - the expiration internal of receipt message to be 60s.
    - Open bulkmsg offline testcase.
    - Remove domain "ece01.trinity-tech.io" from configuration list  of express servers.
    - Fix send friend message return issue.
    - fix invite friend expire issue.
    - Fix libcrystal large buffer alloc crash issue.
    - Fix the markdown format errors in README.
    - Bugfix for synchronize for waiting for robot to be ready to let robot accept offline friend request.
    - Refinement for group testcases.
    - Refine for testcase to test API of 'ela_send_message_with_receipt'.
    - Make testcase of sending offline friend request as standalone testcase.
    - Resolve offline message to run with success in a row.
    - format improvementment for seerval internal headers.
    - format ela_error.h with delcaration with ela_set/get_error().
    - Make implementation of ela_get_turn_server as standalone file.
    - Improvement on internal computation of expires timestamp.
    - Bugfix for receipt notification on offline friend request.
    - Fix unstable issue for receipt testcases in elatests.
    - Improvement for notification implementation on offline event.
    - Update Android build to NDK r21d and cmake 3.16.3 on Ubuntu20.04.
    - improvement for removal of friends.
    - Bugfix for update offline state as outer parameters.
    - Improvement on internal implementation of ela_send_message_xxx APIs and a bugfix for friend notification.
    - Improvment internal implementation on internal function notify_friends.
    - Improvement on internal implementation of ela_run function.
    - Improvement on implementation of mechanism to triggger for pulling offline messages.


07/06/2020 Meng Xiaokun  <mengxiaokun@trinity-tech.io>

Release-v5.6.2 Main changes:
	Carrier:
    - Update Group.getId() to public.
	- add parameter secret_key.

	Native carrier lib changes:
	- Update libsodium to 1.0.18.
	- Fix crash issue when online message send timeout.


06/18/2020 Meng Xiaokun  <mengxiaokun@trinity-tech.io>

Release-v5.6.1 Main changes:
	Carrier:
	- Fix express log.

	Native carrier lib changes:
	- Support to disabling offline message.
	- Resolve internal memory leakage issues.
	- Fix curl dependencies.
	- update libressl to v2.9.2.
	- Update Dockerfile to ubuntu:18.04 and correct docs variable reference.
	- update flatcc to 0.6.0.
	- Fix connector destroy bug.
	- Support pre-defined secret key.
	- fix send_friend_message side issue.
	- Improving express node access order.
	- Fix ios static library install issue.
	- Fix receipt thread sync issue.


05/27/2020 Meng Xiaokun  <mengxiaokun@trinity-tech.io>

Release-v5.6.0 Main changes:

- add receipt message testcases.
- Added APIs sendMessage() with receipt notification (#95)
- add bulk message test case.
- fix bulkmsg, update message max size.



04/30/2020 Meng Xiaokun  <mengxiaokun@trinity-tech.io>

Release-v5.5.1 Main changes:

- add bulk message test case.
- update bulk message max size.
- Updates testcases refereneces to create carrier instances APIs
- Added some extension feature for webrtc
- Add filetransfer-related test cases.
- Added test cases for offline messaging, but now blocked



03/31/2020 Wang Ran <snackwang.petter@gmail.com>

Release-v5.5.0 Main changes:

	
	Interface changes：
	Carrier:
	- remove Carrier.getInstance();
	- remove Carrier.initializeInstance(options, handler);
	- Create the Carrier instance and return it，using Carrier.createInstance(options, handler); 
	Group:
	- Replace carrier.newGroup(groupHandler) with carrier.newGroup();
	Session/FileTransfer Manager:
	- remove Manager.initializeInstance(carrier) and Manager.initializeInstance(carrier, handler);
	- remove Manager.getInstance();
	- Create the Manager instance and return it，using Manager.createInstance(carrier) or Manager.createInstance(carrier, handler);

	Other changes:
	- Be able to create multiple carrier instances now, which required by Trinity (or elastOS). General application over Carrier network should still keep using singleton carrier instance under application context.
	- All groups in Carrier context updated to share one GroupHandler, and become part of CarrierHandler .

	Native carrier lib changes:
	- Correct default port value for IPFS node service.
	- Fix cmake typo.
	- Update cygwin.
	- Allow ela_get_groups() to be called in the whole lifecycle of carrier due to introduction of persistent group.




01/28/2019 Tang Zhilong  <stiartsly@gmail.com>

Release-v5.2.1 Main changes:

	- Support carrier group without central administration, and group peers should be required connected to carrier network;
	- Support file transfer between to carrier peers with pull-driven mode and support to resume transfering from previous break-point as well;
	- Support to send binary message for either carrier or session;
	- Enlarge the invitation data length to almost 8K bytes when sending invitation request/reply message;
	- Refactored exception implementation;
	- Refactored API testsuites to be compatible to use Native Robot (A test stub deaemon);
	- Optimization and bugfixes to carrier/session/stream module;
	- Bugfix for low chance of succeeding to esablish session connectivity when both pees' network topology is behind symmetric NAT.
	- Integrate CI procedure.
