#include <iostream>
#include <cmath>
#include <cstdlib>
#include <conio.h>
using namespace std;

double memory = 0.0;

void showMenu() {
    system("cls");
    cout << "=== Simple Calculator ===" << endl;
    cout << "1. Square Root" << endl;
    cout << "2. Power" << endl;
    cout << "3. Mixed Calculation" << endl;
    cout << "0. Exit" << endl;
    cout << "Current Memory: " << memory << endl;
    cout << "Your choice: ";
}

void waitKey() {
    cout << "\nPress any key to continue...";
    _getch();
}

void doSqrt() {
    system("cls");
    cout << "--- Square Root ---" << endl;
    double n;
    cout << "Enter number: ";
    cin >> n;
    
    double result;
    if (n < 0) {
        cout << "Error: Negative number" << endl;
        result = 0;
    } else {
        result = sqrt(n);
        cout << "Result: " << result << endl;
    }
    
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

void doPower() {
    system("cls");
    cout << "--- Power ---" << endl;
    double b, e;
    cout << "Enter base and exponent: ";
    cin >> b >> e;
    
    double result = pow(b, e);
    cout << "Result: " << result << endl;
    
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

void doMixed() {
    system("cls");
    cout << "--- Mixed Calculation ---" << endl;
    cout << "Enter like: 3 + 5 * 2 =" << endl;
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
            if (cmd == '+') memory += total;
            else if (cmd == '-') memory -= total;
            else if (cmd == 'C') memory = 0.0;
            else if (cmd == 'R') cout << "Memory: " << memory << endl;
            continue;
        }

        double num;
        cin >> num;

        if (op == '+') total += num;
        else if (op == '-') total -= num;
        else if (op == '*') total *= num;
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

int main() {
    int choice;
    while (true) {
        showMenu();
        cin >> choice;
        if (choice == 0) {
            cout << "Goodbye!" << endl;
            break;
        }

        if (choice == 1) doSqrt();
        else if (choice == 2) doPower();
        else if (choice == 3) doMixed();
        else {
            cout << "Invalid choice" << endl;
            waitKey();
        }
    }
    return 0;
}

