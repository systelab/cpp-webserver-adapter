#include <algorithm>
#include <stdexcept>


namespace systelab { namespace web_server {

	RequestQueryStrings::RequestQueryStrings()
		:m_items()
	{
	}

	RequestQueryStrings::RequestQueryStrings(const RequestQueryStrings& other)
		:m_items(other.m_items)
	{
	}

	RequestQueryStrings::RequestQueryStrings(const std::map<std::string, std::string>& items)
		: m_items()
	{
		for (auto item : items)
		{
			m_items.insert({ toLowerCase(item.first),  toLowerCase(item.second) });
		}
	}

	RequestQueryStrings::~RequestQueryStrings()
	{
	}

	bool RequestQueryStrings::hasItem(const std::string& name) const
	{
		return (m_items.find(toLowerCase(name)) != m_items.end());
	}

	std::string RequestQueryStrings::getItem(const std::string& name) const
	{
		auto it = m_items.find(toLowerCase(name));
		if (it != m_items.end())
		{
			return it->second;
		}
		else
		{
			std::string exc = std::string("Query string item '") + toLowerCase(name) + std::string("' not found.");
			throw std::runtime_error(exc.c_str());
		}
	}

	std::map<std::string, std::string> RequestQueryStrings::getItemsMap() const
	{
		return m_items;
	}

	void RequestQueryStrings::addItem(const std::string& name, const std::string& value)
	{
		m_items.insert(std::make_pair(toLowerCase(name), toLowerCase(value)));
	}

	RequestQueryStrings& RequestQueryStrings::operator= (const RequestQueryStrings& other)
	{
		m_items = other.m_items;
		return *this;
	}

	std::string RequestQueryStrings::toLowerCase(const std::string& value) const
	{
		std::string lowerValue = value;
		std::transform(lowerValue.begin(), lowerValue.end(), lowerValue.begin(),
			[](unsigned char c) -> unsigned char
			{
				if (c <= 'Z' && c >= 'A')
				{
					return c - ('Z' - 'z');
				}
				else
				{
					return c;
				}
			}
		);

		return lowerValue;
	}

}}