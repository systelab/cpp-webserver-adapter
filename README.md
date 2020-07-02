[![Build Status](https://travis-ci.org/systelab/cpp-webserver-adapter.svg?branch=master)](https://travis-ci.org/systelab/cpp-webserver-adapter)
[![Build status](https://ci.appveyor.com/api/projects/status/nh73hrkbkcivaprl?svg=true)](https://ci.appveyor.com/project/systelab/cpp-websockets-adapter)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/cdb01d96abbd49ba92ffb0edcff71988)](https://www.codacy.com/app/systelab/cpp-webserver-adapter?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=systelab/cpp-webserver-adapter&amp;utm_campaign=Badge_Grade)
[![Download](https://api.bintray.com/packages/systelab/conan/WebServerAdapterInterface:systelab/images/download.svg)](https://bintray.com/systelab/conan/WebServerAdapterInterface:systelab/_latestVersion)

# C++ Web Server Adapter

This repository defines a library-agnostic API for C++ to work with a web server.

## Supported features

* Server and client
* HTTP
* HTTPS
* Mutual SSL
* CORS
* Thread pool
* GZIP compression

## Available implementations

* [BoostAsioWebServerAdapter](https://github.com/systelab/cpp-boostasio-webserver-adapter)
* [HttpLibWebServerAdapter](https://github.com/systelab/cpp-httplib-webserver-adapter)

## Usage

Use of this library begins with an instance of:
* `systelab::web_server::IServerFactory` class (for server features)
* `systelab::web_server::IClientFactory` class (for client features)

See documentation of selected implementation for details about how to build one.

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

Additionally, support for specific [TLS](https://wiki.openssl.org/index.php/SSL/TLS_Client) versions can be enabled/disabled:

```cpp
securityConfiguration.setTLSv12Enabled(false);
securityConfiguration.setTLSv13Enabled(true);
```

> By default only TLS v1.2 is enabled. TLS v1.3 needs to be enabled on demand because it is not supported before OpenSSL 1.1.1. Older TLS versions should be always disabled as they have known security vulnerabilities.

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

### GZIP compression

The server can be configured to automatically apply gzip compression to payload of replies by enabling the following configuration option:

```cpp
systelab::web_server::Configuration configuration;
configuration.setGZIPCompressionEnabled(true);
```

### HTTP/HTTPS client usage

Set up a new HTTP client by providing a server IP address and a port number:

```cpp
systelab::web_server::IClientFactory& clientFactory = ...
std::unique_ptr<systelab::web_server::IClient> client = clientFactory.buildHTTPClient("127.0.0.1", 8080);
```

Similarly, an HTTPS client can be created as follows:

```cpp
systelab::web_server::IClientFactory& clientFactory = ...
std::unique_ptr<systelab::web_server::IClient> client = clientFactory.buildHTTPSClient("localhost", 9090);
```

Then, the returned `systelab::web_server::IClient` object can be used to send requests to the server:

```cpp
systelab::web_server::Request request;
request.setMethod("POST");
request.setURI("/rest/api/login"); 
request.setContent("PasswordGoesHere");
request.getHeaders().addHeader("Content-Type", "text/plain");

std::unique_ptr<Reply> reply = client->send(request);

systelab::web_server::Reply::StatusType status = reply->getStatus();
std::map<std::string, std::string> headers = reply->getHeaders();
std::string content = reply->getContent();
```
