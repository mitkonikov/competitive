#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int mx = *max_element(a.begin(), a.end());
    vector<bool> seen(mx+1, false);
    for (int i = 0; i < n; i++) seen[a[i]] = true;
    int sum = 0;
    for (int i = 1; i <= mx; i++) {
        if (!seen[i]) sum += i;
    }
    int left = s - sum;
    for (int i = mx + 1; left > 0; i++) {
        if (i > left) {
            cout << "NO" << endl;
            return;
        }
        left -= i;
    }
    cout << (left == 0 ? "YES" : "NO") << endl;
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