#include <bits/stdc++.h>

using namespace std;

const int mxn = 1e5 + 10;
bool isPrime[mxn];

int main() {
    memset(isPrime, true, sizeof(bool)*mxn);
    for (int p = 2; p*p <= mxn; p++) {
        if (isPrime[p]) {
            for (int i = p*p; i <= mxn; i += p) {
                isPrime[i] = false;
            }
        }
    }

    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        if (isPrime[i] && n % i != 0) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}