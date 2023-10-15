#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

long long binary(long long base, long long power) {
    long long result = 1;

    while (power > 0) {
        if (power % 2 == 1) {
            result = result * base;
            power--;
        }

        base = base * base;
        power /= 2;
    }

    return result;
}

int main() {
    ll A, B;
    cin >> A >> B;
    cout << (binary(A, B) + binary(B, A)) << endl;
    return 0;
}