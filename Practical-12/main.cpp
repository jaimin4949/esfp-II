#include <iostream>
using namespace std;
class A
{
private:
    int id, salary;
    string name, designation;

public:
    void getInfo()
    {
        cout << "Enter id , name, designation and salary:\n";
        cin >> id >> name >> designation >> salary;
    }
    void display()
    {
        cout << "\n ====Employee Information=====\n";
        cout << id << "\t" << name << "\t" << designation << "\t" << salary << endl;
    }

public:
};
class B
{
public:
    A obj;
    void disp()
    {
        obj.getInfo();
        obj.display();
    }
};
int main()
{
    B ob;
    ob.disp();
    A obj;
    return 0;
}