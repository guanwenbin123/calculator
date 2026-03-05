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

void showMenu() {
    system("cls");
    cout << "©°©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©´" << endl;
    cout << "©¦ ENHANCED CALCULATOR                                                  v1.0©¦" << endl;
    cout << "©À©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©È" << endl;
    cout << "©¦  FILE  EDIT  VIEW  MODE  HELP                                            ©¦" << endl;
    cout << "©À©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©È" << endl;
    cout << "©¦ ©°©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©´ ©¦" << endl;
    cout << "©¦ ©¦ ?  [1] Basic Arithmetic     [2] Scientific                         ©¦ ©¦" << endl;
    cout << "©¦ ©¦    ©°©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©´©¦ ©¦" << endl;
    cout << "©¦ ©¦    ©¦ 3. Mixed (+-*/)                  		  	   	    		©¦©¦ ©¦" << endl;
    cout << "©¦ ©¦    ©¦ 4. Absolute Value (|x|)        			                ©¦©¦ ©¦" << endl;
    cout << "©¦ ©¦    ©¸©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¼©¦ ©¦" << endl;
    cout << "©¦ ©¦    ©°©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©´©¦ ©¦" << endl;
    cout << "©¦ ©¦    ©¦ 1. ¡Ì  Square Root   5. 3¡Ì Cube Root 			    	    ©¦©¦ ©¦" << endl;
    cout << "©¦ ©¦    ©¦ 2. x^y Power        6. ln  Nat.Log 			    	    ©¦©¦ ©¦" << endl;
    cout << "©¦ ©¦    ©¦                     7. log Base 10                         ©¦©¦ ©¦" << endl;
    cout << "©¦ ©¦    ©¦ 8. sin             10. tan                                 ©¦©¦ ©¦" << endl;
    cout << "©¦ ©¦    ©¦ 9. cos                                                     ©¦©¦ ©¦" << endl;
    cout << "©¦ ©¦    ©¸©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¼©¦ ©¦" << endl;
    cout << "©¦ ©¦  [0] Exit Program  [M] Memory: " << memory;
    if(memory >= 0) cout << "                                                         ©¦ ©¦" << endl;
    else cout << " 										          				      ©¦ ©¦" << endl;
    cout << "©¦ ©¸©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¼ ©¦" << endl;
    cout << "©¸©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¼" << endl;
    cout << "> Select (1-10, 0 to exit, M for memory menu): ";
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
    cout << "©°©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©´" << endl;
    cout << "©¦ --- Mixed Calculation Mode ---                                           ©¦" << endl;
    cout << "©À©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©È" << endl;
    cout << "©¦ Enter like: 3 + 5 * 2 =                                                  ©¦" << endl;
    cout << "©¦ Memory: M+  M-  MC  MR                                                   ©¦" << endl;
    cout << "©¦ Current Memory: " << memory;
    int memSpaces = 35;
    if(memory >= 0) memSpaces -= 1;
    for(int i=0; i<memSpaces; i++) cout << " ";
    cout << "©¦" << endl;
    cout << "©À©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©È" << endl;

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
    cout << "sin(" << angle << ") = " << result << endl;
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
    cout << "cos(" << angle << ") = " << result << endl;
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
        cout << "Error: Tangent is undefined for angle " << angle << "." << endl;
        processResultMemory(0);
        return;
    }
    double result = tan(radians);
    cout << "tan(" << angle << ") = " << result << endl;
    processResultMemory(result);
}

int main() {
    int choice;
    while (true) {
        showMenu();
        cin >> choice;
        if (choice == 0) {
            cout << "Goodbye!" << endl;
            break;
        }

        switch (choice) {
        case 1:
            doSqrt();
            break;
        case 2:
            doPower();
            break;
        case 3:
            doMixed();
            break;
        case 4:
            doAbs();
            break;
        case 5:
            doCbrt();
            break;
        case 6:
            doLog();
            break;
        case 7:
            doLog10();
            break;
        case 8:
            doSin();
            break;
        case 9:
            doCos();
            break;
        case 10:
            doTan();
            break;
        default:
            cout << "Invalid choice" << endl;
            waitKey();
        }
    }
    return 0;
}

