#include <iostream>
#include <cmath>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

double memory = 0.0;

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

class BigInt {
private:
    string value;
    bool isNegative;
    
    string addStrings(const string& num1, const string& num2) const {
        string result;
        int carry = 0;
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            result.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
    
    string subtractStrings(const string& num1, const string& num2) const {
        string result;
        int borrow = 0;
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        
        while (i >= 0) {
            int diff = (num1[i] - '0') - borrow;
            if (j >= 0) diff -= (num2[j] - '0');
            
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            
            result.push_back(diff + '0');
            i--;
            j--;
        }
        
        while (result.length() > 1 && result.back() == '0') {
            result.pop_back();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
    
    bool isGreaterOrEqual(const string& num1, const string& num2) const {
        if (num1.length() != num2.length()) {
            return num1.length() > num2.length();
        }
        return num1 >= num2;
    }

public:
    BigInt(const string& s = "0") {
        if (s.empty()) {
            value = "0";
            isNegative = false;
            return;
        }
        
        string num = s;
        isNegative = false;
        
        if (num[0] == '-') {
            isNegative = true;
            num = num.substr(1);
        }
        
        while (num.length() > 1 && num[0] == '0') {
            num = num.substr(1);
        }
        
        for (char c : num) {
            if (!isdigit(c)) {
                value = "0";
                isNegative = false;
                return;
            }
        }
        
        value = num;
        if (value == "0") isNegative = false;
    }
    
    string toString() const {
        return (isNegative ? "-" : "") + value;
    }
    
    BigInt operator+(const BigInt& other) const {
        if (isNegative == other.isNegative) {
            string sum = addStrings(value, other.value);
            BigInt result(sum);
            result.isNegative = isNegative;
            return result;
        }
        
        if (isGreaterOrEqual(value, other.value)) {
            string diff = subtractStrings(value, other.value);
            BigInt result(diff);
            result.isNegative = isNegative;
            if (result.value == "0") result.isNegative = false;
            return result;
        } else {
            string diff = subtractStrings(other.value, value);
            BigInt result(diff);
            result.isNegative = other.isNegative;
            if (result.value == "0") result.isNegative = false;
            return result;
        }
    }
    
    BigInt operator-(const BigInt& other) const {
        BigInt negOther = other;
        negOther.isNegative = !negOther.isNegative;
        return *this + negOther;
    }
    
    BigInt operator*(const BigInt& other) const {
        if (value == "0" || other.value == "0") {
            return BigInt("0");
        }
        
        int len1 = value.length();
        int len2 = other.value.length();
        vector<int> result(len1 + len2, 0);
        
        for (int i = len1 - 1; i >= 0; i--) {
            for (int j = len2 - 1; j >= 0; j--) {
                int mul = (value[i] - '0') * (other.value[j] - '0');
                int sum = mul + result[i + j + 1];
                
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }
        
        string product;
        for (int num : result) {
            if (!(product.empty() && num == 0)) {
                product.push_back(num + '0');
            }
        }
        
        if (product.empty()) product = "0";
        
        BigInt res(product);
        res.isNegative = (isNegative != other.isNegative);
        if (res.value == "0") res.isNegative = false;
        return res;
    }
    
    bool operator<(const BigInt& other) const {
        if (isNegative != other.isNegative) {
            return isNegative;
        }
        
        if (value.length() != other.value.length()) {
            if (isNegative) {
                return value.length() > other.value.length();
            } else {
                return value.length() < other.value.length();
            }
        }
        
        if (isNegative) {
            return value > other.value;
        } else {
            return value < other.value;
        }
    }
    
    bool operator==(const BigInt& other) const {
        return value == other.value && isNegative == other.isNegative;
    }
    
    bool operator<=(const BigInt& other) const {
        return *this < other || *this == other;
    }
    
    bool operator>(const BigInt& other) const {
        return !(*this <= other);
    }
    
    bool operator>=(const BigInt& other) const {
        return !(*this < other);
    }
};

BigInt bigMemory("0");

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
    cout << "|=- 11. Big Integer Calculator-=|" << endl;
    cout << "|=- 0. Exit                   -=|" << endl;
    cout << "|=- Current Memory:" << memory << "          -=|" << endl;
    cout << "|=- Current Big Memory:" << bigMemory.toString() << "    -=|" << endl;
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

void processBigResultMemory(const BigInt& result) {
    cout << "\nBig Memory options for result:" << endl;
    cout << "B+ : Add to big memory" << endl;
    cout << "B- : Subtract from big memory" << endl;
    cout << "BC : Clear big memory" << endl;
    cout << "Any other key: Continue" << endl;
    cout << "Your choice: ";

    char cmd1, cmd2;
    cin >> cmd1;
    if (cmd1 == 'B' || cmd1 == 'b') {
        cin >> cmd2;
        if (cmd2 == '+') {
            bigMemory = bigMemory + result;
            cout << "Added to big memory. New Big Memory: " << bigMemory.toString() << endl;
        } else if (cmd2 == '-') {
            bigMemory = bigMemory - result;
            cout << "Subtracted from big memory. New Big Memory: " << bigMemory.toString() << endl;
        } else if (cmd2 == 'C' || cmd2 == 'c') {
            bigMemory = BigInt("0");
            cout << "Big memory cleared." << endl;
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

void doBigIntegerCalc() {
    system("cls");
    cout << "--- Big Integer Calculator ---" << endl;
    cout << "Supports +, -, * operations on very large integers" << endl;
    cout << "Big Memory: " << bigMemory.toString() << endl;
    cout << "Format: number1 operator number2" << endl;
    cout << "Use 'B' for big memory operations: B+ B- BC" << endl;
    cout << "Example: 12345678901234567890 + 98765432109876543210" << endl;
    cout << "--------------------------------" << endl;
    
    string input1, op, input2;
    cout << "Enter expression: ";
    cin >> input1 >> op >> input2;
    
    BigInt num1(input1);
    BigInt num2(input2);
    BigInt result("0");
    
    if (op == "+") {
        result = num1 + num2;
        cout << input1 << " + " << input2 << " = " << result.toString() << endl;
    } else if (op == "-") {
        result = num1 - num2;
        cout << input1 << " - " << input2 << " = " << result.toString() << endl;
    } else if (op == "*") {
        result = num1 * num2;
        cout << input1 << " * " << input2 << " = " << result.toString() << endl;
    } else if (op == "B" || op == "b") {
        char cmd;
        cin >> cmd;
        if (cmd == '+') {
            bigMemory = bigMemory + num1;
            cout << "Added to big memory. New Big Memory: " << bigMemory.toString() << endl;
        } else if (cmd == '-') {
            bigMemory = bigMemory - num1;
            cout << "Subtracted from big memory. New Big Memory: " << bigMemory.toString() << endl;
        } else if (cmd == 'C' || cmd == 'c') {
            bigMemory = BigInt("0");
            cout << "Big memory cleared." << endl;
        }
        waitKey();
        return;
    } else {
        cout << "Error: Unsupported operator. Only +, -, * are supported." << endl;
        waitKey();
        return;
    }
    
    processBigResultMemory(result);
}

void doConversion() {
    int category;
    double value, result;
    char fromUnit[20], toUnit[20];

    while (true) {
        system("cls");
        cout << "+====== Conversion Calculator ======+" << endl;
        cout << "|=- 1. Length (e.g., m, cm, in)   -=|" << endl;
        cout << "|=- 2. Weight (e.g., kg, g, lb)   -=|" << endl;
        cout << "|=- 3. Temperature (C, F)         -=|" << endl;
        cout << "|=- 4. Number Base (Bin, Dec, Hex)-=|" << endl;
        cout << "|=- 0. Back to Main Menu          -=|" << endl;
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
            case 4: {
                int baseChoice;
                cout << "--- Number Base Conversion ---" << endl;
                cout << "1. Decimal to Binary" << endl;
                cout << "2. Decimal to Hexadecimal" << endl;
                cout << "3. Binary to Decimal" << endl;
                cout << "4. Hexadecimal to Decimal" << endl;
                cout << "Your choice: ";
                cin >> baseChoice;
                switch (baseChoice) {
                    case 1: {
                        int num;
                        cout << "Enter decimal number: ";
                        cin >> num;
                        char buffer[65];
                        _itoa(num, buffer, 2);
                        cout << "Decimal " << num << " = Binary " << buffer << endl;
                        strcpy(fromUnit, "Dec");
                        strcpy(toUnit, "Bin");
                        result = 0;
                        cout << "\nResult: " << num << " " << fromUnit << " = " << buffer << " " << toUnit << endl;
                        waitKey();
                        continue;
                    }
                    case 2: {
                        int num;
                        cout << "Enter decimal number: ";
                        cin >> num;
                        char buffer[65];
                        _itoa(num, buffer, 16);
                        for (int i = 0; buffer[i]; i++) buffer[i] = toupper(buffer[i]);
                        cout << "Decimal " << num << " = Hexadecimal 0x" << buffer << endl;
                        strcpy(fromUnit, "Dec");
                        strcpy(toUnit, "Hex");
                        result = 0;
                        cout << "\nResult: " << num << " " << fromUnit << " = 0x" << buffer << " " << toUnit << endl;
                        waitKey();
                        continue;
                    }
                    case 3: {
                        char binStr[65];
                        cout << "Enter binary number: ";
                        cin >> binStr;
                        int decimal = 0;
                        for (int i = 0; binStr[i] != '\0'; i++) {
                            decimal = decimal * 2 + (binStr[i] - '0');
                        }
                        cout << "Binary " << binStr << " = Decimal " << decimal << endl;
                        strcpy(fromUnit, "Bin");
                        strcpy(toUnit, "Dec");
                        result = decimal;
                        cout << "\nResult: " << binStr << " " << fromUnit << " = " << result << " " << toUnit << endl;
                        break;
                    }
                    case 4: {
                        char hexStr[65];
                        cout << "Enter hexadecimal number (without 0x): ";
                        cin >> hexStr;
                        int decimal = 0;
                        for (int i = 0; hexStr[i] != '\0'; i++) {
                            int digit;
                            if (hexStr[i] >= '0' && hexStr[i] <= '9') digit = hexStr[i] - '0';
                            else if (hexStr[i] >= 'A' && hexStr[i] <= 'F') digit = hexStr[i] - 'A' + 10;
                            else if (hexStr[i] >= 'a' && hexStr[i] <= 'f') digit = hexStr[i] - 'a' + 10;
                            else {
                                cout << "Invalid hexadecimal digit!" << endl;
                                waitKey();
                                continue;
                            }
                            decimal = decimal * 16 + digit;
                        }
                        cout << "Hexadecimal 0x" << hexStr << " = Decimal " << decimal << endl;
                        strcpy(fromUnit, "Hex");
                        strcpy(toUnit, "Dec");
                        result = decimal;
                        cout << "\nResult: 0x" << hexStr << " " << fromUnit << " = " << result << " " << toUnit << endl;
                        break;
                    }
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
        if (category != 4 || (baseChoice == 3 || baseChoice == 4)) {
            processResultMemory(result);
        }
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
                    case 11: doBigIntegerCalc(); break;
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
