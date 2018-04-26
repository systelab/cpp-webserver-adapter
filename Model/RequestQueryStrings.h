#pragma once

#include <string>
#include <map>


namespace systelab { namespace web_server {

	class RequestQueryStrings
	{
	public:
		RequestQueryStrings();
		RequestQueryStrings(const std::map<std::string, std::string>&);
		virtual ~RequestQueryStrings();

		bool hasItem(const std::string& name) const;
		std::string getItem(const std::string& name) const;

		void addItem(const std::string& name, const std::string& value);

	private:
		std::map<std::string, std::string> m_items;
	};

}}
