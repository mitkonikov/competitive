#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> P(K);
    for (int i = 0; i < K; i++) cin >> P[i];
    sort(P.begin(), P.end());
    vector<int> win(N + 10);
    win[0] = 0;
    for (int i = 1; i <= N; i++) {
        bool ok = 0;
        for (int k = 0; k < K; k++) {
            if (i-P[k]>=0) ok |= win[i-P[k]] ^ 1;
        }
        if (ok) win[i] = 1;
        cout << (win[i] ? "W" : "L");
    }
    cout << endl;
    return 0;
}