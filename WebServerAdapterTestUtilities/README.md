# Test utilities for C++ Web Server Adapter
This folder contains Google test utilities for any library that implements the [C++ Web Server adapter](https://github.com/systelab/cpp-web-server-adapter) interface.

The following types of utilities are available:
* *Interface mocks*: defined using Google Mock framework, allows mocking the Web Server adapter
* *Entity comparators*: allows comparing two web server items (replies, requests, ...) and provides a detailed message with the first difference found
