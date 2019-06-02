#ifndef EVENTSYSTEM_EVENT_HPP
#define EVENTSYSTEM_EVENT_HPP

namespace EventSystem
{

class EventHandler;

class Event
{
public:
	EventHandler* getSender() const;

private:
	EventHandler* m_EventHandler = nullptr;

	friend class EventHandler;
};

}

#endif // !EVENTSYSTEM_EVENT_HPP
