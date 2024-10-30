#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

bool ContainsWhileLetters(const char* str) {
    bool foundW = false, foundH = false, foundI = false, foundL = false, foundE = false;

    for (int i = 0; str[i] != '\0'; i++) {
        switch (str[i]) {
        case 'w': foundW = true; break;
        case 'h': foundH = true; break;
        case 'i': foundI = true; break;
        case 'l': foundL = true; break;
        case 'e': foundE = true; break;
        }
    }

    return foundW && foundH && foundI && foundL && foundE;
}

char* ReplaceWhile(char* str) {
    const char* target = "while";
    const char* replacement = "**";
    size_t len = strlen(str);

    char* tmp = new char[len * 2 + 1];
    char* t = tmp;
    size_t i = 0;

    while (i < len) {
        if (strncmp(&str[i], target, 5) == 0) {
            strcpy(t, replacement);
            t += strlen(replacement);
            i += 5;
        }
        else {
            *t++ = str[i++];
        }
    }

    *t = '\0';
    strcpy(str, tmp);

    return tmp;
}



int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    if (ContainsWhileLetters(str))
        cout << "All letters from 'while'." << endl;
    else
        cout << "Doesn't contain all letters from 'while'." << endl;

    char* modifiedStr = ReplaceWhile(str);
    cout << "Modified string: " << modifiedStr << endl;

    delete[] modifiedStr;
    return 0;
}
