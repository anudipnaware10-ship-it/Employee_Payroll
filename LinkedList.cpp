
#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}

LinkedList::~LinkedList() {
    Node* current = head;

    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
}

void LinkedList::insert(const Employee& employee) {
    Node* newNode = new Node(employee);

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void LinkedList::display() const {
    Node* current = head;

    while (current != nullptr) {
        std::cout << "ID: " << current->data.id
                  << ", Name: " << current->data.name
                  << ", Department: " << current->data.department
                  << ", Salary: " << current->data.salary
                  << '\n';

        current = current->next;
    }
}

Node* LinkedList::getHead() const {
    return head;
}
