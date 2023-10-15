#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll N, M;
    cin >> N >> M;

    ll current = N;
    ll ans = 0;
    int iter = 0;
    set<int> A;
    while (current > 0) {
        if (iter > 29) {
            cout << -1 << endl;
            return;
        }
        if (A.count(current)) {
            cout << -1 << endl;
            return;
        }

        A.insert(current);
        ll left_over = current % M;
        ans += left_over;
        left_over *= 2;
        current = left_over;
        iter++;
    }
    cout << ans << endl;
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