#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<pair<ll, ll>> intervals(N);
    for (int i = 0; i < N; i++) {
        int L, R;
        cin >> L >> R;
        intervals[i] = { L, R };
    }
    ll L = -1;
    ll R = 1e9 + 100;
    while (L + 1 < R) {
        ll MID = (L + R) / 2;
        // K >= MID
        ll l = 0, r = 0;
        bool cant = false;
        for (int i = 0; i < N; i++) {
            ll nr = r + MID;
            ll nl = l - MID;
            if (nr < intervals[i].first || nl > intervals[i].second) {
                cant = true;
                break;
            }
            l = max(intervals[i].first, nl);
            r = min(intervals[i].second, nr);
        }
        if (cant) {
            L = MID;
        } else {
            R = MID;
        }
    }
    cout << R << endl;
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