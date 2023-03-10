#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int INF = 1e9;

inline void umin(int& a, int b) {
    if (b < a) a = b;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }
    vector<int> dp_front(N, INF), dp_back(N, INF);
    dp_front[0] = 0;
    dp_back[N-1] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (S[i][j] == '0') continue;
            int dest = i + j + 1;
            if (dest < N) {
                umin(dp_front[dest], dp_front[i] + 1);
            }
        }
    }
    for (int i = N - 2; i >= 0; i--) {
        for (int j = 0; j < M; j++) {
            if (S[i][j] == '0') continue;
            int dest = i + j + 1;
            if (dest < N) {
                umin(dp_back[i], dp_back[dest] + 1);
            }
        }
    }
    for (int i = 1; i <= N - 2; i++) {
        int ans = INF;
        for (int f = i - 1; f >= max(0, i - 11); f--) {
            for (int j = 0; j < M; j++) {
                if (S[f][j] == '0') continue;
                int dest = f + j + 1;
                if (dest < N && dest > i) {
                    umin(ans, dp_front[f] + dp_back[dest] + 1);
                }
            }
        }
        cout << (ans == INF ? -1 : ans) << " ";
    }
    cout << endl;
    return 0;
}