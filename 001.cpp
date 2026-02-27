#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int operationChoice;
    double numbers[10] = {0.0};
    
    cout << "Input 1: Square root operation" << endl;
    cout << "Input 2: Power operation" << endl;
    cout << "Input 3: Multiplication operation" << endl;
    cout << "Input 4: Division operation" << endl;
    cout << "Input 5: Addition operation" << endl;
    cout << "Input 6: Subtraction operation" << endl;
    cin >> operationChoice;
    cout << operationChoice << endl;
    
    double base, exponent, result;
    int count;
    
    switch(operationChoice) {
        case 1:
            cout << "Please enter the radicand: " << endl;
            cin >> base;
            cout << sqrt(base) << endl;
            break;
            
        case 2:
            cout << "Please enter the base and exponent: " << endl;
            cin >> base >> exponent;
            cout << pow(base, exponent) << endl;
            break;
            
        case 3:
            cout << "Please enter multipliers (enter 0 to end): " << endl;
            result = 1.0;
            for(count = 0; count < 10; count++) {
                cin >> numbers[count];
                if(numbers[count] == 0) break;
                result = result * numbers[count];
            }
            cout << result << endl;
            break;
            
        case 4:
            cout << "Please enter dividend and divisor: " << endl;
            cin >> base >> exponent;
            cout << base / exponent << endl;
            break;
            
        case 5:
            cout << "Please enter addends (enter 0 to end): " << endl;
            result = 0.0;
            for(count = 0; count < 10; count++) {
                cin >> numbers[count];
                if(numbers[count] == 0) break;
                result = result + numbers[count];
            }
            cout << result << endl;
            break;
            
        case 6:
            cout << "Please enter numbers to subtract (enter 0 to end): " << endl;
            result = 0.0;
            for(count = 0; count < 10; count++) {
                cin >> numbers[count];
                if(numbers[count] == 0) break;
                if(count == 0) {
                    result = numbers[count];
                } else {
                    result = result - numbers[count];
                }
            }
            cout << result << endl;
            break;
    }
    
    return 0;
}
