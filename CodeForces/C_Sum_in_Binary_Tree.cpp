#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll N;
    cin >> N;
    ll sum = 0;
    while (N > 0) {
        sum += N;
        N /= 2;
    }
    cout << sum << endl;
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