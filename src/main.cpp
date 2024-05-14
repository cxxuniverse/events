#include "events.h"

enum class Events
{
    INCREASE_COUNT,
    DECREASE_COUNT
};

struct Test
{
  private:
    int size = 0;

  public:
    cxc::EventListener<Events> event_listener{};

    void increase()
    {
        size++;
    }

    void decrease()
    {
        if (size > 0)
            size--;
    }

    int get_size()
    {
        return size;
    }

    Test()
    {
        init_events();
    }

    void init_events()
    {
        event_listener.add(Events::INCREASE_COUNT, [this]() { increase(); });
        event_listener.add(Events::DECREASE_COUNT, [this]() { decrease(); });
    }
};

void something(cxc::EventListener<Events> &event_listener)
{
    event_listener.trigger(Events::DECREASE_COUNT);
    event_listener.trigger(Events::DECREASE_COUNT);
    event_listener.trigger(Events::DECREASE_COUNT);
    event_listener.trigger(Events::DECREASE_COUNT);
    event_listener.trigger(Events::DECREASE_COUNT);
}

int main()
{
    Test test{};

    test.event_listener.trigger(Events::INCREASE_COUNT);
    test.event_listener.trigger(Events::INCREASE_COUNT);
    test.event_listener.trigger(Events::INCREASE_COUNT);
    test.event_listener.trigger(Events::INCREASE_COUNT);
    test.event_listener.trigger(Events::INCREASE_COUNT);
    test.event_listener.trigger(Events::INCREASE_COUNT);

    std::cout << test.get_size() << std::endl;

    something(test.event_listener);

    std::cout << test.get_size() << std::endl;

    // event_listener.trigger(Events::INCREASE_COUNT);
}