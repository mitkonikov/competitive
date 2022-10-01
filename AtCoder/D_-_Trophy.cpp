#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    ll x;
    cin >> n >> x;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    ll cost_to = 0;
    ll mn = INT_MAX;
    ll best = (ll)v[0].first + (x * (ll)v[0].second);
    for (int i = 0; i < n; i++) {
        best = min(best, cost_to + mn * (x - i));
        cost_to = cost_to + v[i].first + v[i].second;
        mn = min(mn, (ll)v[i].second);
    }
    best = min(best, cost_to + mn * (x - n));
    cout << best << endl;
    cout << flush;
    return 0;
}