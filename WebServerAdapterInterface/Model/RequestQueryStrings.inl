
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
			throw std::runtime_error("Query string item '" + name + "' not found.");
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