#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    set<int> A;
    int mn = INT_MIN;
    int mx = INT_MAX;
    for (int i = 0; i < N; i++) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            mn = max(mn, x);
        } else if (t == 2) {
            mx = min(mx, x);
        } else {
            A.insert(x);
        }
    }
    if (mn > mx) {
        cout << 0 << endl;
        return;
    }
    ll count = mx - mn + 1;
    for (auto el: A) if (el >= mn && el <= mx) count--;
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