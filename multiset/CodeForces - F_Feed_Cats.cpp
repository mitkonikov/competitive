#include <bits/stdc++.h>
#define ll long long

using namespace std;

inline void eraseOne(multiset<int> &s, int value) {
    auto itr = s.find(value);
    if (itr != s.end()){
        s.erase(itr);
    }
}

void testCase() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> intervals(M);
    vector<int> change(N + 1);
    vector<vector<int>> put_in(N);
    vector<vector<int>> get_out(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        intervals[i] = { u, v };
        put_in[u].push_back({ u - 1 });
        get_out[v].push_back({ u - 1 });
        change[u]++;
        change[v + 1]--;
    }
    vector<int> lookup(N);
    multiset<int> ms;
    for (int i = 0; i < N; i++) {
        for (auto el: put_in[i]) {
            ms.insert(el);
        }

        lookup[i] = *ms.begin();

        for (auto el: get_out[i]) {
            eraseOne(ms, el);
        }
    }
    vector<int> dp(N);
    int count = 0;
    for (int i = 0; i < N; i++) {
        count += change[i];
        if (i) dp[i] = max(dp[i], dp[i-1]);
        if (count == 0) continue;
        int id = lookup[i];
        if (id >= 0) dp[i] = max(dp[i], dp[id] + count);
        else dp[i] = max(dp[i], count);
    }
    cout << dp[N-1] << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}