#include <iostream>

using namespace std;

void operation(int &num1, int &num2, string &factor, string &result) {
    if (factor == "+") {
        result = to_string(num1 + num2);
    } else if (factor == "-") {
        result = to_string(num1 - num2);
    } else if (factor == "*") {
        result = to_string(num1 * num2);
    } else if (factor == "/") {
        if (num2 != 0) {
            result = to_string(num1 / num2);
        } else {
            result = "Error: Division by zero";
        }
    } else {
        cout << "Wrong operation. Please enter a valid operator (+, -, *, /): ";
        cin >> factor;
        operation(num1, num2, factor, result);
    }
    
}

int main() {
    int num1, num2;
    string factor;
    string result;
    
    
    cout << "MathMate by staxhinho" << endl;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the operation (+, -, *, /): ";
    cin >> factor;
    cout << "Enter the second number: ";
    cin >> num2;
    operation(num1, num2, factor, result);

    cout << "The result is: " << result << endl;
    system("pause");
    return 0;
}