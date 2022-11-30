#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

inline int umin(int ans, int new_ans, int& mn, int n) {
    if (ans == INT_MAX) {
        mn = n;
        return new_ans;
    } else {
        if (n < mn) {
            mn = n;
            return new_ans;
        } else {
            return ans;
        }
    }
}

void testCase() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    sort(a.begin(), a.end());
    int ans = INT_MAX;
    int mn = INT_MAX;
    if (a[0].first != a[1].first) {
        ans = umin(ans, a[0].second + 1, mn, a[0].first);
    }
    if (a[n-1].first != a[n-2].first) {
        ans = umin(ans, a[n-1].second + 1, mn, a[n-1].first);
    }
    for (int i = 1; i < n - 1; i++) {
        if (a[i].first != a[i+1].first && a[i].first != a[i-1].first) {
            ans = umin(ans, a[i].second + 1, mn, a[i].first);
        }
    }
    cout << (ans == INT_MAX ? -1 : ans) << endl;
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