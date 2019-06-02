#include <EventSystem\Event.hpp>

namespace EventSystem
{

EventHandler* Event::getSender() const
{
	return m_EventHandler;
}

}