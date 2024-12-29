#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    ll N;
    cin >> N;
    // 1 1 1 1 -1 -1 -1 -1 -1 -1
    //     10
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<ll> pref(N);
    vector<ll> suff(N);
    map<ll, int> seen;
    {
        for (ll i = 0; i < N; i++) {
            if (i == 0) pref[i] = A[i];
            else pref[i] = pref[i-1] + A[i];
            seen[pref[i]] = 1;
        }
        for (ll i = N - 1; i >= 0; i--) {
            if (i == N - 1) suff[i] = A[i];
            else suff[i] = suff[i+1] + A[i];
            seen[suff[i]] = 1;
        }
    }
    ll target = 0;
    for (ll i = 0; i < N; i++) {
        if (A[i] != -1 && A[i] != 1) {
            target = i;
            break;
        }
    }
    {
        ll mx1 = 0, mn1 = 0;
        ll mx2 = 0, mn2 = 0;
        ll sum = 0;
        for (ll i = target - 1; i >= 0; i--) {
            sum += A[i];
            mx1 = max(mx1, sum);
            mn1 = min(mn1, sum);
        }
        sum = 0;
        for (ll i = target + 1; i < N; i++) {
            sum += A[i];
            mx2 = max(mx2, sum);
            mn2 = min(mn2, sum);
        }
        for (int i = mn1 + mn2 + A[target]; i <= mx1 + mx2 + A[target]; i++) seen[i] = 1;
    }
    {
        ll current_max = 0;
        ll current_min = 0;
        ll best_low = 0;
        ll best_high = 0;
        ll sum = 0;
        for (ll i = 0; i < target; i++) {
            sum += A[i];
            current_max = max(current_max, sum);
            current_min = min(current_min, sum);
            best_low = min(best_low, -(current_max - sum));
            best_high = max(best_high, sum - current_min);
        }
        for (ll i = best_low; i <= best_high; i++) seen[i] = 1;
    }
    {
        ll current_max = 0;
        ll current_min = 0;
        ll best_low = 0;
        ll best_high = 0;
        ll sum = 0;
        for (ll i = N - 1; i > target; i--) {
            sum += A[i];
            current_max = max(current_max, sum);
            current_min = min(current_min, sum);
            best_low = min(best_low, - (current_max - sum));
            best_high = max(best_high, sum - current_min);
        }
        for (ll i = best_low; i <= best_high; i++) seen[i] = 1;
    }
    cout << seen.size() << endl;
    seen[0] = 1;
    for (auto [k, v] : seen) cout << k << " ";
    cout << endl;
}

int main() {
    ll t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}