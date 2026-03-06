#include <iostream>
#include <cmath>
#include <cstdlib>
#include <conio.h>
#include <windows.h>

using namespace std;

double memory = 0.0;

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void Initial() {
    cout << "Please select the tool you want to use" << endl;
    cout << "1.Mathematical calculator" << endl;
    cout << "2.Conversion calculator" << endl;
    cout << "Your choice: "; 
}

void showMenu() {
    system("cls");
    cout << "+=== Mathematical calculator ===+" << endl;
    cout << "|=- 1. Square Root            -=|" << endl;
    cout << "|=- 2. Power                  -=|" << endl;
    cout << "|=- 3. Mixed Calculation      -=|" << endl;
    cout << "|=- 4. Absolute Value         -=|" << endl;
    cout << "|=- 5. Cube Root              -=|" << endl;
    cout << "|=- 6. Logarithm (Natural Log)-=|" << endl;
    cout << "|=- 7. Logarithm (Base 10)    -=|" << endl;
    cout << "|=- 8. Sine                   -=|" << endl;
    cout << "|=- 9. Cosine                 -=|" << endl;
    cout << "|=- 10. Tangent               -=|" << endl;
    cout << "|=- 0. Exit                   -=|" << endl;
    cout << "|=- Current Memory:" << memory << "          -=|" << endl;
    cout << "|=- Your choice: " << endl;
}

void waitKey() {
    cout << "\nPress any key to continue...";
    _getch();
}

void processResultMemory(double result) {
    cout << "\nMemory options for result:" << endl;
    cout << "M+ : Add to memory" << endl;
    cout << "M- : Subtract from memory" << endl;
    cout << "Any other key: Continue" << endl;
    cout << "Your choice: ";

    char cmd;
    cin >> cmd;
    if (cmd == 'M' || cmd == 'm') {
        cin >> cmd;
        if (cmd == '+') {
            memory += result;
            cout << "Added to memory. New Memory: " << memory << endl;
        } else if (cmd == '-') {
            memory -= result;
            cout << "Subtracted from memory. New Memory: " << memory << endl;
        }
    }
    waitKey();
}

void doSqrt() {
    system("cls");
    cout << "--- Square Root ---" << endl;
    double n;
    cout << "Enter number: ";
    cin >> n;

    double result;
    if (n < 0) {
        cout << "Error: Cannot calculate square root of a negative number." << endl;
        result = 0;
    } else {
        result = sqrt(n);
        cout << "sqrt(" << n << ") = " << result << endl;
    }
    processResultMemory(result);
}

void doPower() {
    system("cls");
    cout << "--- Power ---" << endl;
    double b, e;
    cout << "Enter base and exponent: ";
    cin >> b >> e;

    double result = pow(b, e);
    cout << b << " ^ " << e << " = " << result << endl;
    processResultMemory(result);
}

void doMixed() {
    system("cls");
    cout << "--- Mixed Calculation ---" << endl;
    cout << "Input like: 3 + 5 * 2 " << endl;
    cout << "Memory: M+  M-  MC  MR" << endl;
    cout << "Current Memory: " << memory << endl;
    cout << "-----------------------" << endl;

    double total;
    char op;
    cin >> total;

    while (cin >> op && op != '=') {
        if (op == 'M') {
            char cmd;
            cin >> cmd;
            if (cmd == '+')
                memory += total;
            else if (cmd == '-')
                memory -= total;
            else if (cmd == 'C')
                memory = 0.0;
            else if (cmd == 'R')
                cout << "Memory: " << memory << endl;
            continue;
        }

        double num;
        cin >> num;

        if (op == '+')
            total += num;
        else if (op == '-')
            total -= num;
        else if (op == '*')
            total *= num;
        else if (op == '/') {
            if (num == 0) {
                cout << "Error: Divide by zero" << endl;
                break;
            }
            total /= num;
        } else {
            cout << "Error: Bad operator" << endl;
            break;
        }
    }

    cout << "Final Result: " << total << endl;

    cout << "\nMemory options for result:" << endl;
    cout << "M+ : Add result to memory" << endl;
    cout << "M- : Subtract result from memory" << endl;
    cout << "MC : Clear memory" << endl;
    cout << "Any other key: Continue" << endl;
    cout << "Your choice: ";

    char cmd;
    cin >> cmd;
    if (cmd == 'M' || cmd == 'm') {
        cin >> cmd;
        if (cmd == '+') {
            memory += total;
            cout << "Added to memory. New Memory: " << memory << endl;
        } else if (cmd == '-') {
            memory -= total;
            cout << "Subtracted from memory. New Memory: " << memory << endl;
        } else if (cmd == 'C') {
            memory = 0.0;
            cout << "Memory cleared." << endl;
        }
    }

    waitKey();
}

 
void doAbs() {
    system("cls");
    cout << "--- Absolute Value ---" << endl;
    double n;
    cout << "Enter number: ";
    cin >> n;
    double result = fabs(n);
    cout << "|" << n << "| = " << result << endl;
    processResultMemory(result);
}

