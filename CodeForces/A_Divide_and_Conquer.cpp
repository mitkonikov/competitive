#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum % 2 == 0) {
        cout << 0 << endl;
        return;
    }
    int mn = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 1) {
            int t = a[i];
            int count = 0;
            while (t % 2 == 1) {
                t /= 2;
                count++;
            }
            mn = min(mn, count);
        } else {
            int t = a[i];
            int count = 0;
            while (t % 2 == 0) {
                t /= 2;
                count++;
            }
            mn = min(mn, count);
        }
    }
    cout << mn << endl;
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