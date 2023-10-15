#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N;
    cin >> N;
    map<ll, ll> mp;
    for (int i = 0; i < N; i++) {
        ll S, C;
        cin >> S >> C;
        mp[S] += C;
    }
    for (auto it = mp.begin(); it != mp.end(); it++) {
        ll new_count = it->second / 2;
        ll new_size = it->first * 2;
        it->second -= new_count * 2;
        mp[new_size] += new_count;
    }
    int count = 0;
    for (auto [s, c]: mp) {
        if (c > 0) count++;
    }
    cout << count << endl;
    return 0;
}