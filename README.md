![GitHub license](https://img.shields.io/github/license/torresflo/Simple-Event-Library.svg)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](http://makeapullrequest.com)
![GitHub contributors](https://img.shields.io/github/contributors/torresflo/Simple-Event-Library.svg)
![GitHub issues](https://img.shields.io/github/issues/torresflo/Simple-Event-Library.svg)

<p align="center">
  <h1 align="center">Simple Event Library</h3>

  <p align="center">
    A simple and lightweight C++ event library to use out of the box.
    <br />
    <a href="https://github.com/torresflo/Simple-Event-Library/issues">Report a bug or request a feature</a>
  </p>
</p>

## Table of Contents

* [Getting Started](#getting-started)
  * [Installation](#installation)
* [Usage](#usage)
  * [Example](#example)
* [Contributing](#contributing)
* [License](#license)

## Getting Started

### Installation

Clone the repo (`git clone https:://github.com/torresflo/Simple-Event-Library.git`) and add the EventSystem folder to your project, you are ready to go!

## Usage

### Example

```cpp
#include <EventSystem\Event.hpp>
#include <EventSystem\EventHandler.hpp>
#include <EventSystem\IEventListener.hpp>

//Declaration of an event
class EventExample : public EventSystem::Event {};

//Declaration of an event listener for this event
class EventListenerExample : public EventSystem::IEventListener
{
public:
    virtual void onEvent(const EventSystem::Event & event) override { /*Do something...*/ }
};

//Usage
EventListenerExample listener;
EventSystem::EventHandler eventHandler;

eventHandler.registerListener<EventExample>(&listener);
eventHandler.sendEvent<EventExample>(/*Parameters of the event if needed*/);
eventHandler.unregisterListener<EventExample>(&listener);
```

## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<!-- LICENSE -->
## License

Distributed under the GNU General Public License v3.0. See `LICENSE` for more information.
