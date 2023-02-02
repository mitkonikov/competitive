#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    vector<int> A(N + 1);
    vector<vector<int>> r_adj(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        if (i + A[i] >= 1 && i + A[i] <= N) {
            r_adj[i + A[i]].push_back(i);
        }
    }
    vector<int> visited(N + 1, 0);
    vector<bool> loop(N + 1, false);
    vector<int> parents(N + 1, 0);
    vector<bool> main(N + 1, 0);
    vector<int> order;

    int id = 0;
    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;
        int now = i;
        bool cycle = false;
        vector<int> c;
        id++;
        int p = 0;
        int tmp_id = id;
        while (now >= 1 && now <= N) {
            if (visited[now] == id) {
                cycle = true;
                break;
            }
            if (visited[now] != 0) {
                cycle = loop[now];
                tmp_id = visited[now];
                break;
            }
            main[now] = (id == 1);
            if (main[now]) order.push_back(now);
            visited[now] = id;
            c.push_back(now);
            now += A[now];
        }
        for (auto el: c) {
            visited[el] = tmp_id;
        }
        if (cycle) {
            for (auto el: c) {
                loop[el] = true;
            }
        }
    }
    int main_comp = 0;
    for (auto el: visited) {
        if (el == 1) main_comp++;
    }
    int loop_count = 0;
    for (auto el: loop) {
        loop_count += el;
    }

    if (!loop[1]) {
        for (int o = 0; o < order.size(); o++) {
            int i = order[o];
            if (o) parents[i] += parents[order[o-1]] + 1;
            assert(main[i]);
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                auto top = q.front();
                q.pop();
                for (auto el: r_adj[top]) {
                    if (main[el]) continue;
                    parents[i]++;
                    q.push(el);
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += N * 2LL + 1;
        if (main[i]) {
            // that's the main loop
            if (loop[1]) {
                ans -= loop_count;
            } else {
                ans--;
                ans -= parents[i];
                ans -= loop_count;
            }
        } else {
            if (loop[1]) {
                ans -= N * 2LL + 1;
            }
        }
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