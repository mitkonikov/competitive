#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<set<int>> sets(N);
    for (int i = 0; i < N; i++) {
        int K;
        cin >> K;
        for (int j = 0; j < K; j++) {
            int x;
            cin >> x;
            sets[i].insert(x);
        }
    }
    int ans = 0;
    set<int> un;
    for (int i = 0; i < N; i++) {
        for (auto el: sets[i]) un.insert(el);
    }
    for (auto el: un) { // 50
        vector<int> vis(60, 0);
        bool f = 0;
        for (int i = 0; i < N; i++) { // 50
            if (!sets[i].count(el)) {
                for (auto el: sets[i]) { // 50
                    vis[el] = 1;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < 60; i++) if (vis[i]) count++;
        ans = max(ans, count);
    }
    cout << ans << endl;
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