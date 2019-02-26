#pragma once

#include "WebServerAdapterInterface/Model/SecuredServerCredentials.h"

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>


namespace systelab { namespace web_server { namespace test_utility {

	class HttpsClient
	{
	public:
		HttpsClient(SecuredServerCredentials&,
					const std::string& server,
					const std::string& port);
		virtual ~HttpsClient();

		bool send(std::string path, std::map<std::string, std::string>& headers, std::string& content);

	private:
		bool receive(std::map<std::string, std::string>& headers, std::string& content);
		bool setServerCertificate(const std::string& certificate);

	private:
		boost::asio::io_service m_io_service;
		std::string m_server;
		std::string m_port;
		std::string m_root;
		std::auto_ptr<boost::asio::ssl::stream<boost::asio::ip::tcp::socket>> m_socket;
		boost::asio::ssl::context context_;
	};

}}}

