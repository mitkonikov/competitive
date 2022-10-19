#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n, q;
    cin >> n >> q;

    long long sum = 0;
    vector<ll> a(2, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        a[x%2]++;
    }

    for (int i = 0; i < q; i++) {
        int type, x;
        cin >> type >> x;
        if (type == 0) { // add to even
            if (x % 2 == 0) {
                sum += a[0] * x;
            } else {
                sum += a[0] * x;
                a[1] += a[0];
                a[0] = 0;
            }
        } else {
            if (x % 2 == 0) {
                sum += a[1] * x;
            } else {
                sum += a[1] * x;
                a[0] += a[1];
                a[1] = 0;
            }
        }
        cout << sum << endl;
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