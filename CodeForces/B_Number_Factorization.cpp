#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

void testCase() {
    int N;
    cin >> N;
    map<int, int> frq;
    for (int i = 2; i * i <= N; i++) {
        while (N % i == 0) {
            frq[i]++;
            N /= i;
        }
    }
    if (N > 1) {
        frq[N]++;
    }
    vector<pair<int, int>> s;
    for (auto el: frq) {
        s.push_back({ el.second, el.first });
    }
    sort(s.begin(), s.end());
    ll ans = 0;
    int M = s.size();
    vector<ll> suff(M + 1, 1);
    for (int i = M - 1; i >= 0; i--) {
        suff[i] = suff[i+1] * s[i].second;
    }
    for (int i = 0; i < M; i++) {
        ll diff = s[i].first - (i-1>=0 ? s[i-1].first : 0);
        ans += diff * suff[i];
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