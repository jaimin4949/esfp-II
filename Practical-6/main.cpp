

// #include <iostream>
// #include <string>
// using namespace std;

// class Car {
// public:
//     char modelName[50];
//     char brand[50];
//     int manyear;
//     string color;
//     double price;

//     void Insert() {
//         cout << "Enter Car Model: ";
//         cin.ignore();
//         cin.getline(modelName, 50);

//         cout << "Enter Brand Name: ";
//         cin.getline(brand, 50);

//         cout << "Enter Manufacturing year: ";
//         cin >> manyear;

//         cout << "Enter Car Color: ";
//         cin.ignore();
//         getline(cin, color);

//         cout << "Enter Car Price: ";
//         cin >> price;
//     }

//     void display() {
//         cout << "Car Model: " << modelName << endl;
//         cout << "Car Brand: " << brand << endl;
//         cout << "Car Manufacture Year: " << manyear << endl;
//         cout << "Car Color: " << color << endl;
//         cout << "Car Price: " << price << endl;
//     }

//     void ascending(Car cars[], int numcars) {
//         for (int i = 0; i < numcars - 1; i++) {
//             for (int j = 0; j < numcars - 1 - i; j++) {
//                 if (cars[j].price > cars[j + 1].price) {
//                     Car temp = cars[j];
//                     cars[j] = cars[j + 1];
//                     cars[j + 1] = temp;
//                 }
//             }
//         }
//     }

//     void descending(Car cars[], int numcars) {
//         for (int i = 0; i < numcars - 1; i++) {
//             for (int j = 0; j < numcars - 1 - i; j++) {
//                 if (cars[j].price < cars[j + 1].price) {
//                     Car temp = cars[j];
//                     cars[j] = cars[j + 1];
//                     cars[j + 1] = temp;
//                 }
//             }
//         }
//     }
// };

// int main() {
//     int Choice;
//     int numcars = 0;
//     Car cars[100];
    
//     do {
//         cout << "\nPress 1 for Insert Car Details" << endl;
//         cout << "Press 2 for Display Car Details" << endl;
//         cout << "Press 3 for Finding Most Expensive Car" << endl;
//         cout << "Press 4 for Finding Most Cheaper Car" << endl;
//         cout << "Press 5 for Sorting car by price in ascending order" << endl;
//         cout << "Press 6 to Exit" << endl;
//         cout << "Enter Your Choice: ";
//         cin >> Choice;

//         switch (Choice) {
//             case 1: {
//                 cout << "Enter the Number of cars you want to Insert: ";
//                 cin >> numcars;
//                 for (int i = 0; i < numcars; ++i) {
//                     cout << "Enter Car Details for Car " << i + 1 << endl;
//                     cars[i].Insert();
//                 }
//                 break;
//             }
//             case 2: {
//                 for (int i = 0; i < numcars; ++i) {
//                     cout << "Details of Car " << i + 1 << ":" << endl;
//                     cars[i].display();
//                     cout << endl;
//                 }
//                 break;
//             }
//             case 3: {
//                 if (numcars > 0) {
//                     Car expensiveCar = cars[0];
//                     for (int i = 1; i < numcars; ++i) {
//                         if (cars[i].price > expensiveCar.price) {
//                             expensiveCar = cars[i];
//                         }
//                     }
//                     cout << "Most Expensive Car Details:" << endl;
//                     expensiveCar.display();
//                 } else {
//                     cout << "No cars available. Insert cars first." << endl;
//                 }
//                 break;
//             }
//             case 4: {
//                 if (numcars > 0) {
//                     Car cheapCar = cars[0];
//                     for (int i = 1; i < numcars; ++i) {
//                         if (cars[i].price < cheapCar.price) {
//                             cheapCar = cars[i];
//                         }
//                     }
//                     cout << "Most Cheapest Car Details:" << endl;
//                     cheapCar.display();
//                 } else {
//                     cout << "No cars available. Insert cars first." << endl;
//                 }
//                 break;
//             }
//             case 5: {
//                 int ch;
//                 cout << "Input 1 for ascending & 2 for descending: ";
//                 cin >> ch;
//                 switch (ch) {
//                     case 1: {
//                         if (numcars > 0) {
//                             cars[0].ascending(cars, numcars);
//                             cout << "Cars sorted in ascending order by price:" << endl;
//                             for (int i = 0; i < numcars; ++i) {
//                                 cout << "Details of Car " << i + 1 << ":" << endl;
//                                 cars[i].display();
//                                 cout << endl;
//                             }
//                         } else {
//                             cout << "No cars available. Insert cars first." << endl;
//                         }
//                         break;
//                     }
//                     case 2: {
//                         if (numcars > 0) {
//                             cars[0].descending(cars, numcars);
//                             cout << "Cars sorted in descending order by price:" << endl;
//                             for (int i = 0; i < numcars; ++i) {
//                                 cout << "Details of Car " << i + 1 << ":" << endl;
//                                 cars[i].display();
//                                 cout << endl;
//                             }
//                         } else {
//                             cout << "No cars available. Insert cars first." << endl;
//                         }
//                         break;
//                     }
//                 }
//                 break;
//             }
//             case 6:
//                 cout << "Exiting..." << endl;
//                 break;
//             default:
//                 cout << "Invalid Choice. Please try again." << endl;
//         }
//     } while (Choice != 6);

//     return 0;
// }
