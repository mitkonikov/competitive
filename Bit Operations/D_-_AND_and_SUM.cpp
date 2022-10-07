#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll A, S;
    cin >> A >> S;

    bool ok = true;
    bool carry = false;
    for (int i = 0; i < 61 && ok; i++) {
        if ((1LL << i) > A && (1LL << i) > S) break;
        if (A & (1LL << i)) {
            if (S & (1LL << i)) {
                if (!carry) ok = false;
            } else {
                if (carry) ok = false;
                carry = true;
            }
        } else {
            if (S & (1LL << i)) {
                if (carry) {
                    carry = false;
                }
            }
        }
    }

    cout << (ok && !carry ? "Yes" : "No") << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    return 0;
}