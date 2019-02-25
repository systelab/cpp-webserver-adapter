#pragma once

#include <memory>

namespace systelab { namespace web_server {

	class Configuration;
	class IService;

	class IServer
	{
	public:
		virtual ~IServer() = default;

		virtual void setConfiguration(std::unique_ptr<Configuration>) = 0;
		virtual void registerWebService(std::unique_ptr<IService>) = 0;

		virtual bool isRunning() const = 0;
		virtual void start() = 0;
		virtual void stop() = 0;
	};

}}
