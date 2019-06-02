#ifndef EVENTSYSTEM_IEVENTLISTENER_HPP
#define EVENTSYSTEM_IEVENTLISTENER_HPP

#include <EventSystem\Event.hpp>

namespace EventSystem
{

class IEventListener
{
public:
	virtual void onEvent(const Event& event) = 0;
};

}

#endif // !EVENTSYSTEM_IEVENTLISTENER_HPP
