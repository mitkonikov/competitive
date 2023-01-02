#include <bits/stdc++.h>
#define ll long long

using namespace std;

void testCase() {
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<int> d(n);
    int reached = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        while (a[i] > 0 && a[i] % 2 == 0) {
            reached++;
            a[i] /= 2;
        }
        int id = i + 1;
        while (id > 0 && id % 2 == 0) {
            d[i]++;
            id /= 2;
        }
    }
    if (reached >= n) {
        cout << 0 << endl;
        return;
    }
    sort(d.rbegin(), d.rend());
    int count = 0;
    for (int i = 0; i < n; i++) {
        reached += d[i];
        count++;
        if (reached >= n) {
            cout << count << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    return 0;
}