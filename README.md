[![Build Status](https://travis-ci.org/systelab/cpp-webserver-adapter.svg?branch=master)](https://travis-ci.org/systelab/cpp-webserver-adapter)
[![Build status](https://ci.appveyor.com/api/projects/status/b2yacbbo5x9hp8cy?svg=true)](https://ci.appveyor.com/project/systelab/cpp-webserver-adapter)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/cdb01d96abbd49ba92ffb0edcff71988)](https://www.codacy.com/app/systelab/cpp-webserver-adapter?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=systelab/cpp-webserver-adapter&amp;utm_campaign=Badge_Grade)

# C++ Web Server Adapter

This repository defines a library-agnostic API for C++ to work with a web server.

## Supported features

* HTTP server
* HTTPS server
* Mutual SSL
* CORS configuration
* Thread pool configuration

## Available implementations

* [BoostAsioWebServerAdapter](https://github.com/systelab/cpp-boostasio-webserver-adapter)

## Usage

Use of this library begins with an instance of `systelab::web_server::IServerFactory` class. See documentation of selected implementation for details about how to build one.

### HTTP server

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

### HTTPS server

`TBD`

### Mutual SSL

`TBD`

### CORS configuration

`TBD`

### Thread pool configuration

`TBD`
