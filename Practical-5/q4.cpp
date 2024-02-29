#include <iostream>
using namespace std;
namespace A
{
    int a, b, c;
    void sum()
    {
        cout << "Enter two number:";
        cin >> a >> b;
        c = a + b;
        cout << "Sum of two number:" << c;
    }
}
int main()
{
    A::sum(); //here
    return 0;
}