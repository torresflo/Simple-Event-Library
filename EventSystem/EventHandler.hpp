#ifndef EVENTSYSTEM_EVENTHANDLER_HPP
#define EVENTSYSTEM_EVENTHANDLER_HPP

#include <unordered_map>
#include <vector>
#include <functional>

#include <EventSystem\EventID.hpp>
#include <EventSystem\IEventListener.hpp>

namespace EventSystem
{

class EventHandler
{
public:
	template <typename TEvent>
	void registerListener(IEventListener* listener);

	template <typename TEvent>
	void unregisterListener(IEventListener* listener);

	template <typename TEvent, typename ...Args>
	void sendEvent(Args... args);

	template <typename TEvent>
	void sendEvent(const TEvent& event);

	template <typename TEvent>
	unsigned int getNbOfListeners() const;

	void unregisterAll();

private:
	using IEventListenerPtrList = std::vector<IEventListener*>;

	std::unordered_map<EventID, IEventListenerPtrList> m_Listeners;
};

}

#include <EventSystem\EventHandler.inl>

#endif // !EVENTSYSTEM_EVENTHANDLER_HPP
