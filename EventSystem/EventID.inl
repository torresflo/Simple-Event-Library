namespace EventSystem
{

template <typename TEventBase>
EventID EventIDGenerator<TEventBase>::m_nextEventId = 0;

template<typename TEventBase>
template<typename TEvent>
inline EventID EventIDGenerator<TEventBase>::getEventId()
{
	static const EventID id = m_nextEventId++;
	return id;
}

}