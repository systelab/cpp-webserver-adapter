[![Build Status](https://travis-ci.org/systelab/cpp-webserver-adapter.svg?branch=master)](https://travis-ci.org/systelab/cpp-webserver-adapter)
[![Build status](https://ci.appveyor.com/api/projects/status/b2yacbbo5x9hp8cy?svg=true)](https://ci.appveyor.com/project/systelab/cpp-webserver-adapter)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/cdb01d96abbd49ba92ffb0edcff71988)](https://www.codacy.com/app/systelab/cpp-webserver-adapter?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=systelab/cpp-webserver-adapter&amp;utm_campaign=Badge_Grade)
[![Download](https://api.bintray.com/packages/systelab/conan/WebServerAdapter:systelab/images/download.svg?version=1.0.0:stable) ](https://bintray.com/systelab/conan/WebServerAdapter:systelab/1.0.0:stable/link)

# C++ Web Server Adapter

This repository defines a library-agnostic API for C++ to work with a web server.

## Supported features

* HTTP
* HTTPS
* Mutual SSL
* CORS
* Thread pool

## Available implementations

* [BoostAsioWebServerAdapter](https://github.com/systelab/cpp-boostasio-webserver-adapter)

## Usage

Use of this library begins with an instance of `systelab::web_server::IServerFactory` class. See documentation of selected implementation for details about how to build one.

### HTTP server set up

Set up a new HTTP web server by providing a configuration object that specifies host address and port:

```cpp
systelab::web_server::Configuration configuration;
configuration.setHostAddress("127.0.0.1");
configuration.setPort(8080);

systelab::web_server::IServerFactory& serverFactory = ...
std::unique_ptr<systelab::web_server::IServer> server = serverFactory.buildServer(configuration);
```

Then, register at least a web service by providing an instance of a class that implements the `systelab::web_server::IWebService` interface:

```cpp
class MyWebService : public systelab::web_server::IWebService
{
    std::unique_ptr<systelab::web_server::Reply> execute(const systelab::web_server::Request& request)
    {
        std::unique_ptr<systelab::web_server::Reply> reply;
	
        if (canServiceHandleRequest(request))
        {
	          // Process request and build a reply
        }
	
        return reply;
    }
}

auto webService = std::make_unique<MyWebService>();
webServer->registerWebService(std::move(webService));
```

Finally, start the server calling the `start()` method:

```cpp
webServer->start();
```

### HTTPS

HTTPS can be enabled through the configuration object provided when creating the server. The `systelab::web_server::SecurityConfiguration` class allows defining the paths of the certificate files as follows:

```cpp
systelab::web_server::Configuration configuration;
systelab::web_server::SecurityConfiguration& securityConfiguration = configuration.getSecurityConfiguration();
securityConfiguration.setHTTPSEnabled(true);
securityConfiguration.setServerCertificate("Server.cert");
securityConfiguration.setServerPrivateKey("Server.key");
securityConfiguration.setServerDHParam("Server.dhparam");
```

### Mutual SSL

To enable use of mutual SSL, the path of the client certificate must be specified through the security configuration of the server:

```cpp
systelab::web_server::SecurityConfiguration& securityConfiguration = configuration.getSecurityConfiguration();
securityConfiguration.setMutualSSLEnabled(true);
securityConfiguration.setClientCertificate("Client.cert");
```

### CORS configuration

The CORS configuration of the server can be defined using the `systelab::web_server::CORSConfiguration` class:

```cpp
systelab::web_server::Configuration configuration;
systelab::web_server::CORSConfiguration& corsConfiguration = configuration.getCORSConfiguration();
corsConfiguration.setEnabled(true);
corsConfiguration.setAllowedOrigins({"http://127.0.0.1:4200", "http://127.0.0.1:8082"});
corsConfiguration.setAllowedMethods({"GET", "POST", "PUT", "PATCH", "DELETE", "OPTIONS"});
corsConfiguration.setAllowedHeaders({"Origin", "Authorization", "Content-Type"});
corsConfiguration.setExposedHeaders({"Origin", "Authorization", "Content-Type"});
corsConfiguration.setMaxAge(1209600);
corsConfiguration.setAllowedCredentials(true);
```

### Thread pool configuration

The size of the pool of threads dedicated to attend server requests can be specified using the configuration option:

```cpp
systelab::web_server::Configuration configuration;
configuration.setThreadPoolSize(4);
```
