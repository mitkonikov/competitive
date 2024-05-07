#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, K, PB, PS;
    cin >> N >> K >> PB >> PS;
    PB--;
    PS--;
    vector<int> P(N), A(N);
    for (int i = 0; i < N; i++) cin >> P[i];
    for (int i = 0; i < N; i++) cin >> A[i];
    auto stay = [&](ll jumps, ll profit) {
        if (jumps > K) return (ll)0;
        ll rem = max(0LL, K - jumps);
        return rem * profit;
    };
    auto solve = [&](int index) {
        int start = index;
        int jumps = 0;
        ll acc = 0;
        ll ans = acc + stay(jumps, A[start]);
        do {
            acc += A[index];
            index = P[index] - 1;
            jumps++;
            ans = max(ans, acc + stay(jumps, A[index]));
        } while (jumps < K && index != start);
        return ans;
    };
    auto B = solve(PB);
    auto S = solve(PS);
    if (B == S) {
        cout << "Draw" << endl;
        return;
    }
    cout << (B > S ? "Bodya" : "Sasha") << endl;
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