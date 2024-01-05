#include <bits/stdc++.h>
#define ll long long
#define endl '\n'

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> socks(K);
    for (int i = 0; i < K; i++) {
        cin >> socks[i];
    }
    int ans = INT_MAX;
    if ((2 * N - K) % 2 == 1) {
        vector<int> pref(K, 1e9), suff(K, 1e9);
        for (int i = 1; i < K; i += 2) {
            pref[i] = (i-2>=0?pref[i-2]:0) + abs(socks[i] - socks[i-1]);
        }
        for (int i = K - 2; i >= 0; i -= 2) {
            suff[i] = (i+2<K?suff[i+2]:0) + abs(socks[i] - socks[i+1]); 
        }
        auto val = [&](vector<int>& a, int i) {
            return ((i>=0&&i<K) ? a[i] : 0);
        };
        for (int i = 0; i < K; i += 2) {
            int p = min(val(pref, i-1), val(pref, i-2));
            int s = min(val(suff, i+1), val(suff, i+2));
            ans = min(ans, p + s);
        }
    } else {
        ans = 0;
        for (int i = 1; i < K; i += 2) {
            ans += abs(socks[i] - socks[i-1]);
        }
    }
    cout << ans << endl;
    return 0;
}