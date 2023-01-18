#include <bits/stdc++.h>

using namespace std;

inline int closest(int N, int P) {
    return (P < N - P ? P : N - P);
}

template<typename T>
inline void umin(T& a, T b) {
    if (b < a) a = b;
}

long long delivery(int N, int K, int L, int positions[]) {
    #define ll long long
    vector<ll> dp_front(K), dp_back(K);
    ll ans = LLONG_MAX;

    // Consider that we never make a full turn
    for (int i = 0; i < N; i++) {
        dp_back[(N - i) % K] += 2LL * (L - positions[i]);
    }

    for (int i = 0; i <= N; i++) {
        ll current = 0;
        if (i<N) current += dp_back[(N - i) % K];
        if (i-1>=0) current += dp_front[(i - 1) % K];
        umin(ans, current);
        dp_back[(N - i) % K] -= 2LL * (L - positions[i]);
        if (i<N) dp_front[i%K] += 2LL * positions[i];
    }

    // We will take one full turn
    fill(dp_front.begin(), dp_front.end(), 0);
    fill(dp_back.begin(), dp_back.end(), 0);
    
    for (int i = N - 1; i >= K; i--) {
        dp_back[(N - i) % K] += 2LL * (L - positions[i]);
    }

    for (int S = 0; S + K - 1 < N; S++) {
        int E = S + K - 1; // [S, E]
        int back_index = N - E - 1;
        ll cost = dp_back[back_index % K] + L;
        if ((S-1)>=0) cost += dp_front[(S-1)%K];
        umin(ans, cost);
        dp_front[S%K] += 2LL * positions[S];
        dp_back[(back_index)%K] -= 2LL * (L - positions[E+1]);
    }
    return ans;
}

int main() {
    int N, K, L;
    int positions[N];
    cin >> N >> K >> L;
    for (int i = 0; i < N; i++) cin >> positions[i];
    cout << delivery(N, K, L, positions) << endl;
    return 0;
}