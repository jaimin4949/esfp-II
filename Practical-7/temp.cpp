#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int employeeID;
    string address;
    string title;
    double salary;
    string department;
public:
    // Default 
    Employee() {
        name = "Unknown";
        employeeID = 0;
        address = "Unknown";
        title = "Unknown";
        salary = 0.0;
        department = "Unknown";
    }

    // Parameterized 
    Employee(string n, int id, string addr, string t, double sal, string dept) {
        name = n;
        employeeID = id;
        address = addr;
        title = t;
        salary = sal;
        department = dept;
    }

 
    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Employee ID: " << employeeID << endl;
        cout << "Address: " << address << endl;
        cout << "Title: " << title << endl;
        cout << "Salary: $" << salary << endl;
        cout << "Department: " << department << endl;
    }


    void giveRaise(double amount) {
        salary += amount;
        cout << name << "'s salary increased to: $" << salary << endl;
    }

    void updateAddress(string newAddress) {
        address = newAddress;
        cout << name << "'s address updated to: " << address << endl;
    }

    void inputData() {
        cout << "Enter name: ";
        getline(cin >> ws, name);
        cout << "Enter employee ID: ";
        cin >> employeeID;
        cout << "Enter address: ";
        getline(cin >> ws, address);
        cout << "Enter title: ";
        getline(cin >> ws, title);
        cout << "Enter salary: $";
        cin >> salary;
        cout << "Enter department: ";
        getline(cin >> ws, department);
    }

    // Destructor
    ~Employee() {
        cout << "Destructor called for employee: " << name << endl;
    }
};

int main() {
    Employee emp1, emp2, emp3;

    cout << "Enter data for employee 1:" << endl;
    emp1.inputData();

    cout << "\nEnter data for employee 2:" << endl;
    emp2.inputData();

    cout << "\nEnter data for employee 3:" << endl;
    emp3.inputData();

    cout << "\nEmployee details:" << endl;
    emp1.displayInfo();
    emp2.displayInfo();
    emp3.displayInfo();

    return 0;
}
