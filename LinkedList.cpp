#include "../include/LinkedList.h"
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

Node* LinkedList::insert(const Employee& employee) {
    Node* newNode = new Node(employee);

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    return newNode;
}

bool LinkedList::remove(int id) {
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->data.id == id) {
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }

            if (current == tail) {
                tail = previous;
            }

            delete current;
            return true;
        }

        previous = current;
        current = current->next;
    }

    return false;
}

void LinkedList::display() const {
    Node* current = head;

    while (current != nullptr) {
        std::cout << "ID: " << current->data.id
                  << ", Name: " << current->data.name
                  << ", Department: " << current->data.department
                  << ", Designation: " << current->data.designation
                  << ", Salary: " << current->data.salary
                  << '\n';

        current = current->next;
    }
}

Node* LinkedList::getHead() const {
    return head;
}
