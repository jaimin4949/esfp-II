#include <iostream>

namespace NumberOperations {
    int isPalindrome(int n) { 
        int originalNumber = n; 
        int reversedNumber = 0; 

        while (n > 0) { 
            int digit = n % 10; 
            reversedNumber = reversedNumber * 10 + digit; 
            n /= 10; 
        } 

        if (originalNumber == reversedNumber) { 
            return 1; 
        } else { 
            return 0; 
        } 
    }

    int isArmstrong(int n) { 
        int originalNumber = n; 
        int sum = 0; 

        while (n > 0) { 
            int digit = n % 10; 
            sum += (digit * digit * digit); 
            n /= 10; 
        } 

        if (originalNumber == sum) { 
            return 1; 
        } else { 
            return 0; 
        } 
    }
}

int main() {
    int num;
    std::cout << "Enter a number (up to 5 digits): ";
    std::cin >> num;

    if (num < 0 || num > 99999) {
        std::cout << "Invalid input! Please enter a number up to 5 digits." << std::endl;
        return 1;
    }

    if (NumberOperations::isPalindrome(num)) {
        std::cout << num << " is a palindrome." << std::endl;
    } else {
        std::cout << num << " is not a palindrome." << std::endl;
    }

    if (NumberOperations::isArmstrong(num)) {
        std::cout << num << " is an Armstrong number." << std::endl;
    } else {
        std::cout << num << " is not an Armstrong number." << std::endl;
    }

    return 0;
}
