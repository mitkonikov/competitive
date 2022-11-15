// Task: https://mendo.mk/Task.do?id=116

#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    ll cost = 0;
    for (int i = 0; i < m; i++) {
        if (n == 0) break;
        int take = min(a[i].second, n);
        cost += (ll)a[i].first * take;
        n -= take;
    }
    cout << cost << endl;
    return 0;
}