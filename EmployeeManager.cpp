
#include "../include/EmployeeManager.h"
#include <iostream>
using namespace std;

EmployeeManager::EmployeeManager() {
}

void EmployeeManager::addEmployee(Employee employee) {
    employees.insert(employee);
    employeeMap[employee.id] = employees.getHead();
    cout << "Employee added successfully!\n";
}

Node* EmployeeManager::searchEmployee(int id) {
    auto it = employeeMap.find(id);

    if (it != employeeMap.end()) {
        Node* current = employees.getHead();

        while (current != nullptr) {
            if (current->data.id == id) {
                return current;
            }
            current = current->next;
        }
    }

    return nullptr;
}

void EmployeeManager::displayEmployees() {
    employees.display();
}

void EmployeeManager::updateEmployee(int id) {
    Node* employee = searchEmployee(id);

    if (employee == nullptr) {
        cout << "Employee not found!\n";
        return;
    }

    cout << "Enter new name: ";
    cin >> employee->data.name;

    cout << "Enter new department: ";
    cin >> employee->data.department;

    cout << "Enter new designation: ";
    cin >> employee->data.designation;

    cout << "Enter new salary: ";
    cin >> employee->data.salary;

    cout << "Employee updated successfully!\n";
}

void EmployeeManager::deleteEmployee(int id) {
    Node* current = employees.getHead();
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->data.id == id) {
            if (previous == nullptr) {
                cout << "Deleting the head node requires "
                     << "a LinkedList delete method.\n";
                return;
            }

            previous->next = current->next;
            delete current;
            employeeMap.erase(id);

            cout << "Employee deleted successfully!\n";
            return;
        }

        previous = current;
        current = current->next;
    }

    cout << "Employee not found!\n";
}
