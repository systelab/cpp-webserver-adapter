#pragma once

#include <set>


namespace systelab { namespace web_server {

	class CORSConfiguration
	{
	public:
		CORSConfiguration();
		CORSConfiguration(const CORSConfiguration&);
		virtual ~CORSConfiguration();

		bool isEnabled() const;
		void setEnabled(bool enabled);

		bool isAllowedOrigin(const std::string&) const;
		void addAllowedOrigin(const std::string&);

		CORSConfiguration& operator= (const CORSConfiguration& other);

	private:
		bool m_enabled;
		std::set<std::string> m_allowedOrigins;
	};

}}
