#include <iostream>
#include <cmath>

namespace NumberOperations {
    // Function to check if a number is palindrome
    bool isPalindrome(int num) {
        int originalNum = num;
        int reversedNum = 0;

        while (num > 0) {
            int remainder = num % 10;
            reversedNum = reversedNum * 10 + remainder;
            num /= 10;
        }

        return originalNum == reversedNum;
    }

    // Function to check if a number is Armstrong number
    bool isArmstrong(int num) {
        int originalNum = num;
        int sum = 0;
        int numDigits = 0;

        // Count number of digits
        while (num > 0) {
            num /= 10;
            numDigits++;
        }

        // Reset num to original value
        num = originalNum;

        // Calculate sum of digits raised to the power of numDigits
        while (num > 0) {
            int digit = num % 10;
            sum += pow(digit, numDigits);
            num /= 10;
        }

        return originalNum == sum;
    }
}

int main() {
    using namespace std;
    using namespace NumberOperations;

    int num;
    cout << "Enter a number (up to 5 digits): ";
    cin >> num;

    if (isPalindrome(num)) {
        cout << num << " is a palindrome." << endl;
    } else {
        cout << num << " is not a palindrome." << endl;
    }

    if (isArmstrong(num)) {
        cout << num << " is an Armstrong number." << endl;
    } else {
        cout << num << " is not an Armstrong number." << endl;
    }

    return 0;
}
