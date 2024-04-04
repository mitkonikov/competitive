#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    ll X;
    cin >> X;
    map<ll, ll> mp;
    mp[X] = 1;
    ll cost = 0;
    while (!mp.empty()) {
        map<ll, ll> new_mp;
        for (auto [v, frq]: mp) {
            cost += v * frq;
            ll nv1 = v / 2;
            ll nv2 = (v + 1) / 2;
            if (nv1 > 1) new_mp[nv1] += frq;
            if (nv2 > 1) new_mp[nv2] += frq;
        }
        mp.swap(new_mp);
    }
    cout << cost << endl;
    return 0;
}