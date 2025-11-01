#include <iostream>
#include <string>
#include "EventTree.h"
#include "Participant.h"
using namespace std;

int main() {
    EventTree eventTree;
    int choice;

    while (true) {
        cout << "\n===== CampusQueue Event Registration System =====\n";
        cout << "1. Create Event\n";
        cout << "2. Create Sub-Event\n";
        cout << "3. Register Participant\n";
        cout << "4. Cancel Registration\n";
        cout << "5. Show Participants\n";
        cout << "6. Show Waiting List\n";
        cout << "7. Show Event Hierarchy\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string eventName;
            int capacity;
            cout << "Enter main event name: ";
            getline(cin, eventName);
            cout << "Enter capacity: ";
            cin >> capacity;
            cin.ignore();
            eventTree.createEvent(eventName, capacity);
        } 
        else if (choice == 2) {
            string parentName, subEventName;
            int capacity;
            cout << "Enter main event name to attach sub-event: ";
            getline(cin, parentName);
            cout << "Enter sub-event name: ";
            getline(cin, subEventName);
            cout << "Enter capacity for sub-event: ";
            cin >> capacity;
            cin.ignore();
            eventTree.createSubEvent(parentName, subEventName, capacity);
        } 
        else if (choice == 3) {
            string eventName, name, dept;
            cout << "Enter event or sub-event name: ";
            getline(cin, eventName);
            cout << "Enter participant name: ";
            getline(cin, name);
            cout << "Enter department: ";
            getline(cin, dept);
            eventTree.registerParticipant(eventName, Participant(name, dept));
        } 
        else if (choice == 4) {
            string eventName, name;
            cout << "Enter event or sub-event name: ";
            getline(cin, eventName);
            cout << "Enter participant name to cancel: ";
            getline(cin, name);
            eventTree.cancelRegistration(eventName, name);
        } 
        else if (choice == 5) {
            string eventName;
            cout << "Enter event or sub-event name: ";
            getline(cin, eventName);
            eventTree.showParticipants(eventName);
        } 
        else if (choice == 6) {
            string eventName;
            cout << "Enter event or sub-event name: ";
            getline(cin, eventName);
            eventTree.showWaitingList(eventName);
        } 
        else if (choice == 7) {
            cout << "\nEvent Hierarchy:\n";
            eventTree.showHierarchy();
        } 
        else if (choice == 8) {
            cout << "Exiting program.\n";
            break;
        } 
        else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
