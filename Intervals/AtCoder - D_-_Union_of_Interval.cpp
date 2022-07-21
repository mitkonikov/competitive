#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        v[i] = { l, r };
    }
    sort(v.begin(), v.end(), [&](auto &a, auto &b) {
        if (a.second == b.second) return (a.first < b.first);
        return (a.second < b.second);
    });
    vector<pair<int, int>> ans;
    ans.reserve(n);
    int l = v[0].first, r = v[0].second;
    for (int i = 0; i < n; i++) {
        if (v[i].first <= r) {
            r = max(r, v[i].second);
            l = min(l, v[i].first);
            while (!ans.empty() && v[i].first <= ans.back().second) {
                l = min(l, ans.back().first);
                ans.pop_back();
            }
        } else {
            ans.push_back({ l, r });
            l = v[i].first; r = v[i].second;
        }
    }
    ans.push_back({ l, r });
    for (auto el: ans) {
        cout << el.first << " " << el.second << endl;
    }
    cout << flush;
    return 0;
}