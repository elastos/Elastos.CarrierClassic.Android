04/26/2019 Zhao Zhenxuan 757372373@qq.com
Release-v5.2.2 Main changes:

```markdown
- Update project settings along with last android studio-3.3.2 and  modify outdated methods
- Update License to be GPLv3 with regards to c-toxcore project.
- Resolve  compilation failure  due to setting updating;
- Bugfix for open channel of Session module;
- Update gradle files to be possible to distribute Carrier aar package via jcenter.
```

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

