namespace EventSystem
{

template<typename TEvent>
inline void EventHandler::registerListener(IEventListener * listener)
{
	static_assert(std::is_base_of<Event, TEvent>::value, "TEvent should be a derived class of Event");

	EventID id = EventIDGenerator<Event>::getEventId<TEvent>();
	m_Listeners[id].push_back(listener);
}

template<typename TEvent>
inline void EventHandler::unregisterListener(IEventListener* listener)
{
	static_assert(std::is_base_of<Event, TEvent>::value, "TEvent should be a derived class of Event");

	EventID id = EventIDGenerator<Event>::getEventId<TEvent>();
	IEventListenerPtrList& listeners = m_Listeners[id];

	for (auto iterator = listeners.begin(); iterator != listeners.end(); ++iterator)
	{
		if (*iterator == listener)
		{
			listeners.erase(iterator);
			break;
		}
	}
}

template<typename TEvent, typename ...Args>
inline void EventHandler::sendEvent(Args ...args)
{
	static_assert(std::is_base_of<Event, TEvent>::value, "TEvent should be a derived class of Event");

	TEvent event(args...);
	sendEvent(event);
}

template<typename TEvent>
inline void EventHandler::sendEvent(const TEvent& event)
{
	static_assert(std::is_base_of<Event, TEvent>::value, "TEvent should be a derived class of Event");

	const_cast<TEvent&>(event).m_EventHandler = this;
	EventID id = EventIDGenerator<Event>::getEventId<TEvent>();
	if (m_Listeners.find(id) != m_Listeners.end())
	{
		for (IEventListener* listener : m_Listeners.at(id))
		{
			listener->onEvent(event);
		}
	}
}

template<typename TEvent>
inline unsigned int EventHandler::getNbOfListeners() const
{
	static_assert(std::is_base_of<Event, TEvent>::value, "TEvent should be a derived class of Event");
	EventID id = EventIDGenerator<Event>::getEventId<TEvent>();

	if (m_Listeners.find(id) != m_Listeners.end())
	{
		return m_Listeners.at(id).size();
	}

	return 0u;
}

void EventHandler::unregisterAll()
{
	m_Listeners.clear();
}

}