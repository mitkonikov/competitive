#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int solve(int n, int k, string s) {
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) a[i] = (s[i] == 'W');
    
    vector<int> pref(n, 0);
    pref[0] = a[0];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i-1] + a[i];
    }
    
    int ans = pref[k-1];
    for (int i = 0; i < n - k; i++) {
        ans = min(ans, pref[i+k] - pref[i]);
    }
    return ans;
}

void testCase() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    
    cout << solve(n, k, s) << endl;
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