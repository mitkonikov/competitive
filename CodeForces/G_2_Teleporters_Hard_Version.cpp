#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int solve(vector<ll>& A, int N, int C) {
    vector<pair<ll, int>> mins(N);
    vector<ll> pref(N);
    for (int i = 0; i < N; i++) {
        mins[i] = { min(i + 1 + A[i], N - i + A[i]), i };
    }
    sort(mins.begin(), mins.end());
    for (int i = 0; i < N; i++) {
        if (i) pref[i] = pref[i-1] + mins[i].first;
        else pref[i] = mins[i].first;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        // I will pick first the i-th value
        ll cost = mins[i].second + 1 + A[mins[i].second];
        if (cost > C) {
            continue;
        }
        ll target = C - cost;
        int L = 0, R = N;
        while (R - L > 1) {
            int mid = (R + L) / 2;
            ll cst = pref[mid] - (mid >= i ? mins[i].first : 0);
            if (cst > target) {
                R = mid;
            } else {
                L = mid;
            }
        }

        int current_ans = 1;
        for (int mid = max(0, L - 2); mid <= min(N - 1, L + 2); mid++) {
            ll cst = pref[mid] - (mid >= i ? mins[i].first : 0);
            if (cst <= target) {
                current_ans = max(current_ans, 1 + L);
            }
        }
        ans = max(ans, current_ans);
    }
    return ans;
}

void testCase() {
    ll N, C;
    cin >> N >> C;
    vector<ll> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cout << solve(A, N, C) << endl;
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