/**
 * @file ticketQueueManagement.cpp
 * @author torras (you@domain.com)
 * @brief ticket queue management by priority
 * @version 0.1
 * @date 2024-04-15
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <ctime>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

struct Ticket {
  int tID;
  std::string tPriority;
  std::string tTimestamp;

  Ticket(int id, std::string priority, std::string timestamp)
      : tID(id), tPriority(priority), tTimestamp(timestamp) {}

  ~Ticket() = default;
};

class TicketQueue {
private:
  /* TODO: replace raw pointer by smart pointers*/
  std::unordered_map<std::string, std::queue<Ticket *>> tQ;
  std::unordered_map<int, bool> validIDs;
  int tID;

public:
  TicketQueue() {
    this->tID = 0;

    this->tQ["low"] = std::queue<Ticket *>();
    this->tQ["medium"] = std::queue<Ticket *>();
    this->tQ["high"] = std::queue<Ticket *>();
  }

  /* TODO: replace raw pointer by smart pointers and remove this trash code */
  ~TicketQueue() {
    while (!this->tQ["high"].empty()) {
      Ticket *t = nullptr;
      t = this->tQ["high"].front();
      delete t;
      this->tQ["high"].pop();
    }

    while (!this->tQ["medium"].empty()) {
      Ticket *t = nullptr;
      t = this->tQ["medium"].front();
      delete t;
      this->tQ["medium"].pop();
    }

    while (!this->tQ["low"].empty()) {
      Ticket *t = nullptr;
      t = this->tQ["low"].front();
      delete t;
      this->tQ["low"].pop();
    }
  }

  /* TODO: return a bool to indicate success/failure */
  void add(std::string newTicketPriority) {
    // validate priority requested:
    if (newTicketPriority != "low" && newTicketPriority != "medium" && newTicketPriority != "high") {
      std::cout << "-- !! invalid ticket priority, please select <low, medium or high> as values !! --\n";
      return;
    }

    // increment the ID count:
    ++this->tID;

    // mark current ID as valid:
    this->validIDs[this->tID] = true;

    // get a new timestamp:
    std::time_t now = std::time(nullptr);
    std::string timeNow = std::ctime(&now);

    // create a new Ticket object:
    Ticket *ticket = new Ticket(this->tID, newTicketPriority, timeNow);

    // add ticket to the correct queue:
    this->tQ[ticket->tPriority].push(ticket);

    // success message:
    std::cout << "--> A new ticket was created\n\t> ID: " << ticket->tID
              << "\n\t> priority: " << ticket->tPriority
              << "\n\t> timestamp: " << ticket->tTimestamp << "\n\n";
  }

  Ticket *retrieve() {
    // check if the ticket queue is not empty:
    if (this->tQ["high"].empty() && this->tQ["medium"].empty() && this->tQ["low"].empty()) {
      std::cout << "-- !! There are no tickets queued up !! --\n";
      return nullptr;
    }

    Ticket *t = nullptr;

    /* TODO:
      clean up by extracting the repeated code below to a separate function which receives a 'priority' as argument
    */

    // -- check queue by priority:
    // high priority queue:
    if (!this->tQ["high"].empty()) {
      t = this->tQ["high"].front();
      // remove invalid tickets:
      while (this->validIDs[t->tID] == false) {
        this->tQ["high"].pop();

        if (this->tQ["high"].empty())
          break;

        t = this->tQ["high"].front();
      }
      // return ticket if still valid:
      if (!this->tQ["high"].empty())
        return t;
    }

    // medium priority queue:
    if (!this->tQ["medium"].empty()) {
      t = this->tQ["medium"].front();
      // remove invalid tickets:
      while (this->validIDs[t->tID] == false) {
        this->tQ["medium"].pop();

        if (this->tQ["medium"].empty())
          break;

        t = this->tQ["medium"].front();
      }
      // return ticket if still valid:
      if (!this->tQ["medium"].empty())
        return t;
    }

    // low priority queue:
    t = this->tQ["low"].front();

    // remove invalid tickets:
    while (this->validIDs[t->tID] == false) {
      this->tQ["low"].pop();

      if (this->tQ["low"].empty())
        break;

      t = this->tQ["low"].front();
    }
    // return ticket if still valid:
    if (!this->tQ["low"].empty())
      return t;

    std::cout << "-- !! There are no tickets queued up !! --\n";

    return nullptr;
  }

  /* TODO: return a bool to indicate success/failure */
  void remove(int ID) {
    if (this->validIDs.find(ID) != this->validIDs.end() && this->validIDs[ID]) {
      // invalidate ticket with the argument ID:
      this->validIDs[ID] = false;

      std::cout << "--> A ticket with the ID <" << ID << "> is set to be removed\n";

      return;
    }

    std::cout << "-- !! There is no valid ticket with ID <" << ID << "> !! --\n";
  }
};

int main() {
  TicketQueue *tqueue = new TicketQueue();

  tqueue->add("super");

  tqueue->add("low");
  tqueue->add("high");
  tqueue->add("high");
  tqueue->add("medium");

  Ticket *ticket = tqueue->retrieve();
  if (ticket) {
    std::cout << "--> The following ticket was retrieved\n\t> ID: " << ticket->tID
              << "\n\t> priority: " << ticket->tPriority
              << "\n\t> timestamp: " << ticket->tTimestamp << "\n\n";
  }

  tqueue->remove(2);
  ticket = tqueue->retrieve();
  if (ticket) {
    std::cout << "--> The following ticket was retrieved\n\t> ID: " << ticket->tID
              << "\n\t> priority: " << ticket->tPriority
              << "\n\t> timestamp: " << ticket->tTimestamp << "\n\n";
  }

  tqueue->remove(3);
  ticket = tqueue->retrieve();
  if (ticket) {
    std::cout << "--> The following ticket was retrieved\n\t> ID: " << ticket->tID
              << "\n\t> priority: " << ticket->tPriority
              << "\n\t> timestamp: " << ticket->tTimestamp << "\n\n";
  }

  tqueue->remove(4);
  ticket = tqueue->retrieve();
  if (ticket) {
    std::cout << "--> The following ticket was retrieved\n\t> ID: " << ticket->tID
              << "\n\t> priority: " << ticket->tPriority
              << "\n\t> timestamp: " << ticket->tTimestamp << "\n\n";
  }

  tqueue->remove(1);
  ticket = tqueue->retrieve();
  if (ticket) {
    std::cout << "--> The following ticket was retrieved\n\t> ID: " << ticket->tID
              << "\n\t> priority: " << ticket->tPriority
              << "\n\t> timestamp: " << ticket->tTimestamp << "\n\n";
  }

  tqueue->add("low");
  ticket = tqueue->retrieve();
  if (ticket) {
    std::cout << "--> The following ticket was retrieved\n\t> ID: " << ticket->tID
              << "\n\t> priority: " << ticket->tPriority
              << "\n\t> timestamp: " << ticket->tTimestamp << "\n\n";
  }

  tqueue->add("medium");
  ticket = tqueue->retrieve();
  if (ticket) {
    std::cout << "--> The following ticket was retrieved\n\t> ID: " << ticket->tID
              << "\n\t> priority: " << ticket->tPriority
              << "\n\t> timestamp: " << ticket->tTimestamp << "\n\n";
  }

  tqueue->add("high");
  ticket = tqueue->retrieve();
  if (ticket) {
    std::cout << "--> The following ticket was retrieved\n\t> ID: " << ticket->tID
              << "\n\t> priority: " << ticket->tPriority
              << "\n\t> timestamp: " << ticket->tTimestamp << "\n\n";
  }

  delete tqueue;

  return 0;
}
