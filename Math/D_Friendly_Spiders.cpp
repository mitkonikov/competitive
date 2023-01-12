#include <bits/stdc++.h>
#define ll long long

using namespace std;

struct Sieve {
    static const int N = 4e5 + 1000;
    vector<int> lp, pr;
    int counter = 0;

    Sieve() {
        lp.resize(N + 1, 0);
        pr.resize(N + 1, -1);

        for (int i = 2; i <= N; ++i) {
            if (lp[i] == 0) {
                lp[i] = i;
                pr[counter++] = i;
            }
            for (int j = 0; j < counter && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
                lp[i * pr[j]] = pr[j];
        }
    }
};

template <typename T>
T gcd(T a, T b) {
    return (a == 0) ? b : gcd(b % a, a);
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<map<int, int>> f(N);
    Sieve s;
    vector<vector<int>> adj(s.N);
    for (int i = 0; i < N; i++) {
        int t = A[i];
        while (s.lp[t] > 1 && t % s.lp[t] == 0) {
            f[i][s.lp[t]]++;
            t /= s.lp[t];
        }
        for (auto el : f[i]) {
            if (el.second > 0) {
                adj[el.first].push_back(i);
            }
        }
    }
    int S, T;
    cin >> S >> T;
    S--;
    T--;
    if (S == T) {
        cout << 1 << endl;
        cout << S + 1 << endl;
        return 0;
    }
    if (gcd(A[S], A[T]) > 1) {
        cout << 2 << endl;
        cout << S + 1 << " " << T + 1 << endl;
        return 0;
    }
    queue<int> bfs;
    const int INF = 1e9;
    vector<int> parent(N, -1), dist(N, INF);
    bfs.push(S);
    dist[S] = 0;
    while (!bfs.empty()) {
        auto top = bfs.front();
        bfs.pop();
        for (auto el : f[top]) {
            if (el.second > 0) {
                for (auto v : adj[el.first]) {
                    if (dist[v] > dist[top] + 1) {
                        dist[v] = dist[top] + 1;
                        parent[v] = top;
                        bfs.push(v);
                    }
                }
                adj[el.first].clear();
            }
        }
    }
    if (parent[T] == -1) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> path;
    int tmp = T;
    while (parent[tmp] != -1) {
        path.push_back(tmp);
        tmp = parent[tmp];
    }
    reverse(path.begin(), path.end());
    cout << dist[T] + 1 << endl;
    cout << S + 1 << " ";
    for (auto el : path) {
        cout << el + 1 << " ";
    }
    cout << endl;
    return 0;
}