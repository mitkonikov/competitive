#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

vector<set<int>> adj;

pair<int, int> find_center(int u, int p = -1) {
    for (auto el: adj[u]) {
        if (el == p) continue;
        if (adj[el].size() > 2) return { u, el };
        return find_center(el, u);
    }
    assert(false);
    return { -1, -1 };
}

void testCase() {
    int N, Q;
    cin >> N >> Q;
    adj.clear();
    adj.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        adj[i+1].insert(i+2);
        adj[i+2].insert(i+1);
        cout << i+1 << " " << i+2 << endl;
    }
    int A = 1, B = N, C = -1;
    auto no = [&]() {
        cout << "-1 -1 -1" << endl;
    };
    auto yes = [&](int u, int v1, int v2) {
        if (v1 == v2) return no();
        cout << u << " " << v1 << " " << v2 << endl;
        adj[u].erase(v1);
        adj[v1].erase(u);
        adj[u].insert(v2);
        adj[v2].insert(u);
    };
    for (int i = 0; i < Q; i++) {
        int D;
        cin >> D;
        if (D == N - 1) {
            // we have to create a path graph
            if (C == -1) {
                no();
                continue;
            } else {
                // detach branch B and attach it to node C
                auto [u, v1] = find_center(B);
                yes(u, v1, C);
                C = -1;
            }
        } else {
            if (C == -1) {
                C = N - 1;
                yes(N, N - 1, D);
            } else {
                yes(N, *adj[N].begin(), D);
            }
        }
    }
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