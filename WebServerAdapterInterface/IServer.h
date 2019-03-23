#pragma once

#include <memory>

namespace systelab { namespace web_server {

	class Configuration;
	class IWebService;

	class IServer
	{
	public:
		virtual ~IServer() = default;

		virtual void registerWebService(std::unique_ptr<IWebService>) = 0;

		virtual bool isRunning() const = 0;
		virtual void start() = 0;
		virtual void stop() = 0;

	public:
		struct Exception : public std::runtime_error
		{
			Exception(const std::string& message)
				:std::runtime_error(message.c_str())
			{}
		};
	};

}}
