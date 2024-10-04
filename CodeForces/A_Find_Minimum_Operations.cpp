#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll N, K;
    cin >> N >> K;
    if (K == 1) {
        cout << N << endl;
        return;
    }
    int count = 0;
    vector<ll> base;
    while (N > 0) {
        base.push_back(N % K);
        N /= K;
    }
    for (int i = 0; i < base.size(); i++) {
        count += base[i];
    }
    cout << count << endl;
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