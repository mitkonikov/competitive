#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    int ans = K / 2 + 1;
    for (int i = 1; i < N; i++) {
        int right = N - i - 1;
        int take = right / 2;
        int kk = max(0, K - take * 2 - 1);
        int lowest = kk / 2 + 1;
        int highest = i / 2 + 1;
        if (lowest == highest && lowest == A[i]) continue;
        if (lowest == highest && K == N && (i % 2 == 0)) continue;
        if (lowest == highest) {
            ans = min(ans, lowest);
        } else {
            if (A[i] == lowest) ans = min(ans, lowest + 1);
            else ans = min(ans, lowest);
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