#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

set<int> f;

void testCase() {
    string N;
    cin >> N;
    vector<int> dp(7, 0);
    dp[0] = 1;
    for (int i = 0; i < N.size(); i++) {
        if (dp[i] == 0) continue;
        for (int sz = 1; sz <= N.size() - i; sz++) {
            int cur = stoi(N.substr(i, sz));
            if (f.count(cur)) {
                dp[i+sz] = max(dp[i+sz], dp[i] + 1);
            }
        }
    }
    cout << (dp[N.size()] > 2 ? "YES" : "NO") << endl;
}

int main() {
    int fib[1000];
    memset(fib, -1, sizeof fib);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; true; i++) {
        fib[i] = fib[i-1] + fib[i-2];
        if (fib[i] > 1e5) break;
    }
    for (int i = 0; i < 1000; i++) {
        if (fib[i] == -1) break;
        f.insert(fib[i]);
    }

    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}