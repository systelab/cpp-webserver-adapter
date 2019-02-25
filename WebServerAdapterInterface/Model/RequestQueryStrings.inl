
namespace systelab { namespace web_server {

	RequestQueryStrings::RequestQueryStrings()
		:m_items()
	{
	}

	RequestQueryStrings::RequestQueryStrings(const std::map<std::string, std::string>& items)
		: m_items(items)
	{
	}

	RequestQueryStrings::~RequestQueryStrings()
	{
	}

	bool RequestQueryStrings::hasItem(const std::string& name) const
	{
		return (m_items.find(name) != m_items.end());
	}

	std::string RequestQueryStrings::getItem(const std::string& name) const
	{
		auto it = m_items.find(name);
		if (m_items.find(name) != m_items.end())
		{
			return it->second;
		}
		else
		{
			std::string exc = std::string("Query string item '") + name + std::string("' not found.");
			throw std::exception(exc.c_str());
		}
	}

	std::map<std::string, std::string> RequestQueryStrings::getItemsMap() const
	{
		return m_items;
	}

	void RequestQueryStrings::addItem(const std::string& name, const std::string& value)
	{
		m_items.insert(std::make_pair(name, value));
	}

}}