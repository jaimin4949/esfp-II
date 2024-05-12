#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
#include <string>

bool checkLogin()
{
    std::string loginId, password;
    int attempts = 0;
    do
    {
        std::cout << "Enter Login ID: ";
        std::cin >> loginId;
        std::cout << "Enter Password: ";
        std::cin >> password;
        if (loginId == "admin" && password == "admin")
        {
            std::cout << "Login successful!" << std::endl;
            return true;
        }
        else
        {
            attempts++;
            std::cout << "Incorrect login credentials. Please try again." << std::endl;
        }
    } while (attempts < 3);
    std::cout << "Maximum login attempts reached. Exiting program." << std::endl;
    return false;
}

#endif
