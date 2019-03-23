#pragma once

#include <memory>


namespace systelab { namespace web_server {

	class Configuration;
	class IServer;

	class IServerFactory
	{
	public:
		virtual ~IServerFactory() = default;

		virtual std::unique_ptr<IServer> buildServer(const Configuration&) const = 0;
	};

}}