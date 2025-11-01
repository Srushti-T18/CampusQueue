#ifndef EVENTTREE_H
#define EVENTTREE_H

#include <iostream>
#include <string>
#include <vector>
#include "Event.h"

class EventNode {
public:
    Event event;
    std::vector<EventNode*> subEvents;

    EventNode(Event e) : event(e) {}
};

class EventTree {
    std::vector<EventNode*> roots;

    EventNode* findEventNode(const std::string &name, EventNode* current) {
        if (!current) return nullptr;
        if (current->event.getName() == name) return current;
        for (auto child : current->subEvents) {
            EventNode* found = findEventNode(name, child);
            if (found) return found;
        }
        return nullptr;
    }

public:
    void createEvent(const std::string &name, int capacity) {
        roots.push_back(new EventNode(Event(name, capacity)));
        std::cout << "Main event '" << name << "' created.\n";
    }

    void createSubEvent(const std::string &parentName, const std::string &subName, int capacity) {
        for (auto root : roots) {
            EventNode* parent = findEventNode(parentName, root);
            if (parent) {
                parent->subEvents.push_back(new EventNode(Event(subName, capacity)));
                std::cout << "Sub-event '" << subName << "' added under '" << parentName << "'.\n";
                return;
            }
        }
        std::cout << "Parent event '" << parentName << "' not found.\n";
    }

    void registerParticipant(const std::string &eventName, const Participant &p);
    void cancelRegistration(const std::string &eventName, const std::string &name);
    void showParticipants(const std::string &eventName);
    void showWaitingList(const std::string &eventName);
    void showHierarchy();
};

#endif
