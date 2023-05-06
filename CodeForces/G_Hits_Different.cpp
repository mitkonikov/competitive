#include <bits/stdc++.h>
#define ll __int128_t

using namespace std;

int main() {
    vector<vector<ll>> levels;
    int sum = 0;
    int level = 1;
    vector<pair<int, int>> where(1e6 + 10);
    for (int i = 1; sum <= 1e6 + 100; i++) {
        levels.push_back({});
        for (int j = 1; j <= level; j++) {
            if (j + sum < where.size()) {
                where[j + sum] = { level - 1, levels.back().size() };
            }
            levels.back().push_back((ll)(j + sum) * (j + sum));
        }
        for (int i = 1; i < levels.back().size(); i++) {
            levels.back()[i] += levels.back()[i-1];
        }
        level++;
        sum += i;
    }

    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        auto [l, p] = where[N];
        int L = p, R = p;
        ll sum = 0;
        while (l >= 0) {
            R = min(R, (int)levels[l].size() - 1);
            sum += levels[l][R] - (L-1>=0?levels[l][L-1]:(ll)0);
            L--;
            l--;
        }
        cout << (long long)sum << endl;
    }

    cout << flush;
    return 0;
}