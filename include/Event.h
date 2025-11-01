#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "Participant.h"

class Event {
    std::string name;
    int capacity;
    std::vector<Participant> participants;
    std::queue<Participant> waitingList;

public:
    Event(std::string n = "", int c = 0) : name(n), capacity(c) {}

    std::string getName() const { return name; }

    void registerParticipant(const Participant &p) {
        if ((int)participants.size() < capacity) {
            participants.push_back(p);
            std::cout << p.getName() << " successfully registered for " << name << ".\n";
        } else {
            waitingList.push(p);
            std::cout << name << " is full. " << p.getName() << " added to waiting list.\n";
        }
    }

    void cancelRegistration(const std::string &participantName) {
        for (auto it = participants.begin(); it != participants.end(); ++it) {
            if (it->getName() == participantName) {
                std::cout << participantName << " removed from " << name << ".\n";
                participants.erase(it);
                if (!waitingList.empty()) {
                    Participant next = waitingList.front();
                    waitingList.pop();
                    participants.push_back(next);
                    std::cout << next.getName() << " moved from waiting list to participants.\n";
                }
                return;
            }
        }
        std::cout << "Participant not found in " << name << ".\n";
    }

    void showParticipants() const {
        std::cout << "\nParticipants for " << name << ":\n";
        if (participants.empty()) {
            std::cout << "No participants yet.\n";
            return;
        }
        for (const auto &p : participants)
            std::cout << p.getName() << " (" << p.getDept()
                      << ") - Ticket #" << p.getTicketNo() << "\n";
    }

    void showWaitingList() const {
        std::queue<Participant> copy = waitingList;
        std::cout << "\nWaiting List for " << name << ":\n";
        if (copy.empty()) {
            std::cout << "No one in waiting list.\n";
            return;
        }
        while (!copy.empty()) {
            Participant p = copy.front();
            copy.pop();
            std::cout << p.getName() << " (" << p.getDept()
                      << ") - Ticket #" << p.getTicketNo() << "\n";
        }
    }
};

#endif
