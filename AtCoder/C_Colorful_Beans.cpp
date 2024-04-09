#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    map<int, int> mp;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, c;
        cin >> a >> c;
        auto it = mp.find(c);
        if (it == mp.end()) {
            mp[c] = a;
        } else {
            mp[c] = min(mp[c], a);
        }
    }
    int best = 0;
    for (auto [c, v]: mp) {
        if (v > best) {
            best = v;
        }
    }
    cout << best << endl;
    return 0;
}