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
		inline void setEnabled(bool enabled);

		inline bool isAllowedOrigin(const std::string&) const;
		inline std::set<std::string> getAllowedOrigins() const;
		inline void addAllowedOrigin(const std::string&);
		inline void setAllowedOrigins(const std::set<std::string>&);

		inline bool isAllowedMethod(const std::string&) const;
		inline std::set<std::string> getAllowedMethods() const;
		inline void addAllowedMethod(const std::string&);
		inline void setAllowedMethods(const std::set<std::string>&);

		inline bool isAllowedHeader(const std::string&) const;
		inline std::set<std::string> getAllowedHeaders() const;
		inline void addAllowedHeader(const std::string&);
		inline void setAllowedHeaders(const std::set<std::string>&);

		inline bool isExposedHeader(const std::string&) const;
		inline std::set<std::string> getExposedHeaders() const;
		inline void addExposedHeader(const std::string&);
		inline void setExposedHeaders(const std::set<std::string>&);

		inline bool areAllowedCredentials() const;
		inline void setAllowedCredentials(bool);

		inline unsigned int getMaxAge() const;
		inline void setMaxAge(unsigned int);

		inline CORSConfiguration& operator= (const CORSConfiguration&);

	private:
		bool m_enabled;
		std::set<std::string> m_allowedOrigins;
		std::set<std::string> m_allowedMethods;
		std::set<std::string> m_allowedHeaders;
		std::set<std::string> m_exposedHeaders;
		bool m_allowedCredentials;
		unsigned int m_maxAge;
	};

}}

#include "CORSConfiguration.inl"
