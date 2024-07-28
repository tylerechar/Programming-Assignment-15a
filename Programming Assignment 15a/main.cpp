#include <iostream>

using namespace std;

class invalidCharacterException : public exception {
public:
    const char* what() const throw() {
        return "Invalid character input.";
    }
};

class invalidRangeException : public exception {
public:
    const char* what() const throw() {
        return "Character is out of range.";
    }
};

char character(char start, int offset) {
    if (!isalpha(start)) {
        throw invalidCharacterException();
    }
    char target = start + offset;
    if (!isalpha(target) || (isupper(start) && islower(target)) || (islower(start) && isupper(target))) {
        throw invalidRangeException();
    }
    return target;
}

int main() {
    try {
        cout << "character('a', 1): ";
        cout << character('a', 1) << "\n";
    }
    catch (const exception& e) {
        cout << e.what() << "\n";
    }

    try {
        cout << "character('a', -1): ";
        cout << character('a', -1) << "\n";
    }
    catch (const exception& e) {
        cout << e.what() << "\n";
    }

    try {
        cout << "character('Z', -1): ";
        cout << character('Z', -1) << "\n";
    }
    catch (const exception& e) {
        cout << e.what() << "\n";
    }

    try {
        cout << "character('?', 5): ";
        cout << character('?', 5) << "\n";
    }
    catch (const exception& e) {
        cout << e.what() << "\n";
    }

    try {
        cout << "character('A', 32): ";
        cout << character('A', 32) << "\n";
    }
    catch (const exception& e) {
        cout << e.what() << "\n";
    }

    system("pause");
    return 0;
}
