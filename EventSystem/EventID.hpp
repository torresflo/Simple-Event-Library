#ifndef EVENTSYSTEM_EVENTID_HPP
#define EVENTSYSTEM_EVENTID_HPP

#include <cstddef>
#include <type_traits>

#include <EventSystem\Event.hpp>

namespace EventSystem
{

typedef std::size_t EventID;

template <typename TEventBase>
class EventIDGenerator
{
	static_assert(std::is_base_of<Event, TEventBase>::value, "TEvent should be a derived class of Event");

public:
	template <typename TEvent>
	static EventID getEventId();

private:
	static EventID m_nextEventId;
};

}

#include <EventSystem\EventID.inl>

#endif // !EVENTSYSTEM_EVENTID_HPP
