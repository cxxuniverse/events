# C++ Event Listener

A lightweight event listener library for C++, allowing easy integration into existing projects.
It provides functionality for both listening to events and dispatching them, allowing bound functions or handlers to be called when events occur.

## Example Usage

```cpp
#include "events.h"

enum class Events
{
    INCREASE_COUNT,
    DECREASE_COUNT
};

struct Test
{
    int size = 0;
    cxc::EventListener<Events> event_listener{};

    void increase() { size++; }
    void decrease() { size--; }
    int get_size() { return size; }

    Test() { init_events(); }
    void init_events() { 
        /* Event handler initialization */
        event_listener.add(Events::INCREASE_COUNT, [this]() { increase(); });
        event_listener.add(Events::DECREASE_COUNT, [this]() { decrease(); });
    }
};

void some_function(cxc::EventListener<Events> &event_listener) { /* Event trigger */ }

void some_other_function(cxc::EventListener<Events> &event_listener) { 
    event_listener.trigger(Events::DECREASE_COUNT);
}

int main()
{
    Test test{};
    test.event_listener.trigger(Events::INCREASE_COUNT);
    std::cout << test.get_size() << std::endl;
    some_function(test.event_listener);
    std::cout << test.get_size() << std::endl;
}

```