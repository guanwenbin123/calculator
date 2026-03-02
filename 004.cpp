#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int operationChoice;
double base, exponent, result;
int count;

void menu (){
	cout << "Input 1: Square root operation" << endl;
    cout << "Input 2: Power operation" << endl;
    cout << "Input 3: Mixed arithmetic operation (+, -, *, /)" << endl;
    cout << "Input 0: exit the calculator"<<endl;
}

void clearScreen(){
	system("cls");
}

int main() {
	while(1) {
		menu();
		cin >> operationChoice;
		if(operationChoice == 0)break;
	    switch(operationChoice) {
	        case 1: { // Square root
				clearScreen();	        
	            double num;
	            cout << "Please enter the number: " << endl;
	            cin >> num;
	            if (num < 0) {
	                cout << "Error: Negative number cannot be square rooted!" << endl;
	            } else {
	            	clearScreen();
	                cout << "Result: " << sqrt(num) << endl;
	            }
	            break;
	        }
	        case 2: { // Power
	        	clearScreen();
	            double base, exponent;
	            cout << "Please enter the base and exponent in order: " << endl;
	            cin >> base >> exponent;
	            clearScreen();
	            cout << "Result: " << pow(base, exponent) << endl;
	            break;
	        }
	        case 3: {
	        	clearScreen();
	            cout << "Please enter a mixed expression (e.g., 3 + 4 * 2 = ): " << endl;
	            cout << "Supported operators: +, -, *, /. End with '='." << endl;
	            cout << "Priority is not supported."<<endl;
	            double result, num;
	            char op;
	            cin >> result;  
	            while (cin >> op) {  
	                if (op == '=') {  
	                    break;
	                }
	                cin >> num;  
	                if (op == '+') {
	                    result = result + num;
	                } else if (op == '-') {
	                    result = result - num;
	                } else if (op == '*') {
	                    result = result * num;
	                } else if (op == '/') {
	                    if (num == 0.0) {
	                        cout << "Error: Divisor cannot be zero!" << endl;
	                        return 1;
	                    }
	                    result = result / num;
	                } else {
	                    cout << "Error: Unsupported operator '" << op << "'." << endl;
	                    return 1;
	                }
	            }
	            clearScreen();
	            cout << "Result: " << result << endl;
	            break;
	        }
	        default:
	            cout << "Invalid input" << endl;	            
	            break;
	    }
	    cout << "input any number to continue";
	    int i;
	    cin>>i;
	    if(i != 666)
			clearScreen();
	}
    return 0;
}
