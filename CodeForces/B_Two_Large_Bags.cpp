#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    map<int, int> frq;
    for (int i = 0; i < N; i++) {
        frq[A[i]]++;
    }
    bool ok = true;
    for (auto it = frq.begin(); it != frq.end(); ) {
        auto [k, v] = *it;
        if (v == 1) {
            ok = false;
            break;
        }
        if (v >= 2) {
            frq[k+1] += v - 2;
        }
        it = frq.upper_bound(k);
    }
    cout << (ok ? "Yes" : "No") << endl;
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