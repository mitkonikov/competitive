#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<ll> A(N);
    vector<ll> pref(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i == 0) pref[i] = A[i];
        else pref[i] = pref[i-1] + A[i];
    }
    auto sum = [&](int l, int r) {
        return (pref[r] - (l-1>=0 ? pref[l-1] : 0));
    };
    auto query = [&](int l, int r) {
        cout << "? ";
        cout << (r - l + 1) << " ";
        for (int i = l; i <= r; i++) {
            cout << i << " ";
        }
        cout << endl;
        ll result;
        cin >> result;
        return result;
    };
    int L = 0, R = N;
    while (R - L > 1) {
        int mid = (R + L) / 2;
        ll q = query(L + 1, mid);
        if (q > sum(L, mid - 1)) {
            R = mid;
        } else {
            L = mid;
        }
    }
    for (int i = max(0, L - 1); i <= min(N-1, L + 1); i++) {
        if (query(i + 1, i + 1) != sum(i, i)) {
            cout << "! " << i + 1 << endl;
            return;
        }
    }
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