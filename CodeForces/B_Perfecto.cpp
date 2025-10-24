#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    if (N == 1) {
        cout << -1 << endl;
        return;
    }
    vector<int> ans(N);
    ll sum = 0;
    for (int i = 0; i < N; i++) {
        ans[i] = N - i;
        sum += N - i;
    }
    auto sq = (ll)(sqrt(sum));
    if (sq * sq == sum) {
        cout << -1 << endl;
        return;
    }
    ll sum2 = 0;
    auto is_perfect = [](ll n) {
        auto sq = (ll)(sqrt(n));
        return (sq * sq == n);
    };
    for (int i = 0; i < N - 1; i++) {
        if (is_perfect(sum2 + ans[i])) {
            swap(ans[i], ans[i+1]);
        }
        sum2 += ans[i];
        assert(!is_perfect(sum2));
    }
    for (auto el : ans) cout << el << " ";
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;

    while (t--) {
        testCase();
    }

    cout << flush;
    return 0;
}