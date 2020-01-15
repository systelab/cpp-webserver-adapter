#pragma once

#include <memory>


namespace systelab { namespace web_server {

	class Reply;
	class Request;

	class IClient
	{
	public:
		virtual ~IClient() = default;

		virtual std::unique_ptr<Reply> send(const Request&) const = 0;
	};

}}
