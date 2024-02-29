#include <iostream>
#include <string>
using namespace std;

class cars {
public:
    struct info {
        string model;
        string brand;
        int year;
        string color;
        int price;
    } info_data[10], asc[10], des[10], temp;

    int numCars;

    void input() {
        cout << "Enter the number of cars: ";
        cin >> numCars;
        cin.ignore();

        cout << "Enter the Information about the available cars" << endl;
        for (int i = 0; i < numCars; i++) {
            cout << "Enter the Information about Car number " << (i + 1) << endl;
            cout << "Enter Car's Model: ";
            getline(cin, info_data[i].model);

            cout << "Enter Car's Brand: ";
            getline(cin, info_data[i].brand);

            cout << "Enter Car's Year: ";
            cin >> info_data[i].year;
            cin.ignore();

            cout << "Enter Car's Colour: ";
            getline(cin, info_data[i].color);

            cout << "Enter Car's Price: ";
            cin >> info_data[i].price;
            cin.ignore();

            asc[i] = info_data[i];
            des[i] = info_data[i];
        }
    }

    void display(struct info detls[]) {
        cout << "Model" << "\t" << "Brand" << "\t" << "Year" << "\t" << "Color" << "\t" << "Price" << endl;
        for (int j = 0; j < numCars; j++) {
            cout << detls[j].model << "\t" << detls[j].brand << "\t" << detls[j].year << "\t" << detls[j].color << "\t" << detls[j].price << endl << endl;
        }
    }

    void ascending() {
        for (int i = 0; i < numCars; i++) {
            for (int j = 0; j < numCars - 1; j++) {
                if (asc[j].price > asc[j + 1].price) {
                    temp = asc[j + 1];
                    asc[j + 1] = asc[j];
                    asc[j] = temp;
                }
            }
        }
    }

    void descending() {
        for (int i = 0; i < numCars; i++) {
            for (int j = 0; j < numCars - 1; j++) {
                if (des[j].price < des[j + 1].price) {
                    temp = des[j + 1];
                    des[j + 1] = des[j];
                    des[j] = temp;
                }
            }
        }
    }
};

int main() {
    int choice, exit = 1;
    cars dealer;
    dealer.input();
    dealer.ascending();
    dealer.descending();
    cout << endl << endl;
    cout << "Information about the available cars: " << endl;
    dealer.display(dealer.info_data);

    while (exit != 0) {
        cout << endl << "--------------Options-----------";
        cout << endl << "Press <1> to Display car list" << endl;
        cout << "Press <2> to Display most expensive car" << endl;
        cout << "Press <3> to Display most cheaper car" << endl;
        cout << "Press <4> to Display car list according to price (Ascending)" << endl;
        cout << "Press <5> to Display car list according to price (descending)" << endl;
        cout << "Press <0> to exit" << endl;

        cout << endl << "Enter your Choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                cout << "Information about the available cars: " << endl;
                dealer.display(dealer.info_data);
                break;

            case 2:
                cout << "most expensive car is: " << endl;
                cout << "Model" << "\t" << "Brand" << "\t" << "Year" << "\t" << "Color" << "\t" << "Price" << endl;
                cout << dealer.des[0].model << "\t" << dealer.des[0].brand << "\t" << dealer.des[0].year << "\t" << dealer.des[0].color << "\t" << dealer.des[0].price << endl;
                break;

            case 3:
                cout << "cheapest car is: " << endl;
                cout << "Model" << "\t" << "Brand" << "\t" << "Year" << "\t" << "Color" << "\t" << "Price" << endl;
                cout << dealer.asc[0].model << "\t" << dealer.asc[0].brand << "\t" << dealer.asc[0].year << "\t" << dealer.asc[0].color << "\t" << dealer.asc[0].price << endl;
                break;

            case 4:
                cout << "cars sorted by price (Ascending) : " << endl; 
                dealer.display(dealer.asc);
                break;

            case 5:
                cout << "cars sorted by price (descending) : " << endl; 
                dealer.display(dealer.des);
                break;

            case 0:
                exit = 0;
                cout << "Exit.......";
                break;

            default:
                cout << "Invalid choice, enter a valid option.";
                break;
        }
    }
    return 0;
}
