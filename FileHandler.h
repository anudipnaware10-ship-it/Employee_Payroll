
#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "Employee.h"
#include <vector>

class FileHandler {
public:
    // Save all employee records to a text file
    static void saveEmployees(
        const std::vector<Employee>& employees
    );

    // Load employee records from a text file
    static std::vector<Employee> loadEmployees();
};

#endif
