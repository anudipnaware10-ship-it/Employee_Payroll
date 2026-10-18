
#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include "LinkedList.h"
#include <unordered_map>

class EmployeeManager {
private:
    LinkedList employees;
    std::unordered_map<int, Node*> employeeMap;

public:
    EmployeeManager();

    void addEmployee(Employee employee);
    Node* searchEmployee(int id);
    void displayEmployees();
    void updateEmployee(int id);
    void deleteEmployee(int id);

    // File handling functions
    void loadFromFile();
    void saveToFile();
};

#endif
