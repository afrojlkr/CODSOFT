#include <iostream>
int main() {
    char operation;
    double num1, num2, result;
    // Get user input
    std::cout << "Enter first number: ";
    std::cin >> num1;
    std::cout << "Enter second number: ";
    std::cin >> num2;
    // Get the operation from the user
    std::cout << "Choose an operation (+, -, *, /): ";
    std::cin >> operation;
    // Perform the selected operation
    switch (operation) {
    case '+':
        result = num1 + num2;
    break;
    case '-':
        result = num1 - num2;
    break;
    case '*':
        result = num1 * num2;
    break;
    case '/':
    // Check for division by zero
    if (num2 != 0) {
        result = num1 / num2;
    } else {
        std::cout << "Error: Division by zero is not allowed.\n";

        return 1; // Exit the program with an error code
    }
    break;
    default:
        std::cout << "Error: Invalid operation.\n";
        return 1; // Exit the program with an error code
    }
    // Display the result
    std::cout << "Result: " << result << std::endl;
    return 0;
}