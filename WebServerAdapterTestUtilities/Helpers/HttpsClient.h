#pragma once

#include "stdafx.h"

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include "Webserver/SecuredServer.h"

namespace http {
namespace server {
namespace test_utility {

class HTTPSyncClient
{
public:
	HTTPSyncClient(SecuredServer::Credentials& serverCredentials, SecuredServer::Credentials& clientCredentials,
		const std::string&, const std::string&);
	~HTTPSyncClient();
	bool send(std::string path, std::map<std::string, std::string>& headers, std::string& content);
private:
	bool receive(std::map<std::string, std::string>& headers, std::string& content);

	bool setServerCertificate(const std::string& certificate); //context_->use_certificate_file("certs/server/cert.crt", boost::asio::ssl::context::pem);
	bool setClientCertificate(const std::string& certificate);
	bool HTTPSyncClient::setClientPrivateKey(const std::string& privateKey); //context_->use_private_key_file("certs/server/key.pem", boost::asio::ssl::context::pem);
private:
	boost::asio::io_service m_io_service;
	std::string m_server;
	std::string m_port;
	std::string m_root;
	std::auto_ptr<boost::asio::ssl::stream<boost::asio::ip::tcp::socket>> m_socket;
	boost::asio::ssl::context context_;
};
}
}
}