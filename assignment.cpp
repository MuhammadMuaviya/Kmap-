#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX_VARIABLES = 5;
const int MAX_SIZE = pow(2, MAX_VARIABLES);

void printKMap(int variables) {
    cout << "KMap layout for " << variables << " variables:" << endl;
    // Print KMap headers
    cout << " ";
    for (int i = 0; i < variables; ++i) {
        cout << (char)('A' + i) << " ";
    }
    cout << endl;
    // Print KMap body
    for (int i = 0; i < MAX_SIZE; ++i) {
        cout << (char)('0' + (i >> variables - 1)); // Print C variable
        for (int j = variables - 2; j >= 0; --j) {
            cout << " " << (char)('0' + ((i >> j) & 1));
        }
        cout << endl;
    }
}

void inputTruthTableValues(int kmap[MAX_SIZE]) {
    int numOnBits;
    cout << "Enter the number of ON bits: ";
    cin >> numOnBits;
    cout << "Enter the location of ON bits (min or max terms): ";
    for (int i = 0; i < numOnBits; ++i) {
        int term;
        cin >> term;
        kmap[term] = 1;
    }
}

void simplifyKMap(int kmap[MAX_SIZE]) {
    // Simplification algorithm implementation
    // This is just a placeholder
    cout << "Simplified Equation:" << endl;
    cout << "Out = ";
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (kmap[i] == 1) {
            int variables = log2(MAX_SIZE);
            for (int j = 0; j < variables; ++j) {
                if ((i >> j) & 1) {
                    if (j > 0) cout << " + ";
                    cout << (char)('A' + j);
                } else {
                    if (j > 0) cout << "'";
                    cout << (char)('A' + j);
                }
            }
            cout << endl;
        }
    }
}

int main() {
    int variables;
    cout << "Enter the number of variables (2 to " << MAX_VARIABLES << "): ";
    cin >> variables;

    if (variables < 2 || variables > MAX_VARIABLES) {
        cout << "Invalid number of variables!" << endl;
        return 1;
    }

    int kmap[MAX_SIZE] = {0};

    printKMap(variables);
    inputTruthTableValues(kmap);
    simplifyKMap(kmap);

    return 0;
}