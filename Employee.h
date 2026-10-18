
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

struct Employee {
    int id;
    std::string name;
    std::string department;
    std::string designation;
    double salary;

    // Default constructor
    Employee()
        : id(0), name(""), department(""),
          designation(""), salary(0.0) {}

    // Parameterized constructor
    Employee(int id,
             std::string name,
             std::string department,
             std::string designation,
             double salary)
        : id(id),
          name(name),
          department(department),
          designation(designation),
          salary(salary) {}
};

#endif
