#include<iostream>
using namespace std;

namespace root {
    

    int calc() {
        int dis;
        cout<<"Enter Distance: ";
        cin>>dis;

        if (dis>0 && dis<=20) {
            cout<<"Fare is 1 RS";
        }
        else if (dis>=21 && dis<=40) {
            cout<<"Fare is 2 RS";
        }
        else if (dis>=41 && dis<=60) {
            cout<<"Fare is 3 RS";
        }
        else if (dis>=61 && dis<=80) {
            cout<<"Fare is 4 RS";
        }
        else if (dis>=81 && dis<=100) {
            cout<<"Fare is 5 RS";
        }
        else if (dis>=101) {
            cout<<"Fare is 6 RS";
        }
        else {
            cout<<"Invalid Input";
        }    

        return 0;
    }
}

int main() {
    root::calc();
    return 0;
}
