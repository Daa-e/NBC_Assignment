#include <iostream>

using namespace std;




// + - * / 계산기
int main() {
    char op;
    double num1, num2;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;
    cout << "Enter second number: ";
    cin >> num2;

    if (op == '+') {
        cout << "Result: " << num1 + num2 << endl;
    }
    else if (op == '-') {
        cout << "Result: " << num1 - num2 << endl;
    }
    else if (op == '*') {
        cout << "Result: " << num1 * num2 << endl;
    }
    else if (op == '/') {
        if (num2 == 0) {
            cout << "Division by zero is not allowed." << endl;
        }
        else {
            cout << "Result: " << num1 / num2 << endl;
        }
    }
    else {
        cout << "Invalid operator." << endl;
    }

    return 0;
}






// 더하기만 하는 계산기
//int main(void)
//{
//	int firstNum = 0;
//	int secondNum = 0;
//	
//	cout << "첫 번째 수 입력 : ";
//	cin >> firstNum;
//
//	cout << "두 번째 수 입력 : ";
//	cin >> secondNum;
//	
//	cout << "더한 결과는 : " << firstNum + secondNum << endl;
//	
//	return 0;
//}