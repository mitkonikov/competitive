#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

const int MOD = 1e9 + 7;

long long binary(long long base, long long power) {
    long long result = 1;

    while (power > 0) {
        if (power % 2 == 1) {
            result = (result * base) % MOD;
            power--;
        }

        base = (base * base) % MOD;
        power /= 2;
    }

    return result;
}

void testCase() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), d(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> d[i];

    vector<int> mp_a(n + 1), mp_b(n + 1);
    for (int i = 0; i < n; i++) {
        mp_a[a[i]] = i;
        mp_b[b[i]] = i;
    }

    vector<bool> visited(n, false);
    ll ans = 1;
    for (int i = 0; i < n; i++) {
        // through d's
        if (d[i] == 0) continue;
        bool side = (b[i] == d[i]); // 0 - a, 1 - b
        int p = a[i];
        if (side) {
            p = b[i];
        }

        while (true) {
            if (side) {
                int where = mp_a[p];
                if (visited[where]) break;
                visited[where] = true;
                if (d[where] == 0) {
                    d[where] = b[where];
                    p = b[where];
                } else {
                    break;
                    p = b[where];
                }
            } else {
                int where = mp_b[p];
                if (visited[where]) break;
                visited[where] = true;
                if (d[where] == 0) {
                    d[where] = a[where];
                    p = a[where];
                } else {
                    break;
                    p = a[where];
                }
            }
        }
    }

    // for (auto e: d) {
    //     cout << e << " ";
    // } cout << endl;

    int count = 0;
    visited.clear();
    visited.resize(n, false);
    for (int i = 0; i < n; i++) {
        if (d[i] != 0) continue;
        if (visited[i]) continue;
        int p = i;
        visited[i] = true;
        while (true) {
            p = mp_b[a[p]];
            if (visited[p]) break;
            visited[p] = true;
        }
        count += (a[i] != b[i]);
    }

    cout << binary(2, count) << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    return 0;
}