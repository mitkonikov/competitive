#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    vector<int> a(n);
    int OR = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        OR |= a[i];
    }

    ll all = (ll)n * (n + 1) / 2;
    ll bad = 0;

    vector<int> visited(3 * OR, 0);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cur ^= a[i];
        for (int j = 0; j < 1000; j++) {
            if (j * j > OR) break;
            if (cur == j * j) bad++;
            bad += visited[cur ^ (j * j)];
        }
        visited[cur]++;
    }

    cout << all - bad << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    return 0;
}