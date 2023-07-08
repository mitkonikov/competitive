#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int read(int N) {
    string s;
    cin >> s;
    int x = 0;
    for (int i = 0; i < N; i++) if (s[i] == '1') x += (1 << i);
    return x;
}

inline void umin(int& a, int b) {
    if (b < a) a = b;
}

void testCase() {
    int N, M;
    cin >> N >> M;
    int symp = read(N);
    struct Medicine {
        int u, v, d;
    };
    vector<Medicine> med(M);
    for (int i = 0; i < M; i++) {
        int d;
        cin >> d;
        int x1 = read(N), x2 = read(N);
        med[i] = { x1, x2, d };
    }
    const int INF = 1e9;
    vector<int> dp(1 << N, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, symp });
    dp[symp] = 0;
    while (!pq.empty()) {
        auto [dist, me] = pq.top();
        pq.pop();

        if (dp[me] < dist) continue;
        if (me == 0) break;

        for (int i = 0; i < M; i++) {
            int nj = me & (((1<<N)-1)&(~med[i].u)) | med[i].v;
            if (dp[nj] > dp[me] + med[i].d) {
                dp[nj] = dp[me] + med[i].d;
                pq.push({ dp[nj], nj });
            }
        }
    }

    cout << (dp[0] == INF ? -1 : dp[0]) << endl;
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