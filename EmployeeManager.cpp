
#include "EmployeeManager.h"
#include "FileHandler.h"

#include <iostream>
#include <vector>

using namespace std;

EmployeeManager::EmployeeManager() {}

// Add employee
void EmployeeManager::addEmployee(Employee employee) {
    if (employeeMap.find(employee.id) != employeeMap.end()) {
        cout << "Employee ID already exists!\n";
        return;
    }

    Node* newNode = employees.insert(employee);
    employeeMap[employee.id] = newNode;

    cout << "Employee added successfully!\n";
    saveToFile();
}

// Search employee
Node* EmployeeManager::searchEmployee(int id) {
    auto it = employeeMap.find(id);

    if (it != employeeMap.end()) {
        return it->second;
    }

    return nullptr;
}

// Display employees
void EmployeeManager::displayEmployees() {
    employees.display();
}

// Update employee
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
    saveToFile();
}

// Delete employee
void EmployeeManager::deleteEmployee(int id) {
    if (employeeMap.find(id) == employeeMap.end()) {
        cout << "Employee not found!\n";
        return;
    }

    if (employees.remove(id)) {
        employeeMap.erase(id);

        cout << "Employee deleted successfully!\n";
        saveToFile();
    }
}

// Load employee records from file
void EmployeeManager::loadFromFile() {
    vector<Employee> savedEmployees = FileHandler::loadEmployees();

    for (const Employee& emp : savedEmployees) {
        if (employeeMap.find(emp.id) == employeeMap.end()) {
            Node* newNode = employees.insert(emp);
            employeeMap[emp.id] = newNode;
        }
    }

    cout << "Employee records loaded: "
         << employeeMap.size() << "\n";
}

// Save employee records to file
void EmployeeManager::saveToFile() {
    vector<Employee> allEmployees;

    Node* current = employees.getHead();

    while (current != nullptr) {
        allEmployees.push_back(current->data);
        current = current->next;
    }

    FileHandler::saveEmployees(allEmployees);
}
