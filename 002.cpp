#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int operationChoice;
    double base, exponent, result;
    int count;

    cout << "Input 1: Square root operation" << endl;
    cout << "Input 2: Power operation" << endl;
    cout << "Input 3: Multiplication operation" << endl;
    cout << "Input 4: Division operation" << endl;
    cout << "Input 5: Addition operation" << endl;
    cout << "Input 6: Subtraction operation" << endl;
    cin >> operationChoice;
    cout << operationChoice << endl;

    switch(operationChoice) {
    	case 1: {
        double num;
        cout << "Please enter the base number" << endl;
        cin >> num;
        if (num < 0) {
            cout << "Negatve number cannt be square rooted!" << endl;
        } else {
            cout << "square root:" << sqrt(num) << endl;
        }
        break;
    	}
	    case 2: {
	        double base, exponent;
	        cout << "Please enter the base and exponent in order" << endl;
	        cin >> base >> exponent;
	        cout << "power: " << pow(base, exponent) << endl;
	        break;
	    }
        case 3: {
            cout << "Please enter multipliers (enter 0 to end): " << endl;
            result = 1.0;
            count = 0;
            while (true) {
                double num;
                cin >> num;
                if (num == 0) break;
                result = result * num;
                count++;
            }
            cout << result << endl;
            break;
        }
        case 4: {
            cout << "Please enter dividend and divisor: " << endl;
            cin >> base >> exponent;
            if (exponent == 0.0) {
                cout << "Error: Divisor cannot be zero!" << endl;
                return 1;
            }
            result = base / exponent;
            cout << result << endl;
            break;
        }
        case 5: {
            cout << "Please enter addends (enter 0 to end): " << endl;
            result = 0.0;
            count = 0;
            while (true) {
                double num;
                cin >> num;
                if (num == 0) break;
                result = result + num;
                count++;
            }
            cout << result << endl;
            break;
        }
        case 6: {
            cout << "Please enter numbers to subtract (enter 0 to end): " << endl;
            result = 0.0;
            count = 0;
            while (true) {
                double num;
                cin >> num;
                if (num == 0) break;
                if (count == 0) {
                    result = num;
                } else {
                    result = result - num;
                }
                count++;
            }
            cout << result << endl;
            break;
        }
        default:
            cout << "Invalid input" << endl;
            break;
    }
    return 0;
}

