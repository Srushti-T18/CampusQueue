# CampusQueue
A terminal-based Event Registration System built entirely in **C++**, using data structures like **Queue**, **Linked List**, and **Tree** for Data Structures IA 2.

## FEATURES
- **Event Management** – Add, delete, and traverse events (Tree-based)
- **Participant List** – Store, add, and remove participants (Linked List)
- **Waiting List** – Handle overflow registrations (Queue)
- **Reports** – Generate summaries of events and registrations
- **Ticket Confirmation** – Every successful registration generates a unique ticket number

## DATA STRUCTURES USED
| Feature | Data Structure | Purpose |
|----------|----------------|----------|
| Event Hierarchy | Tree | To categorize main events |
| Participant List | Linked List | Dynamic storage of participants |
| Waiting List | Queue | Manage registration overflow (FIFO) |

## HOW TO COMPILE AND RUN IN TERMINAL
### Step 1: Compile 
g++ src/*.cpp -I include -std=c++17 -o CampusQueue.exe
### Step 2: Run
./CampusQueue.exe


