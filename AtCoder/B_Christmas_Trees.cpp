#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ll A, M, L, R;
    cin >> A >> M >> L >> R;
    if (A < L) {
        cout << (R - A + M) / M - (L - 1 - A + M) / M << endl;
    } else if (A > R) {
        cout << (A - L + M) / M - (A - (R + 1) + M) / M << endl;
    } else {
        cout << (R - A + M) / M + (A - L + M) / M - 1 << endl;
    }
    return 0;
}