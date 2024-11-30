#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

template<typename T>
T gcd(T a, T b) {
    return (a == 0) ? b : gcd(b % a, a);
}

void testCase() {
    int A, B;
    cin >> A >> B;
    cout << A * B / gcd(A, B) << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}