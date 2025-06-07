#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, L;
    cin >> N >> L;
    vector<int> D(N);
    map<int, int> mp;
    mp[0]++;
    for (int i = 1; i < N; i++) {
        int X;
        cin >> X;
        D[i] = (D[i-1] + X) % L;
        mp[D[i]]++;
    }
    if (L % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    for (auto& [k, v]: mp) {
        auto v2 = mp.find((k + L / 3) % L) != mp.end() ? mp.find((k + L / 3) % L)->second : 0;
        auto v3 = mp.find((k + L / 3 * 2) % L) != mp.end() ? mp.find((k + L / 3 * 2) % L)->second : 0;
        ans += (ll)v * v2 * v3;
    }
    cout << ans / 3 << endl;
    return 0;
}