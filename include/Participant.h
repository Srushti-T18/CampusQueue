#ifndef PARTICIPANT_H
#define PARTICIPANT_H

#include <string>
#include <cstdlib>

class Participant {
    std::string name;
    std::string dept;
    int ticketNo;

public:
    Participant(std::string n = "", std::string d = "")
        : name(n), dept(d) {
        ticketNo = rand() % 9000 + 1000; 
    }

    std::string getName() const { return name; }
    std::string getDept() const { return dept; }
    int getTicketNo() const { return ticketNo; }
};

#endif
