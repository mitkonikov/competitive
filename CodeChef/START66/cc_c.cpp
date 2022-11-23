#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int p1 = 0, p2 = n - 1;
    int ans = 0;
    while (p1 < p2) {
        if (a[p1] == a[p2]) {
            p1++;
            p2--;
            continue;
        }

        if (a[p1] < a[p2]) {
            a[p2] -= a[p1];
            p1++;
            ans++;
        }

        if (a[p1] > a[p2]) {
            a[p1] -= a[p2];
            ans++;
            p2--;
        }
    }
    
    cout << ans << endl;
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