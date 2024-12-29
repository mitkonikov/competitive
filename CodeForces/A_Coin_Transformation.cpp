#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll N;
    cin >> N;
    ll count = 0;
    while (N > 3) {
        N = N / 4;
        count++;
    }
    cout << (1LL << count) << endl;
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