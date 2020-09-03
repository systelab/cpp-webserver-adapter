#include <stdexcept>


namespace systelab { namespace web_server {

	RequestHeaders::RequestHeaders()
		:m_headers()
	{
	}

	RequestHeaders::RequestHeaders(const RequestHeaders& other)
		:m_headers(other.m_headers)
	{
	}

	RequestHeaders::RequestHeaders(const std::map<std::string, std::string>& headers)
		: m_headers(headers)
	{
	}

	RequestHeaders::~RequestHeaders() = default;

	bool RequestHeaders::hasHeader(const std::string& name) const
	{
		return (m_headers.find(name) != m_headers.end());
	}

	std::string RequestHeaders::getHeader(const std::string& name) const
	{
		auto it = m_headers.find(name);
		if (m_headers.find(name) != m_headers.end())
		{
			return it->second;
		}
		else
		{
			throw std::runtime_error("Header '" + name + "' not found.");
		}
	}

	std::map<std::string, std::string> RequestHeaders::getHeadersMap() const
	{
		return m_headers;
	}

	void RequestHeaders::addHeader(const std::string& name, const std::string& value)
	{
		m_headers.insert(std::make_pair(name, value));
	}

	RequestHeaders& RequestHeaders::operator= (const RequestHeaders& other)
	{
		m_headers = other.m_headers;
		return *this;
	}

}}