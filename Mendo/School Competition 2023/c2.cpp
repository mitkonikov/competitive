#include <bits/stdc++.h>

using namespace std;

// This is a solution without Matrix Exponentiation

int main() {
    long long X;
    cin >> X;
    int a = 0;
    
    if (X == 1) {
        cout << 1 << endl;
        return 0;
    }

    if (X % 4 == 2) a = 2;
    else if (X % 4 == 3) a = 4;
    else if (X % 4 == 0) a = 8;
    else if (X % 4 == 1) a = 16;

    cout << max(0LL, (X - 2)) / 4 * 20 + a << endl;
    return 0;
}