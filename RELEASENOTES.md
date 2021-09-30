# Summary of changes

## Changes for version 1.1.10 (30 Sep 2021)

### Bug Fixes

- Moved continuous integration to Jenkins
- Deploy conan package into remote specific for C++ task force
- Fixed use of "export_sources" definition in conan recipes


## Changes for version 1.1.9 (1 Apr 2021)

### Bug Fixes

- Moved deploy of Conan packages to CSW JFrogPlatform
- Moved VS2017 configurations to GoogleTest 1.10


## Changes for version 1.1.8 (25 Feb 2021)

### Bug Fixes

- Updated continuous integration to:
  - Use GitHub Action to generate library documentation
  - Upload generated packages to Systelab's public Artifactory


## Changes for version 1.1.7 (4 Sep 2020)

### Bug Fixes

- Replaced URI full attribute by a method that calculates its value on demand


## Changes for version 1.1.6 (4 Sep 2020)

### Bug Fixes

- Added "URI Full" attribute (URI including query strings) to Request model
- Added builder test utilities for Request and Reply entities


## Changes for version 1.1.5 (2 Jun 2020)

### Bug Fixes

- Used gtest from conan-center (without username/channel)


## Changes for version 1.1.4 (22 May 2020)

### Bug Fixes

- Added support for enabling/disabling TLS versions


## Changes for version 1.1.3 (21 May 2020)

### Bug Fixes

- Fixed mock for ServerFactory so it now perfectly matches with the associated interface


## Changes for version 1.1.2 (7 Feb 2020)

### Bug Fixes

- Added missing include on inline files


## Changes for version 1.1.1 (7 Feb 2020)

### Bug Fixes

- Fixed compilation for GTest 1.10.0
- Fixed compilation for Visual Studio 2019


## Changes for version 1.1.0 (15 Jan 2020)

### Enhancements

- Added interface for HTTP/HTTPS clients


## Changes for version 1.0.4 (13 Jan 2020)

### Bug Fixes

- Allow configuring server to use GZIP compression


## Changes for version 1.0.3 (27 Nov 2019)

### Bug Fixes

- Allow configuring web server as using a single IP address or binding to all IP addresses


## Changes for version 1.0.2 (23 Oct 2019)

### Bug Fixes

- Splitted Conan packages of this repository in two:
  - WebServerAdapterInterface (header only package)
  - WebServerAdapterTestUtilities


## Changes for version 1.0.1 (3 Aug 2019)

### Bug Fixes

- Improved cmake and conan configuration to link only against used dependencies


## Changes for version 1.0.0 (4 Apr 2019)

### Enhancements

- Initial version on GitHub
