# Employee Management System

This is a simple C++ console program that allows you to manage employees using a linked list.  

## Features
- Add a new employee (ID, Name, Age, Salary)
- Delete an employee by ID
- Search for an employee by ID
- Display all employees

## How to Run
1. Clone the repository:
```bash
git clone https://github.com/Abdelmounaimko/EmployeeManagement.git
```
2. Open the project in your IDE or terminal.
3. Compile the code:
```bash
g++ EmployeeManagement.cpp -o EmployeeManagement
```
4. Run the program
```bash
./EmployeeManagement
```
Notes
 • The program uses dynamic memory allocation and a singly linked list.
 • The name input reads one word. To handle full names with spaces, modify cin to getline.

 ```cpp
cin.ignore();
cin.getline(name, 50);
 
