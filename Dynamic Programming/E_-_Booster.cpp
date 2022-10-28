#include <bits/stdc++.h>

#define ll long long

using namespace std;

vector<pair<int, int>> towns;
vector<vector<double>> dp;
int n, m;

const ll INF = LLONG_MAX / 100;

double sq(int a) {
    return (double)a * a;
}

double dist(int a, int b) {
    pair<int, int> A = { 0, 0 };
    pair<int, int> B = towns[b];
    if (a != -1) {
        A = towns[a];
    }

    double ex = sq(A.first - B.first) + sq(A.second - B.second);
    return sqrt(ex);
}

double dfs(int mask, int last_town) {
    if (last_town != -1 && dp[last_town][mask] != INF) {
        return dp[last_town][mask];
    }

    int bitcount = 0;
    for (int j = 0; j < m; j++) {
        if (mask & (1 << (j + n))) bitcount++;
    }
    double acc = pow(2, bitcount);
    //assert(acc != 0);

    double best = INF;
    if ((mask & ((1 << n) - 1)) == ((1 << n) - 1)) {
        best = dist(-1, last_town) / acc;
    }

    for (int i = 0; i < n + m; i++) {
        if ((1 << i) & mask) {
            continue;
        }

        best = min(best,
            dfs(mask | (1 << i), i) +
            (dist(last_town, i)
            / acc)
        );
    }

    if (last_town == -1) return best;
    return dp[last_town][mask] = best;
}

int main() {
    cin >> n >> m;
    dp.resize(n + m, vector<double>((1 << 18), INF));
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        towns.push_back({ x, y });
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        towns.push_back({ x, y });
    }
    cout << fixed << setprecision(15) << dfs(0, -1) << endl;
    return 0;
}