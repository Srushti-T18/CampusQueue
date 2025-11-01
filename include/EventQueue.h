#ifndef EVENTQUEUE_H
#define EVENTQUEUE_H

#include <queue>
#include "Event.h"

class EventQueue {
private:
    std::queue<Event> events;

public:
    void enqueue(const Event& e);
    void dequeue();
    Event* findEvent(const std::string& eventName);
    void showAllEvents();
    bool isEmpty() const;
};

#endif
