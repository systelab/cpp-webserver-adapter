#pragma once

#include <string>
#include <map>


namespace systelab { namespace web_server {

	class RequestQueryStrings
	{
	public:
		inline RequestQueryStrings();
		inline RequestQueryStrings(const RequestQueryStrings&);
		inline RequestQueryStrings(const std::map<std::string, std::string>&);
		inline virtual ~RequestQueryStrings();

		inline bool hasItem(const std::string& name) const;
		inline std::string getItem(const std::string& name) const;
		inline std::map<std::string, std::string> getItemsMap() const;

		inline void addItem(const std::string& name, const std::string& value);

	private:
		inline std::string toLowerCase(const std::string&) const;

	private:
		std::map<std::string, std::string> m_items;
	};

}}

#include "RequestQueryStrings.inl"