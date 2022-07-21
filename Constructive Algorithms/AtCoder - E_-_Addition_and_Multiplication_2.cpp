#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main() {
    int budget;
    cin >> budget;
    vector<pair<int, int>> v(9);
    vector<int> cost(9);
    for (int i = 0; i < 9; i++) {
        cin >> v[i].first;
        v[i].second = i;
        cost[i] = v[i].first;
    }
    sort(v.begin(), v.end(), [&](auto a, auto b) {
        if (a.first == b.first) return (a.second > b.second);
        return (a.first < b.first);
    });
    int how = budget / v[0].first;
    budget = budget % v[0].first;
    vector<pair<int, int>> ans;
    ans.push_back({ v[0].second, how });
    for (int i = 8; i >= 0; i--) {
        if (i <= ans[0].first) break;
        ans.push_back({ i, 0 });
        while (true) {
            int save = cost[ans[0].first];
            budget += save;
            if (budget >= cost[i]) {
                ans.back().second++;
                ans[0].second--;
                budget -= cost[i];
            } else {
                budget -= save;
                break;
            }
        }
    }
    sort(ans.rbegin(), ans.rend());
    for (auto el: ans) {
        for (int i = 0; i < el.second; i++) {
            cout << el.first + 1;
        }
    } cout << endl;
    cout << flush;
    return 0;
}