void doCbrt() {
    system("cls");
    cout << "--- Cube Root ---" << endl;
    double n;
    cout << "Enter number: ";
    cin >> n;
    double result = cbrt(n);
    cout << "cbrt(" << n << ") = " << result << endl;
    processResultMemory(result);
}

void doLog() {  
    system("cls");
    cout << "--- Natural Logarithm ---" << endl;
    double n;
    cout << "Enter number (> 0): ";
    cin >> n;
    double result;
    if (n <= 0) {
        cout << "Error: Logarithm is undefined for non-positive numbers." << endl;
        result = 0;
    } else {
        result = log(n);
        cout << "ln(" << n << ") = " << result << endl;
    }
    processResultMemory(result);
}

void doLog10() {
    system("cls");
    cout << "--- Logarithm (Base 10) ---" << endl;
    double n;
    cout << "Enter number (> 0): ";
    cin >> n;
    double result;
    if (n <= 0) {
        cout << "Error: Logarithm is undefined for non-positive numbers." << endl;
        result = 0;
    } else {
        result = log10(n);
        cout << "log10(" << n << ") = " << result << endl;
    }
    processResultMemory(result);
}

void doSin() {
    system("cls");
    cout << "--- Sine ---" << endl;
    double angle;
    const double PI = 3.14159265358979323846;
    cout << "Enter angle (in degrees): ";
    cin >> angle;
    double radians = angle * PI / 180.0;  
    double result = sin(radians);
    cout << "sin(" << angle << "¡ã) = " << result << endl;
    processResultMemory(result);
}

void doCos() {
    system("cls");
    cout << "--- Cosine ---" << endl;
    double angle;
    const double PI = 3.14159265358979323846;
    cout << "Enter angle (in degrees): ";
    cin >> angle;
    double radians = angle * PI / 180.0;  
    double result = cos(radians);
    cout << "cos(" << angle << "¡ã) = " << result << endl;
    processResultMemory(result);
}

void doTan() {
    system("cls");
    cout << "--- Tangent ---" << endl;
    double angle;
    const double PI = 3.14159265358979323846;
    cout << "Enter angle (in degrees): ";
    cin >> angle;
    double radians = angle * PI / 180.0; 
     
    if (fmod(fabs(angle + 90), 180.0) < 1e-9) {
        cout << "Error: Tangent is undefined for angle " << angle << "¡ã." << endl;
        processResultMemory(0);
        return;
    }
    double result = tan(radians);
    cout << "tan(" << angle << "¡ã) = " << result << endl;
    processResultMemory(result);
}

