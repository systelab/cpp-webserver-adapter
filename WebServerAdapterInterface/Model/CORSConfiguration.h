#pragma once

#include <set>


namespace systelab { namespace web_server {

	class CORSConfiguration
	{
	public:
		inline CORSConfiguration();
		inline CORSConfiguration(const CORSConfiguration&);
		inline virtual ~CORSConfiguration();

		inline bool isEnabled() const;
		inline bool isAllowedOrigin(const std::string&) const;
		inline std::string getAllowedHeaders() const;
		inline std::string getAllowedMethods() const;
		inline bool areAllowedCredentials() const;
		inline unsigned int getMaxAge() const;
		inline std::string getExposedHeaders() const;

		inline void setEnabled(bool enabled);
		inline void addAllowedOrigin(const std::string&);
		inline void setAllowedHeaders(const std::string&);
		inline void setAllowedMethods(const std::string&);
		inline void setAllowedCredentials(bool);
		inline void setMaxAge(unsigned int);
		inline void setExposedHeaders(const std::string&);

		inline CORSConfiguration& operator= (const CORSConfiguration& other);

	private:
		bool m_enabled;
		std::set<std::string> m_allowedOrigins;
		std::string m_allowedHeaders;
		std::string m_allowedMethods;
		bool m_allowedCredentials;
		unsigned int m_maxAge;
		std::string m_exposedHeaders;
	};

}}

#include "CORSConfiguration.inl"