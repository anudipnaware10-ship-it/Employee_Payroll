
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Employee.h"

struct Node {
    Employee data;
    Node* next;

    Node(const Employee& employee)
        : data(employee), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList();
    ~LinkedList();

    // Insert an employee and return the new node
    Node* insert(const Employee& employee);

    // Remove an employee using their ID
    bool remove(int id);

    // Display all employees
    void display() const;

    // Return the first node
    Node* getHead() const;
};

#endif
