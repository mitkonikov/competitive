#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int q;
    cin >> q;
    vector<ll> d(q + 10);
    for (int i = 1; i < q; i++) {
        string s;
        cin >> s;
        if (s == "Patrik") {
            ll dist;
            cin >> dist;
            d[i] = dist;
        } else {
            ll y, time;
            cin >> y >> time;
            d[i] = d[y - 1] + time;
        }
    }
    ll smallest_dist = LLONG_MAX;
    ll sx = 0, sy = 0;
    for (int i = 1; i < q; i++) {
        if (d[i] - d[i-1] < smallest_dist) {
            smallest_dist = d[i] - d[i-1];
            sx = i-1;
            sy = i;
        }
    }
    cout << smallest_dist << " " << sx + 1 << " " << sy + 1 << endl;
    return 0;
}