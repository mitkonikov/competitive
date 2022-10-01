#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    vector<set<int>> sets;
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto it = mp.lower_bound(x);
        if (it == mp.end()) {
            if (k == 1) {
                ans[x-1] = i;
                continue;
            }
            sets.push_back({ x });
            mp[x] = sets.size() - 1;
        } else {
            int id = it->second;
            if (sets[id].size() + 1 == k) {
                for (auto el: sets[id]) {
                    ans[el-1] = i;
                }
                ans[x-1] = i;
                mp.erase(it->first);
            } else {
                sets[it->second].insert(x);
                mp.erase(it->first);
                mp[x] = it->second;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (ans[i] != -1) cout << ans[i] + 1 << endl;
        else cout << -1 << endl;
    }

    cout << flush;
    return 0;
}