void doConversion() {
    int category;
    double value, result;
    char fromUnit[20], toUnit[20];  

    while (true) {
        system("cls");
        cout << "X== Conversion Calculator ========[" << endl;
        cout << "|=- 1. Length (e.g., m, cm, in)  -=|" << endl;
        cout << "|=- 2. Weight (e.g., kg, g, lb)  -=|" << endl;
        cout << "|=- 3. Temperature (C, F)        -=|" << endl;
        cout << "|=- 0. Back to Main Menu         -=|" << endl;
        cout << "|=- Your choice: ";

        cin >> category;
        if (category == 0) {
            return; 
        }

        system("cls");

        switch (category) {
            case 1: { 
                int lengthChoice;
                cout << "--- Length Conversion ---" << endl;
                cout << "1. Meter to Centimeter" << endl;
                cout << "2. Centimeter to Meter" << endl;
                cout << "3. Inch to Centimeter" << endl;
                cout << "4. Centimeter to Inch" << endl;
                cout << "Your choice: ";
                cin >> lengthChoice;
                cout << "Enter value: ";
                cin >> value;

                switch (lengthChoice) {
                    case 1:
                        result = value * 100.0;
                        strcpy(fromUnit, "m");
                        strcpy(toUnit, "cm");
                        break;
                    case 2:
                        result = value / 100.0;
                        strcpy(fromUnit, "cm");
                        strcpy(toUnit, "m");
                        break;
                    case 3:
                        result = value * 2.54;
                        strcpy(fromUnit, "in");
                        strcpy(toUnit, "cm");
                        break;
                    case 4:
                        result = value / 2.54;
                        strcpy(fromUnit, "cm");
                        strcpy(toUnit, "in");
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                        waitKey();
                        continue;
                }
                break;
            }
            case 2: { 
                int weightChoice;
                cout << "--- Weight Conversion ---" << endl;
                cout << "1. Kilogram to Gram" << endl;
                cout << "2. Gram to Kilogram" << endl;
                cout << "3. Kilogram to Pound" << endl;
                cout << "4. Pound to Kilogram" << endl;
                cout << "Your choice: ";
                cin >> weightChoice;
                cout << "Enter value: ";
                cin >> value;

                switch (weightChoice) {
                    case 1:
                        result = value * 1000.0;
                        strcpy(fromUnit, "kg");
                        strcpy(toUnit, "g");
                        break;
                    case 2:
                        result = value / 1000.0;
                        strcpy(fromUnit, "g");
                        strcpy(toUnit, "kg");
                        break;
                    case 3:
                        result = value * 2.20462;
                        strcpy(fromUnit, "kg");
                        strcpy(toUnit, "lb");
                        break;
                    case 4:
                        result = value / 2.20462;
                        strcpy(fromUnit, "lb");
                        strcpy(toUnit, "kg");
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                        waitKey();
                        continue;
                }
                break;
            }
            case 3: { 
                int tempChoice;
                cout << "--- Temperature Conversion ---" << endl;
                cout << "1. Celsius to Fahrenheit" << endl;
                cout << "2. Fahrenheit to Celsius" << endl;
                cout << "Your choice: ";
                cin >> tempChoice;
                cout << "Enter temperature: ";
                cin >> value;

                switch (tempChoice) {
                    case 1:
                        result = (value * 9.0 / 5.0) + 32.0;
                        strcpy(fromUnit, "C");
                        strcpy(toUnit, "F");
                        break;
                    case 2:
                        result = (value - 32.0) * 5.0 / 9.0;
                        strcpy(fromUnit, "F");
                        strcpy(toUnit, "C");
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                        waitKey();
                        continue;
                }
                break;
            }
            default:
                cout << "Invalid category!" << endl;
                waitKey();
                continue;
        }
        cout << "\nResult: " << value << " " << fromUnit << " = " << result << " " << toUnit << endl;
        processResultMemory(result); 
    }
}

int main() {
    int choice;
    setColor(11);
    cout << "I am extremely honored that you are using my calculator.";
	Sleep(3000);
    setColor(7);
    system("cls");
    while (true) {
        Initial();
        cin >> choice;
        if (choice == 1) {
            int mathChoice;
            do {
                showMenu();
                cin >> mathChoice;
                if (mathChoice == 0) {
                    break; 
                }
                switch (mathChoice) {
                    case 1: doSqrt(); break;
                    case 2: doPower(); break;
                    case 3: doMixed(); break;
                    case 4: doAbs(); break;
                    case 5: doCbrt(); break;
                    case 6: doLog(); break;
                    case 7: doLog10(); break;
                    case 8: doSin(); break;
                    case 9: doCos(); break;
                    case 10: doTan(); break;
                    default: cout << "Invalid choice" << endl; waitKey();
                }
            } while (true);
        } else if (choice == 2) {
            doConversion();
        } else {
            cout << "Invalid choice." << endl;
            Sleep(500);
            waitKey();
        }
    }
    return 0;
}


