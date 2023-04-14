#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

template<typename T>
T gcd(T a, T b) {
    return (a == 0) ? b : gcd(b % a, a);
}

void testCase() {
    string S, T;
    cin >> S >> T;
    cout << (gcd((int)S.size(), (int)T.size())) << endl;
}

int main() {
    freopen("sieve.in", "r", stdin);
    
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}