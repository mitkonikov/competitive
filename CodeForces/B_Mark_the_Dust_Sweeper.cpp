#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    ll ans = 0;
    int id = 0;
    while (id < n - 1 && v[id] != 0) id++;
    for (int i = 0; i < n - 1; i++) {
        if (v[i] == 0) continue;
        id = max(id, i);
        while (id < n - 1 && v[id] != 0) id++;
        while (id < n - 1 && v[i] > 0) {
            v[i]--;
            v[id]++;
            ans++;
            while (id < n - 1 && v[id] != 0) id++;
        }
        ans = ans + v[i];
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