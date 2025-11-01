#include "EventTree.h"

EventNode* findNodeRecursive(const std::string &name, EventNode* node) {
    if (!node) return nullptr;
    if (node->event.getName() == name) return node;
    for (auto child : node->subEvents) {
        EventNode* found = findNodeRecursive(name, child);
        if (found) return found;
    }
    return nullptr;
}

void EventTree::registerParticipant(const std::string &eventName, const Participant &p) {
    for (auto root : roots) {
        EventNode* node = findNodeRecursive(eventName, root);
        if (node) {
            node->event.registerParticipant(p);
            return;
        }
    }
    std::cout << "Event not found.\n";
}

void EventTree::cancelRegistration(const std::string &eventName, const std::string &name) {
    for (auto root : roots) {
        EventNode* node = findNodeRecursive(eventName, root);
        if (node) {
            node->event.cancelRegistration(name);
            return;
        }
    }
    std::cout << "Event not found.\n";
}

void EventTree::showParticipants(const std::string &eventName) {
    for (auto root : roots) {
        EventNode* node = findNodeRecursive(eventName, root);
        if (node) {
            node->event.showParticipants();
            return;
        }
    }
    std::cout << "Event not found.\n";
}

void EventTree::showWaitingList(const std::string &eventName) {
    for (auto root : roots) {
        EventNode* node = findNodeRecursive(eventName, root);
        if (node) {
            node->event.showWaitingList();
            return;
        }
    }
    std::cout << "Event not found.\n";
}

void displayHierarchy(EventNode* node, int level) {
    for (int i = 0; i < level; ++i) std::cout << "  ";
    std::cout << "- " << node->event.getName() << "\n";
    for (auto child : node->subEvents)
        displayHierarchy(child, level + 1);
}

void EventTree::showHierarchy() {
    for (auto root : roots)
        displayHierarchy(root, 0);
}
